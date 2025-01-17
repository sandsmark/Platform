//------------------------------------------------------------------------------
// Copyright (c) 2016 John D. Haughton
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------

#include <fcntl.h>
#include <linux/fb.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <mxcfb.h>

#include <algorithm>

#include "PLT/Frame.h"

namespace PLT {

class Frame::Impl
{
private:
   unsigned width{600};
   unsigned height{800};
   unsigned pitch{300};
   uint8_t* buffer{nullptr};

   size_t getSize() const { return pitch * height; }

   static void error(const char* format, ...)
   {
      va_list ap;

      fprintf(stderr, "ERROR - ");

      va_start(ap, format);
      vfprintf(stderr, format, ap);
      va_end(ap);

      fprintf(stderr, "\n");
      exit(1);
   }

   static int openDev(const char* filename)
   {
      int fd = open(filename, O_RDWR);
      if(-1 == fd)
      {
         error("Failed to open \"%s\"", filename);
      }
      return fd;
   }

public:
   Impl()
   {
      display_fd = openDev("/dev/fb0");

      struct fb_var_screeninfo screeninfo;
      int                      status = ioctl(display_fd, FBIOGET_VSCREENINFO, &screeninfo);
      if(-1 == status)
      {
         error("ioctl(.. FBIOGET_VSCREENINFO) failed");
      }

      width  = screeninfo.xres;
      height = screeninfo.yres;
      pitch  = (width + 1)/2;

      buffer = (uint8_t*)mmap(nullptr, getSize(), PROT_READ | PROT_WRITE, MAP_SHARED, display_fd, 0);
      if(nullptr == buffer)
      {
         error("mmap() failed");
      }
   }

   ~Impl()
   {
      munmap(buffer, getSize());
      close(display_fd);
   }

   unsigned getWidth() const { return width; }

   unsigned getHeight() const { return height; }

   uint8_t* getStorage(unsigned& pitch_) const
   {
      pitch_ = pitch;
      return buffer;
   }

   void refresh() const
   {
       mxcfb_update_data data;
       data.update_region.left = 0;
       data.update_region.top = 0;
       data.update_region.width = width;
       data.update_region.height = height;
       data.temp = TEMP_USE_AMBIENT;
       data.update_marker = 0;
       data.update_mode = UPDATE_MODE_PARTIAL;
       data.flags = 0;
       data.waveform_mode = 6; // A2, fast mono
       ioctl(display_fd, MXCFB_SEND_UPDATE, &data);
   }
};


Frame::Frame(const char* /* title */, unsigned width_, unsigned height_, uint32_t /* flags */)
{
   pimpl  = new Impl();
   buffer = pimpl->getStorage(pitch);

   resize(width_, height_);
}

Frame::~Frame() { delete pimpl; }

void Frame::resize(unsigned width_, unsigned height_)
{
   width  = std::min(width_,  pimpl->getWidth());
   height = std::min(height_, pimpl->getHeight());
}

void Frame::refresh() { pimpl->refresh(); }

// Some stubs for unimplemented functionality

void* Frame::getHandle() const { return nullptr; }

uint32_t Frame::getId() const { return 0; }

void Frame::setTitle(const char* title_) {}

void Frame::setVisible(bool visible_) {}

void Frame::setScanner(Scanner* scanner_) {}

} // namespace PLT
