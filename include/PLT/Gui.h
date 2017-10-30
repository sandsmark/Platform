//------------------------------------------------------------------------------
// Copyright (c) 2015 John D. Haughton
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

#ifndef PLT_GUI_H
#define PLT_GUI_H

#include "PLT/Event.h"
#include "PLT/Frame.h"

#include "GUI/GUI.h"

namespace PLT {

class Gui : public GUI::Window
{
private:
   PLT::Frame frame;

   // Implement GUI::Canvas

   virtual GUI::Colour canvasGetPixel(signed x, signed y) const override
   {
      return frame.getPixel(x, y);
   }

   virtual void canvasResize(unsigned width, unsigned height) override
   {
      frame.resize(width, height);
   }

   virtual void canvasRefresh(signed x1, signed y1, signed x2, signed y2) override
   {
      frame.refresh();
   }

   virtual void canvasPoint(GUI::Colour colour, signed x, signed y) override
   {
      frame.setPixel(x, y, colour);
   }

   virtual void canvasSpan(GUI::Colour colour, signed x1, signed y, signed x2) override
   {
      for(signed x = x1; x < x2; x++)
      {
         frame.setPixel(x, y, colour);
      }
   }

   // -------------------

   static uint32_t guiFlagsToFrameFlags(uint32_t gui_flags)
   {
      uint32_t frame_flags = 0;
      if(gui_flags & GUI::RESIZABLE)   frame_flags |= Frame::RESIZABLE;
      if(gui_flags & GUI::NO_BORDER)   frame_flags |= Frame::NO_BORDER;
      if(gui_flags & GUI::FULL_SCREEN) frame_flags |= Frame::FULL_SCREEN;
      return frame_flags;
   }

   void handleEvent(const Event::Message& event)
   {
      switch(event.type)
      {
      case PLT::Event::RESIZE:       winResize(event.x, event.y); break;
      case PLT::Event::KEY_DOWN:     keyPress(event.code, true ); break;
      case PLT::Event::KEY_UP:       keyPress(event.code, false); break;
      case PLT::Event::POINTER_MOVE: ptrMove(event.x, event.y); break;
      case PLT::Event::BUTTON_DOWN:  btnPress(event.x, event.y, event.code == 1, true);  break;
      case PLT::Event::BUTTON_UP:    btnPress(event.x, event.y, event.code == 1, false); break;
      case PLT::Event::TIMER:        timerEvent(); break;

      case PLT::Event::QUIT:
      default:
         break;
      }
   }

   static void eventCallBack(const Event::Message& event, void* ptr)
   {
      Gui* gui = reinterpret_cast<Gui*>(ptr);
      gui->handleEvent(event);
   }

public:
   Gui(const char* title_, const GUI::Font* font_, uint32_t flags_ = 0)
      : GUI::Window(font_)
      , frame(title_, 0, 0, guiFlagsToFrameFlags(flags_))
   {
   }

   Gui(const char* title_, unsigned width_, unsigned height_, uint32_t flags_ = 0)
      : GUI::Window()
      , frame(title_, width_, height_, guiFlagsToFrameFlags(flags_))
   {
      setSize(width_, height_);
   }

   int eventLoop()
   {
      show();

      return PLT::Event::eventLoop(eventCallBack, this);
   }

   void setTimer(unsigned code, unsigned period_ms)
   {
      setTimerEvent(code);
      PLT::Event::setTimer(period_ms);
   }
};

} // namespace PLT

#endif
