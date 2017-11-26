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

#include "SDL_headers.h"

#include "PLT/Image.h"

namespace PLT {

unsigned Image::getPixelBits() { return 32; }

uint32_t Image::getPixel(unsigned x, unsigned y) const
{
   uint32_t* pixels = reinterpret_cast<uint32_t*>(buffer);
   return pixels[x + y * pitch / 4];
}

void Image::setPixel(unsigned x, unsigned y, uint32_t rgb)
{
   uint32_t* pixels = reinterpret_cast<uint32_t*>(buffer);
#ifdef PROJ_TARGET_Emscripten
   pixels[x + y * pitch / 4] = 0xFF000000 | rgb;
#else
   pixels[x + y * pitch / 4] = rgb;
#endif
}

void Image::span(unsigned x1, unsigned y, unsigned x2, uint32_t rgb)
{
   defaultSpan(x1, y, x2, rgb);
}

void Image::blit(unsigned x, unsigned y, unsigned src_offset, unsigned src_width,
                 const Image& source)
{
   SDL_Surface* src = static_cast<SDL_Surface*>(source.getHandle());

   SDL_Rect srcrect;
   SDL_Rect dstrect;

   srcrect.x = src_offset;
   srcrect.y = 0;
   srcrect.w = src_width;
   srcrect.h = src->h;

   dstrect.x = x;
   dstrect.y = y;
   dstrect.w = src_width;
   dstrect.h = src->h;

   if(src_width == 0)
   {
      srcrect.w = src->w;
      dstrect.w = src->w;
   }

   SDL_BlitSurface(src, &srcrect, static_cast<SDL_Surface*>(getHandle()), &dstrect);
}

} // namespace PLT
