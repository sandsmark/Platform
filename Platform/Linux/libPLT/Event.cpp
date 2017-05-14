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

#include <stdint.h>

#include "SDL2/SDL.h"

#include "PLT/Event.h"


namespace PLT {

static uint8_t translate_key(SDL_Keycode key)
{
   switch(key)
   {
   case SDLK_RSHIFT:    return RSHIFT;
   case SDLK_LSHIFT:    return LSHIFT;
   case SDLK_LCTRL:     return LCTRL;
   case SDLK_RALT:      return RALT;
   case SDLK_LALT:      return LALT;
   case SDLK_F1:        return F1;
   case SDLK_F2:        return F2;
   case SDLK_F3:        return F3;
   case SDLK_F4:        return F4;
   case SDLK_F5:        return F5;
   case SDLK_F6:        return F6;
   case SDLK_F7:        return F7;
   case SDLK_F8:        return F8;
   case SDLK_F9:        return F9;
   case SDLK_F10:       return F10;
   case SDLK_F11:       return F11;
   case SDLK_F12:       return F12;
   case SDLK_CAPSLOCK:  return CAPSLOCK;
   case SDLK_UP:        return UP;
   case SDLK_DOWN:      return DOWN;
   case SDLK_RIGHT:     return RIGHT;
   case SDLK_LEFT:      return LEFT;
   case SDLK_BACKSPACE: return BACKSPACE;
   case SDLK_RETURN:    return RETURN;
   case 0xA7:           return '`';
   default:             return key;
   }
}

static EventType getEvent(Event& event, bool wait)
{
   event.type = NONE;
   event.code = 0;
   event.x    = 0;
   event.y    = 0;

   SDL_Event  sdl_event;

   if (wait ? SDL_WaitEvent(&sdl_event)
            : SDL_PollEvent(&sdl_event))
   {
      switch(sdl_event.type)
      {
      case SDL_QUIT:
         event.type = QUIT;
         break;

      case SDL_WINDOWEVENT:
         event.code = sdl_event.window.windowID;
         switch(sdl_event.window.event)
         {
         case SDL_WINDOWEVENT_CLOSE:
            event.type = QUIT;
            break;

         case SDL_WINDOWEVENT_RESIZED:
            event.type = RESIZE;
            event.x    = sdl_event.window.data1;
            event.y    = sdl_event.window.data2;
            break;

         default:
            break;
         }
         break;

      case SDL_KEYDOWN:
         event.type = KEY_DOWN;
         event.code = translate_key(sdl_event.key.keysym.sym);
         break;

      case SDL_KEYUP:
         event.type = KEY_UP;
         event.code = translate_key(sdl_event.key.keysym.sym);
         break;

      case SDL_MOUSEMOTION:
         event.type = POINTER_MOVE;
         event.x    = sdl_event.motion.x;
         event.y    = sdl_event.motion.y;
         break;

      case SDL_MOUSEBUTTONDOWN:
      case SDL_MOUSEBUTTONUP:
         event.type = sdl_event.button.type == SDL_MOUSEBUTTONUP ? BUTTON_UP
                                                                 : BUTTON_DOWN;
         switch(sdl_event.button.button)
         {
         case SDL_BUTTON_LEFT:  event.code = uint8_t(Button::LEFT);  break;
         case SDL_BUTTON_RIGHT: event.code = uint8_t(Button::RIGHT); break;
         }
         event.x = sdl_event.button.x;
         event.y = sdl_event.button.y;
         break;

      case SDL_USEREVENT:
         event.type = TIMER;
         break;

      default:
         break;
      }
   }

   return EventType(event.type);
}


EventType pollEvent(Event& event)
{
   return getEvent(event, false);
}

EventType waitEvent(Event& event)
{
   return getEvent(event, true);
}


static Uint32 timer_callback(Uint32 period_ms, void* param)
{
   SDL_Event       event;
   SDL_UserEvent   user_event;

   user_event.type  = SDL_USEREVENT;
   user_event.code  = 0;
   user_event.data1 = 0;
   user_event.data2 = 0;

   event.type = SDL_USEREVENT;
   event.user = user_event;

   SDL_PushEvent(&event);

   return period_ms;
}


void setTimer(unsigned period_ms)
{
   static SDL_TimerID id = 0;

   if (id != 0)
   {
      SDL_RemoveTimer(id);
   }

   if (period_ms != 0)
   {
      id = SDL_AddTimer(period_ms, timer_callback, 0);
   }
}


} // PLT