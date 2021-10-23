//  XpandMouse (standard edition)
//  Copyright (C) 2021 CDR_Xavier
//  All rights reserved.
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Public License as published by
//  the Free Software Foundation; either version 2.1 of the License,
//  or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//
//  the mouse library is horribly written. However, I am not the one that write it.
//  So, in the current state, it does not support horizontal scrolling or zooming.
//  That in particular, might be expanded upon.
//  there is also a hitch to it where the USB code is written so it will always
//  appear to a device as a virtual COM port, with a mouse or whatever attached to it.
//  This also mean that the device will always be name "Arduino Leonardo/Micro" and
//  driver will be always "Arduino LLC" as well as some others.

#include <XpandShield2.h>
#include "XMouse.h"



int16_t sti0;
int16_t sti0_min;
int16_t sti0_mid;
int16_t sti0_max;
int16_t sti1;
int16_t sti1_min;
int16_t sti1_mid;
int16_t sti1_max;
int16_t sti2;
int16_t sti2_min;
int16_t sti2_mid;
int16_t sti2_max;
int16_t sti3;
int16_t sti3_min;
int16_t sti3_mid;
int16_t sti3_max;
int16_t sti4;
int16_t sti5;


#define STK00 ((sti0>sti0_mid)? (((sti0-sti0_mid) * 32) / (sti0_max-sti0_mid)) : (((sti0-sti0_mid) * 32) / (sti0_mid-sti0_min)))
#define STK10 ((sti1>sti1_mid)? (((sti1-sti1_mid) * 32) / (sti1_max-sti1_mid)) : (((sti1-sti1_mid) * 32) / (sti1_mid-sti1_min)))
#define STK20 ((sti2>sti2_mid)? (((sti2-sti2_mid) * 32) / (sti2_max-sti2_mid)) : (((sti2-sti2_mid) * 32) / (sti2_mid-sti2_min)))
#define STK30 ((sti3>sti3_mid)? (((sti3-sti3_mid) * 32) / (sti3_max-sti3_mid)) : (((sti3-sti3_mid) * 32) / (sti3_mid-sti3_min)))



int8_t dirX;
int8_t dirY;

bool repeat;
bool repeatL;
bool repeatR;


bool scramble;
int8_t moveFrame;
bool stallFrame;

XMouse mouse;

void fillCircle
(int16_t x0, int16_t y0, uint8_t r, uint8_t color)
{
  XpandShield2::drawVLine(x0, y0 - r, 2 * r + 1, color);

  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  while (x < y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }

    x++;
    ddF_x += 2;
    f += ddF_x;

    if (3 & 0x1) {// right side
      XpandShield2::drawVLine(x0 + x, y0 - y, 2 * y + 1, color);
      XpandShield2::drawVLine(x0 + y, y0 - x, 2 * x + 1, color);
    }

    if (3 & 0x2) {// left side

      XpandShield2::drawVLine(x0 - x, y0 - y, 2 * y + 1, color);
      XpandShield2::drawVLine(x0 - y, y0 - x, 2 * x + 1, color);
    }
  }
}




void setup() {
  // put your setup code here, to run once:
  XpandShield2::Startup();
  XpandShield2::setFrameDiff(20);
  //Mouse.begin();




  dirX = 0;
  dirY = 0;
  repeat = false;
  repeatL = false;
  repeatR = false;
  scramble = false;
  moveFrame = 0;
  stallFrame = false;

  sti0_mid = analogRead(A0);
  sti1_mid = analogRead(A1);
  sti2_mid = analogRead(A2);
  sti3_mid = analogRead(A3);

  sti0_min = sti0_mid;
  sti0_max = sti0_mid;
  sti1_min = sti1_mid;
  sti1_max = sti1_mid;
  sti2_min = sti2_mid;
  sti2_max = sti2_mid;
  sti3_min = sti3_mid;
  sti3_max = sti3_mid;
}


