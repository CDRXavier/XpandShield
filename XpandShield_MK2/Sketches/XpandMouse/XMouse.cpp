/*
  Mouse.cpp

  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "XMouse.h"

#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  
  //  Mouse
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 54
    0x09, 0x02,                    // USAGE (Mouse)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x85, 0x01,                    //     REPORT_ID (1)
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
    0x29, 0x03,                    //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x95, 0x03,                    //     REPORT_COUNT (3)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x95, 0x01,                    //     REPORT_COUNT (1)
    0x75, 0x05,                    //     REPORT_SIZE (5)
    0x81, 0x03,                    //     INPUT (Cnst,Var,Abs)
    0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x09, 0x38,                    //     USAGE (AB Wheel)
    0x0a, 0x38, 0x02,              //     USAGE (AC pan)
    0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x04,                    //     REPORT_COUNT (4)
    0x81, 0x06,                    //     INPUT (Data,Var,Rel)
    
    //0x05, 0x0c,                    //     USAGE_PAGE (Consumer Devices)
    //0x0a, 0x38, 0x02,              //     USAGE (AC pan)
    //0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
    //0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
    //0x75, 0x08,                    //     REPORT_SIZE (8)
    //0x95, 0x01,                    //     REPORT_COUNT (1)
    //0x81, 0x06,                    //     INPUT (Data,Var,Rel)
    0xc0,                          //   END_COLLECTION
    0xc0,                          // END_COLLECTION
};

//================================================================================
//================================================================================
//	Mouse

XMouse::XMouse(void) : _buttons(0)
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    HID().AppendDescriptor(&node);
}

void XMouse::begin(void) 
{
}

void XMouse::end(void) 
{
}

void XMouse::move(signed char x, signed char y)
{
	discr[1] = x;
	discr[2] = y;
}

void XMouse::scroll (signed char wheel, signed char wheelee)
{
	discr[3] = wheel;
	discr[4] = wheelee;
}

void XMouse::press(uint8_t b) 
{
	_buttons = _buttons | b;
}

void XMouse::release(uint8_t b)
{
	_buttons = _buttons & ~b;
}

bool XMouse::isPressed(uint8_t b)
{
	if ((b & _buttons) > 0) 
		return true;
	return false;
}
void XMouse::update(void)
{
	discr[0] = _buttons;
	HID().SendReport(1,discr,5);
  discr[0] = 0;
  discr[1] = 0;
  discr[2] = 0;
  discr[3] = 0;
  discr[4] = 0;
}

#endif
