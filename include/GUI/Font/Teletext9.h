//------------------------------------------------------------------------------
// The font data in this file is a derivative of font data reverse engineered
// from bitmap images published in the data sheet for the Mullard SAA5050
// "Teletext Character Generator" (dated July 1982). That publicly available
// document does not contain a copyright notice or any mention of permissions
// or restrictions that apply to the use of the data. However, according to law
// that does not necessarily mean that the data is free from restrictions on its
// use. At the time of publication, the copyright holder for the font data may
// have been Mullard or may have been the designers of the original teletext
// system, the British Broadcasting Corporation. If the actual copyright holder
// becomes apparent and wishes to retrospectively declare reasonable and legal
// restrictions on the data, then either those restrictions must be obeyed or
// this data file shouled be deleted.
//
// The statements above shall be included in all copies or substantial portions
// of the data.
//
// THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE
// DATA.
//------------------------------------------------------------------------------

// Adapted from, but not identical to, the font published in pixel detail in the
// SAA5050 datasheet.

#ifndef GUI_FONT_TELETEXT_9_H
#define GUI_FONT_TELETEXT_9_H

#include "GUI/Font.h"

namespace GUI {

static const uint8_t font_teletext9_data[] =
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20,
   0x00, 0x00, 0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x50, 0x50, 0xF8, 0x50, 0xF8,
   0x50, 0x50, 0x00, 0x00, 0x70, 0xA8, 0xA0, 0x73, 0x28, 0xA8, 0x70, 0x00, 0x00, 0xC0, 0xC8, 0x13,
   0x20, 0x40, 0x98, 0x18, 0x00, 0x00, 0x40, 0xA0, 0xA0, 0x40, 0xA8, 0x90, 0x68, 0x00, 0x00, 0x20,
   0x21, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x40, 0x40, 0x40, 0x20, 0x10, 0x00,
   0x00, 0x40, 0x20, 0x10, 0x10, 0x10, 0x20, 0x40, 0x00, 0x00, 0x20, 0xA8, 0x70, 0x20, 0x70, 0xA8,
   0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
   0x20, 0x50, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00, 0x00, 0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70,
   0x00, 0x00, 0x70, 0x88, 0x08, 0x30, 0x40, 0x80, 0xF8, 0x00, 0x00, 0xF8, 0x08, 0x10, 0x30, 0x08,
   0x88, 0x70, 0x00, 0x00, 0x10, 0x30, 0x50, 0x90, 0xF8, 0x10, 0x10, 0x00, 0x00, 0xF8, 0x80, 0xF0,
   0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x30, 0x40, 0x80, 0xF0, 0x88, 0x88, 0x70, 0x00, 0x00, 0xF8,
   0x08, 0x10, 0x20, 0x40, 0x40, 0x40, 0x00, 0x00, 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00,
   0x00, 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0x63, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x03,
   0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x20, 0x20, 0x40, 0x00, 0x10, 0x20, 0x40, 0x80,
   0x41, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20,
   0x10, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00, 0x70, 0x88, 0x10, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00,
   0x70, 0x88, 0xB8, 0xA8, 0xB8, 0x80, 0x70, 0x00, 0x01, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88,
   0x02, 0x00, 0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, 0x00, 0x00, 0x70, 0x88, 0x80, 0x80, 0x80,
   0x88, 0x70, 0x00, 0x00, 0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0, 0x00, 0x00, 0xF8, 0x80, 0x80,
   0xF0, 0x80, 0x80, 0xF8, 0x00, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x70,
   0x88, 0x80, 0x80, 0x98, 0x88, 0x78, 0x00, 0x00, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x00,
   0x00, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x88,
   0x70, 0x00, 0x00, 0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
   0x80, 0x80, 0xF8, 0x00, 0x00, 0x88, 0xD8, 0xA8, 0xA8, 0x88, 0x88, 0x88, 0x00, 0x00, 0x88, 0x88,
   0xC8, 0xA8, 0x98, 0x88, 0x88, 0x00, 0x00, 0x73, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x03,
   0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0xA8, 0x90, 0x68,
   0x01, 0x00, 0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00, 0x00, 0x70, 0x88, 0x80, 0x70, 0x08,
   0x88, 0x70, 0x00, 0x00, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x88, 0x88, 0x88,
   0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x00, 0x00, 0x88,
   0x88, 0x88, 0xA8, 0xA8, 0xA8, 0x50, 0x00, 0x00, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00,
   0x00, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0xF8, 0x08, 0x10, 0x20, 0x40, 0x80,
   0xF8, 0x00, 0x00, 0x70, 0x40, 0x40, 0x40, 0x40, 0x40, 0x70, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
   0x10, 0x08, 0x00, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00, 0x00, 0x00, 0x20,
   0x50, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
   0x40, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78,
   0x00, 0x00, 0x80, 0x80, 0xF0, 0x88, 0x88, 0x88, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x78, 0x80, 0x80,
   0x80, 0x78, 0x00, 0x00, 0x08, 0x08, 0x78, 0x8B, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00, 0x00, 0x73,
   0x88, 0xF8, 0x80, 0x70, 0x00, 0x00, 0x10, 0x20, 0x20, 0x70, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
   0x01, 0x78, 0x88, 0x88, 0x88, 0x78, 0x08, 0x70, 0x80, 0x80, 0xF0, 0x88, 0x88, 0x88, 0x88, 0x00,
   0x00, 0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x20, 0x00, 0x20, 0x20, 0x20, 0x20,
   0x20, 0x20, 0x40, 0x40, 0x40, 0x48, 0x50, 0x60, 0x50, 0x48, 0x00, 0x00, 0x60, 0x20, 0x20, 0x20,
   0x20, 0x20, 0x70, 0x00, 0x00, 0x00, 0x00, 0xD0, 0xA8, 0xA8, 0xA8, 0xA8, 0x00, 0x00, 0x00, 0x00,
   0xF0, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
   0x00, 0x00, 0xF0, 0x88, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x00, 0x00, 0x78, 0x88, 0x88, 0x88, 0x78,
   0x08, 0x08, 0x00, 0x00, 0x58, 0x60, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x78, 0x80, 0x70,
   0x08, 0xF0, 0x00, 0x00, 0x20, 0x20, 0x70, 0x20, 0x20, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x88,
   0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x50, 0x50, 0x20, 0x00, 0x00, 0x00,
   0x00, 0x88, 0x88, 0xA8, 0xA8, 0x50, 0x00, 0x00, 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00,
   0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x7B, 0x08, 0x70, 0x00, 0x00, 0xF8, 0x10, 0x20, 0x43,
   0xF8, 0x00, 0x00, 0x10, 0x20, 0x20, 0x60, 0x20, 0x20, 0x10, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20,
   0x21, 0x20, 0x20, 0x00, 0x00, 0x40, 0x20, 0x20, 0x30, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00,
   0x40, 0xA8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x20, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x02, 0x1C, 0x1E, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0,
   0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xFC,
   0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x00, 0x00,
   0x00, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
   0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
   0xFC, 0xFC, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x1C, 0x1C,
   0x1C, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x03,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0,
   0xE1, 0xE0, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0x00, 0x00,
   0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
   0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFC,
   0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0,
   0xE0, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
   0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xFC,
   0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C,
   0x1C, 0xFC, 0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xE0, 0xE0, 0xE0,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x1C,
   0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0x00, 0x00,
   0x00, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0xE3, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE3,
   0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0xFC,
   0xFD, 0xFC, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
   0x1C, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
   0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0xFC,
   0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
   0x1C, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xFC,
   0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00,
   0x00, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xE0, 0xE0, 0xE0,
   0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xFC,
   0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0xFC, 0xFC,
   0xFC, 0xE0, 0xE0, 0xE0, 0x1C, 0x1C, 0x1C, 0xFF, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1F,
   0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFC,
   0xFD, 0xFC, 0xFC, 0xFC, 0xFC, 0xE0, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C,
   0x1C, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x02, 0x00, 0x0E, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x6C, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60,
   0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
   0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00,
   0x00, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C,
   0x00, 0x00, 0x00, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x0C,
   0x0C, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x03, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x03,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
   0x61, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x00,
   0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60,
   0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00,
   0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x60,
   0x60, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C,
   0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
   0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x0C,
   0x0C, 0x00, 0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x60, 0x60,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
   0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x6C, 0x6C, 0x00, 0x00,
   0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x03, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x63,
   0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00,
   0x6D, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0C,
   0x0C, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C,
   0x00, 0x0C, 0x0C, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0E, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00,
   0x6F, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x0C,
   0x0D, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x6E, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
   0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x00,
   0x00, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x60, 0x60,
   0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00,
   0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x6C,
   0x6C, 0x00, 0x60, 0x60, 0x00, 0x0C, 0x0C, 0x03, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0F,
   0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x0C, 0x0C, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00,
   0x6D, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x60, 0x60, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x0C,
   0x0C, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C, 0x00, 0x6C, 0x6C
};

static const Font font_teletext9 =
{
   { 6, 9 }, 0x20, 0xFF, 1, font_teletext9_data
};

}

#endif
