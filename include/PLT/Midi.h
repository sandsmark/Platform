//------------------------------------------------------------------------------
// Copyright (c) 2017 John D. Haughton
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

#ifndef PLT_MIDI_H
#define PLT_MIDI_H

#include <cstdint>

namespace PLT {

namespace MIDI {


static const uint8_t  NOTE_OFF          = 0x80;
static const uint8_t  NOTE_ON           = 0x90;
static const uint8_t  POLY_KEY_PRESSURE = 0xA0;
static const uint8_t  CONTROL_CHANGE    = 0xB0;
static const uint8_t  PROGRAM_CHANGE    = 0xC0;
static const uint8_t  CHANNEL_PRESSURE  = 0xD0;
static const uint8_t  PITCH_BEND        = 0xE0;
static const uint8_t  SYSEX             = 0xF0;


//! MIDI input stream
class In
{
public:
   In(unsigned device_index = 0);
   ~In();

   bool isConnected() const { return connected; }

   virtual void messageIn(unsigned length, uint8_t* data) = 0;

private:
   bool connected{false};
};


//! MIDI output stream
class Out
{
public:
   Out(unsigned device_index = 0);
   ~Out();

   bool isConnected() const { return connected; }

   void messageOut(unsigned length, const uint8_t* data);

private:
   bool connected{false};
};


} // namespace MIDI

} // namespace PLT

#endif