void loop() {
  // put your main code here, to run repeatedly:
  if (XpandShield2::nextFrame()) {

    sti0 = analogRead(A0);
    sti1 = analogRead(A1);
    sti2 = analogRead(A2);
    sti3 = analogRead(A3);
    sti4 = analogRead(A4);
    sti5 = analogRead(A5);

    if (sti0 < sti0_min)
      sti0_min = sti0;
    if (sti1 < sti1_min)
      sti1_min = sti1;
    if (sti2 < sti2_min)
      sti2_min = sti2;
    if (sti3 < sti3_min)
      sti3_min = sti3;

    if (sti0 > sti0_max)
      sti0_max = sti0;
    if (sti1 > sti1_max)
      sti1_max = sti1;
    if (sti2 > sti2_max)
      sti2_max = sti2;
    if (sti3 > sti3_max)
      sti3_max = sti3;

    XpandShield2::pollButtons();

    XpandShield2::clearDisplay();

    //XpandShield2::drawCircle(24, 50, 14, XpandShield2::WHITE);
    XpandShield2::drawRect(8, 4, 34, 34, XpandShield2::WHITE);
    XpandShield2::drawRect(57, 1, 65, 6, XpandShield2::WHITE);
    XpandShield2::drawRect(57, 9, 65, 6, XpandShield2::WHITE);
    XpandShield2::drawRect(57, 18, 65, 6, XpandShield2::WHITE);
    XpandShield2::drawRect(57, 25, 65, 6, XpandShield2::WHITE);
    XpandShield2::drawRect(57, 33, 65, 6, XpandShield2::WHITE);


    XpandShield2::drawVLine(24, 40, 5, XpandShield2::WHITE);
    XpandShield2::drawVLine(24, 58, 5, XpandShield2::WHITE);
    XpandShield2::drawHLine(13, 51, 5, XpandShield2::WHITE);
    XpandShield2::drawHLine(31, 51, 5, XpandShield2::WHITE);



    dirX = 0;
    dirY = 0;
    if (XpandShield2::pressed(XpandShield2::UP_BUTTON)) {
      XpandShield2::drawRect(23, 40, 3, 5, XpandShield2::WHITE);
      dirY = dirY - 1;
    }
    if (XpandShield2::pressed(XpandShield2::DOWN_BUTTON)) {
      XpandShield2::drawRect(23, 58, 3, 5, XpandShield2::WHITE);
      dirY = dirY + 1;
    }
    if (XpandShield2::pressed(XpandShield2::LEFT_BUTTON)) {
      XpandShield2::drawRect(13, 50, 5, 3, XpandShield2::WHITE);
      dirX = dirX - 1;
    }
    if (XpandShield2::pressed(XpandShield2::RIGHT_BUTTON)) {
      XpandShield2::drawRect(31, 50, 5, 3, XpandShield2::WHITE);
      dirX = dirX + 1;
    }
    if (dirX > 0)
      mouse.scroll(0, -1);
    if (dirX < 0)
      mouse.scroll(0, 1);
    if (dirY > 0)
      mouse.scroll(-1, 0);
    if (dirY < 0)
      mouse.scroll(1, 0);
    XpandShield2::drawCircle(61, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(69, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(77, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(85, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(93, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(101, 43, 2, XpandShield2::WHITE);


    if (XpandShield2::pressed(XpandShield2::A_BUTTON)) {
      fillCircle(61, 43, 2, XpandShield2::WHITE);
      mouse.press(MOUSE_LEFT);
    }
    else
      mouse.release(MOUSE_LEFT);

    if (XpandShield2::pressed(XpandShield2::B_BUTTON)) {
      fillCircle(69, 43, 2, XpandShield2::WHITE);
      mouse.press(MOUSE_RIGHT);
    }
    else
      mouse.release(MOUSE_RIGHT);

    if (XpandShield2::pressed(XpandShield2::C_BUTTON)) {
      fillCircle(77, 43, 2, XpandShield2::WHITE);
      mouse.press(MOUSE_MIDDLE);
    }

    else
      mouse.release(MOUSE_MIDDLE);

    if (XpandShield2::pressed(XpandShield2::X_BUTTON))
      fillCircle(85, 43, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::Y_BUTTON))
      fillCircle(93, 43, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::Z_BUTTON))
      fillCircle(101, 43, 2, XpandShield2::WHITE);


    if (XpandShield2::justPressed(XpandShield2::START_BUTTON))
      repeat = !repeat;
    if (XpandShield2::justPressed(XpandShield2::SELECT_BUTTON))
      scramble = !scramble;


    XpandShield2::drawCircle(109, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(117, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(61, 51, 2, XpandShield2::WHITE);


    if (scramble)
      XpandShield2::drawRect(67, 58, 5, 5, XpandShield2::WHITE);


    if (XpandShield2::pressed(XpandShield2::START_BUTTON))
      fillCircle(109, 43, 2, XpandShield2::WHITE);

    if (repeat) { //repeat
      XpandShield2::drawRect(59, 58, 5, 5, XpandShield2::WHITE);
      if (XpandShield2::justPressed(XpandShield2::START_BUTTON))
        repeatL = !repeatL;
    } else
      repeatL = false;
    if (XpandShield2::pressed(XpandShield2::SELECT_BUTTON))
      fillCircle(117, 43, 2, XpandShield2::WHITE);


    if (XpandShield2::pressed(XpandShield2::MENU_BUTTON))
      fillCircle(61, 51, 2, XpandShield2::WHITE);


    if (repeat) {
      if (repeatL) {
        XpandShield2::drawCircle(109, 59, 2, XpandShield2::WHITE);
        if (repeatR) {
          repeatR = false;
          XpandShield2::fillRect(108, 58, 3, 3, XpandShield2::WHITE);
          mouse.press(MOUSE_LEFT);
        }
        else {
          repeatR = true;
          mouse.release(MOUSE_LEFT);
        }
      } else if (mouse.isPressed(MOUSE_LEFT))
        mouse.release(MOUSE_LEFT);
    }
    XpandShield2::drawCircle(69, 51, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(77, 51, 2, XpandShield2::WHITE);


    if (XpandShield2::pressed(XpandShield2::L2_BUTTON))
      fillCircle(69, 51, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::R2_BUTTON))
      fillCircle(77, 51, 2, XpandShield2::WHITE);


    XpandShield2::drawCircle(85, 51, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(93, 51, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(101, 51, 2, XpandShield2::WHITE);


    if (XpandShield2::pressed(XpandShield2::C1_BUTTON))
      fillCircle(85, 51, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::C2_BUTTON))
      fillCircle(93, 51, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::STK_S_BUTTON)) {
      fillCircle(101, 51, 2, XpandShield2::WHITE);
    }

    if (XpandShield2::pressed(XpandShield2::L1_BUTTON)) {
      XpandShield2::fillRect(58, 1, 32, 6, XpandShield2::WHITE);
      //++sho;
    }
    if (XpandShield2::pressed(XpandShield2::R1_BUTTON)) {
      XpandShield2::fillRect(91, 1, 32, 6, XpandShield2::WHITE);
      //--sho;
    }

    XpandShield2::drawVLine(24, 45, 5, XpandShield2::WHITE);
    XpandShield2::drawVLine(24, 53, 5, XpandShield2::WHITE);
    XpandShield2::drawHLine(18, 51, 5, XpandShield2::WHITE);
    XpandShield2::drawHLine(26, 51, 5, XpandShield2::WHITE);


    if (XpandShield2::pressed(XpandShield2::STK_U_BUTTON)) {
      XpandShield2::drawRect(23, 45, 3, 5, XpandShield2::WHITE);
      //--stkY;
    }
    if (XpandShield2::pressed(XpandShield2::STK_D_BUTTON)) {
      XpandShield2::drawRect(23, 53, 3, 5, XpandShield2::WHITE);
      //++stkY;
    }
    if (XpandShield2::pressed(XpandShield2::STK_L_BUTTON)) {
      XpandShield2::drawRect(18, 50, 5, 3, XpandShield2::WHITE);
      //--stkX;
    }
    if (XpandShield2::pressed(XpandShield2::STK_R_BUTTON)) {
      XpandShield2::drawRect(26, 50, 5, 3, XpandShield2::WHITE);
      //++stkX;
    }
    XpandShield2::drawVLine(8 + 16 + (STK20 >> 1), 5, 32, XpandShield2::WHITE);
    XpandShield2::drawHLine(9, 4 + 16 + (STK00 >> 1), 32, XpandShield2::WHITE);

    XpandShield2::fillRect(58, 10, 32 + STK10, 4, XpandShield2::WHITE);

    XpandShield2::fillRect(58, 19, 32 + STK30, 4, XpandShield2::WHITE);

    XpandShield2::fillRect(58, 26, (sti4 >> 4), 4, XpandShield2::WHITE);
    XpandShield2::fillRect(58, 34, (sti5 >> 4), 4, XpandShield2::WHITE);

    XpandShield2::display();



    mouse.move(STK20 >> 1, STK00 >> 1);

    if (scramble) {
      stallFrame = !stallFrame;
      if (stallFrame) {

        if (moveFrame == 3)
          mouse.move((sti4 >> 5), 0);
        if (moveFrame == 2)
          mouse.move(0, (sti4 >> 5));
        if (moveFrame == 1)
          mouse.move(-(sti4 >> 5), 0);
        if (moveFrame == 0)
          mouse.move(0, -(sti4 >> 5));
        moveFrame++;
        if (moveFrame > 3)
          moveFrame = 0;
      }
    }
    mouse.update();
  }
}
