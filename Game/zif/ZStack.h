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

#ifndef ZSTACK_H
#define ZSTACK_H

#include <cassert>
#include <stdint.h>

//! Stack for ZMachine
template <unsigned SIZE>
class ZStack
{
private:
   uint16_t  elem[SIZE];
   uint16_t  sp;
   uint16_t  fp;

   bool empty() const { return sp == fp;   }
   bool full()  const { return sp == SIZE; }

public:
   ZStack()
   {
      init();
   }

   void init()
   {
      sp = fp = 0;
   }

   uint16_t framePtr() const { return fp; }

   void push(uint16_t value)
   {
      assert(!full());
      elem[sp++] = value;
      //tprintf("\npush %5u => stack[%u]", value, sp - 1);
   }

   void push(uint32_t value)
   {
      push(uint16_t(value));
      push(uint16_t(value >> 16));
   }

   void pushFrame(uint16_t num_arg)
   {
      push(fp);
      fp = sp;
      push(num_arg);
   }

   uint16_t& peek()
   {
      assert(!empty());
      return elem[sp - 1];
   }

   uint16_t pop()
   {
      assert(!empty());
      //tprintf("\npop stack[%u] => %u", sp - 1, elem[sp-1]);
      return elem[--sp];
   }

   void pop(uint16_t& value)
   {
      value = pop();
   }

   void pop(uint32_t& value)
   {
      value =  pop()<<16;
      value |= pop();
   }

   void popFrame()
   {
      sp = fp;
      assert(sp != 0);
      fp = elem[--sp];
   }

   uint16_t frameArgs() const
   {
      return elem[fp];
   }

   uint16_t& frame(unsigned index)
   {
      assert(index <= 14);
      unsigned ptr = fp + 1 + index;
      assert(ptr < sp);
      return elem[ptr];
   }
};

#endif
