#include <XpandShield2.h>
#include "joystick.h"

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
int16_t deadzone;


int16_t sti4;
int16_t sti5;

int8_t stkX, stkY;

/* For later:
class MenuButton
{
  char *btnName;
  MenuButton *children, *parent;
  
}
*/

//Temporary:
int menuPos=1;
bool calibrate=false;

bool menu=false, prevMenu=false, prevUp=false, prevDown=false, prevLeft=false, prevRight=false;

//need to cast to 32 bit to preserve 10 bit precision
#define STK00 ((sti0>sti0_mid)? (((sti0-sti0_mid)<<5) / (sti0_max-sti0_mid)) : (((sti0-sti0_mid)<<5) / (sti0_mid-sti0_min)))
#define STK10 ((sti1>sti1_mid)? (((sti1-sti1_mid)<<5) / (sti1_max-sti1_mid)) : (((sti1-sti1_mid)<<5) / (sti1_mid-sti1_min)))
#define STK20 ((sti2>sti2_mid)? (((sti2-sti2_mid)<<5) / (sti2_max-sti2_mid)) : (((sti2-sti2_mid)<<5) / (sti2_mid-sti2_min)))
#define STK30 ((sti3>sti3_mid)? (((sti3-sti3_mid)<<5) / (sti3_max-sti3_mid)) : (((sti3-sti3_mid)<<5) / (sti3_mid-sti3_min)))



Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   14, 2,                  // Button Count, Hat Switch Count
                   true, true, true,     // X and Y, Z Axis
                   true, true, true,   // Rx, Ry, Rz
                   false, true,          //rudder, throttle
                   false, false, false);  //accelerator, brake, steering



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


void centerAxis
(void)
{
  sti0_mid = analogRead(A0);
  sti1_mid = analogRead(A1);
  sti2_mid = analogRead(A2);
  sti3_mid = analogRead(A3);
  sti4 = analogRead(A4);
  sti5 = analogRead(A5);
  sti0_min = sti0_mid;
  sti0_max = sti0_mid;
  sti1_min = sti1_mid;
  sti1_max = sti1_mid;
  sti2_min = sti2_mid;
  sti2_max = sti2_mid;
  sti3_min = sti3_mid;
  sti3_max = sti3_mid;

}

void setup
(void)
{
  // put your setup code here, to run once:
  XpandShield2::Startup();
  XpandShield2::setFrameDiff(100);
  Joystick.begin(false);

  centerAxis();
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
    if (!menu)
    {
      XpandShield2::drawRect(8, 4, 34, 34, XpandShield2::WHITE);
      XpandShield2::drawRect(57, 1, 65, 6, XpandShield2::WHITE);
      XpandShield2::drawRect(57, 9, 65, 6, XpandShield2::WHITE);
      XpandShield2::drawRect(57, 17, 65, 6, XpandShield2::WHITE);
      XpandShield2::drawRect(57, 25, 65, 6, XpandShield2::WHITE);
      XpandShield2::drawRect(57, 33, 65, 6, XpandShield2::WHITE);
    
    
      XpandShield2::drawVLine(24, 40, 5, XpandShield2::WHITE);
      XpandShield2::drawVLine(24, 58, 5, XpandShield2::WHITE);
      XpandShield2::drawHLine(13, 51, 5, XpandShield2::WHITE);
      XpandShield2::drawHLine(31, 51, 5, XpandShield2::WHITE);
    }
    //dpad
    {
      int8_t dirX = 0;
      int8_t dirY = 0;
      if (XpandShield2::pressed(XpandShield2::UP_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(23, 40, 3, 5, XpandShield2::WHITE);
        dirY = dirY - 1;
      }
      if (XpandShield2::pressed(XpandShield2::DOWN_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(23, 58, 3, 5, XpandShield2::WHITE);
        dirY = dirY + 1;
      }
      if (XpandShield2::pressed(XpandShield2::LEFT_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(13, 50, 5, 3, XpandShield2::WHITE);
        dirX = dirX - 1;
      }
      if (XpandShield2::pressed(XpandShield2::RIGHT_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(31, 50, 5, 3, XpandShield2::WHITE);
        dirX = dirX + 1;
      }
      if (dirY < 0) {
        if (dirX > 0)
          Joystick.setHatSwitch(0, 1);
        else if (dirX < 0)
          Joystick.setHatSwitch(0, 7);
        else
          Joystick.setHatSwitch(0, 0);
      }
      else if (dirY > 0) {
        if (dirX > 0)
          Joystick.setHatSwitch(0, 3);
        else if (dirX < 0)
          Joystick.setHatSwitch(0, 5);
        else
          Joystick.setHatSwitch(0, 4);
      }
      else if (dirX > 0)
        Joystick.setHatSwitch(0, 2);
      else if (dirX < 0)
        Joystick.setHatSwitch(0, 6);
      else
        Joystick.setHatSwitch(0, -1);
    }


    if (!menu)
    {
      XpandShield2::drawCircle(61, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(69, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(77, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(85, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(93, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(101, 43, 2, XpandShield2::WHITE);
    }
    
    if (XpandShield2::pressed(XpandShield2::A_BUTTON)) {
      if (!menu)
        fillCircle(61, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(0, 1);
    }
    else
      Joystick.setButton(0, 0);
    if (XpandShield2::pressed(XpandShield2::B_BUTTON)) {
      if (!menu)
        fillCircle(69, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(1, 1);
    }
    else
      Joystick.setButton(1, 0);
    if (XpandShield2::pressed(XpandShield2::C_BUTTON)) {
      if (!menu)
        fillCircle(77, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(2, 1);
    }
    else
      Joystick.setButton(2, 0);
    if (XpandShield2::pressed(XpandShield2::X_BUTTON)) {
      if (!menu)
        fillCircle(85, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(3, 1);
    }
    else
      Joystick.setButton(3, 0);
    if (XpandShield2::pressed(XpandShield2::Y_BUTTON)) {
      if (!menu)
        fillCircle(93, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(4, 1);
    }
    else
      Joystick.setButton(4, 0);
    if (XpandShield2::pressed(XpandShield2::Z_BUTTON)) {
      if (!menu)
        fillCircle(101, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(5, 1);
    } else
      Joystick.setButton(5, 0);



    if (!menu)
    {
      XpandShield2::drawCircle(109, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(117, 43, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(61, 51, 2, XpandShield2::WHITE);
    }

    if (XpandShield2::pressed(XpandShield2::START_BUTTON)) {
      if (!menu)
        fillCircle(109, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(6, 1);
    } else
      Joystick.setButton(6, 0);
    if (XpandShield2::pressed(XpandShield2::SELECT_BUTTON)) {
      if (!menu)
        fillCircle(117, 43, 2, XpandShield2::WHITE);
      Joystick.setButton(7, 1);
    } else
      Joystick.setButton(7, 0);
    if (XpandShield2::pressed(XpandShield2::MENU_BUTTON)) {
      menu=!prevMenu;
      if (!menu)
      {
        menuPos=1;
        fillCircle(61, 51, 2, XpandShield2::WHITE);
        Joystick.setButton(8, 1);
      }
    } else
    {
      prevMenu=menu;
      Joystick.setButton(8, 0);
    }





    if (!menu)
    {
      XpandShield2::drawCircle(69, 51, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(77, 51, 2, XpandShield2::WHITE);
    }

    if (XpandShield2::pressed(XpandShield2::L2_BUTTON)) {
      if (!menu)
        fillCircle(69, 51, 2, XpandShield2::WHITE);
      Joystick.setButton(9, 1);
    } else
      Joystick.setButton(9, 0);
    if (XpandShield2::pressed(XpandShield2::R2_BUTTON)) {
      if (!menu)
        fillCircle(77, 51, 2, XpandShield2::WHITE);
      Joystick.setButton(10, 1);
    } else
      Joystick.setButton(10, 0);



    //Joystick center button handling (last 3 circles)

    if (!menu)
    {
      XpandShield2::drawCircle(85, 51, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(93, 51, 2, XpandShield2::WHITE);
      XpandShield2::drawCircle(101, 51, 2, XpandShield2::WHITE);
    }

    if (XpandShield2::pressed(XpandShield2::C1_BUTTON)) {
      if (!menu)
        fillCircle(85, 51, 2, XpandShield2::WHITE);
      Joystick.setButton(11, 1);
    } else
      Joystick.setButton(11, 0);
    if (XpandShield2::pressed(XpandShield2::C2_BUTTON)) {
      if (!menu)
        fillCircle(93, 51, 2, XpandShield2::WHITE);
      Joystick.setButton(12, 1);
    } else
      Joystick.setButton(12, 0);
    if (XpandShield2::pressed(XpandShield2::STK_S_BUTTON)) {
      if (!menu)
        fillCircle(101, 51, 2, XpandShield2::WHITE);
      Joystick.setButton(13, 1);
    } else
      Joystick.setButton(13, 0);

    {
      int8_t sho = 0;
      if (XpandShield2::pressed(XpandShield2::L1_BUTTON))
        ++sho;
      if (XpandShield2::pressed(XpandShield2::R1_BUTTON))
        --sho;
      if (sho == 0) {
        Joystick.setZAxis(512);
        if (!menu)
          XpandShield2::fillRect(58, 1, 32, 6, XpandShield2::WHITE);
      } if (sho == 1) {
        Joystick.setZAxis(1024);
        if (!menu)
          XpandShield2::fillRect(58, 1, 63, 6, XpandShield2::WHITE);
      } if (sho == -1)
        Joystick.setZAxis(0);
    }

    if (!menu)
    {
      XpandShield2::drawVLine(24, 45, 5, XpandShield2::WHITE);
      XpandShield2::drawVLine(24, 53, 5, XpandShield2::WHITE);
      XpandShield2::drawHLine(18, 51, 5, XpandShield2::WHITE);
      XpandShield2::drawHLine(26, 51, 5, XpandShield2::WHITE);
    }



    stkX = 0;
    stkY = 0;
    if (XpandShield2::pressed(XpandShield2::STK_S_BUTTON)) {
      if (XpandShield2::pressed(XpandShield2::STK_D_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(23, 45, 3, 5, XpandShield2::WHITE);
        else if (!calibrate && !prevDown)
        {
          menuPos++;
          if (menuPos > 3)
            menuPos=1;
        }
        prevDown=true;
        --stkY;
      }
      else prevDown=false;
      if (XpandShield2::pressed(XpandShield2::STK_L_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(23, 53, 3, 5, XpandShield2::WHITE);
        else if (!calibrate && !prevLeft)
        {
          menu=false;
        }
        ++stkY;
        prevLeft=true;
      }
      else prevLeft=false;
      if (XpandShield2::pressed(XpandShield2::STK_U_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(18, 50, 5, 3, XpandShield2::WHITE);
        else if (!calibrate && !prevUp)
        {
          menuPos++;
          if (menuPos < 1)
            menuPos=3;
        }
        --stkX;
        prevUp=true;
      }
      else prevUp=false;
      if (XpandShield2::pressed(XpandShield2::STK_R_BUTTON)) {
        if (!menu)
          XpandShield2::drawRect(26, 50, 5, 3, XpandShield2::WHITE);
        else if (!calibrate && !prevRight)
        {
          if (menuPos == 1)
            calibrate=true;
        }
        ++stkX;
        prevRight=true;
      }
      else prevRight=false;
    }


    if (stkY < 0) {
      if (stkX > 0)
        Joystick.setHatSwitch(1, 1);
      else if (stkX < 0)
        Joystick.setHatSwitch(1, 7);
      else
        Joystick.setHatSwitch(1, 0);
    }
    else if (stkY > 0) {
      if (stkX > 0)
        Joystick.setHatSwitch(1, 3);
      else if (stkX < 0)
        Joystick.setHatSwitch(1, 5);
      else
        Joystick.setHatSwitch(1, 4);
    }
    else if (stkX > 0)
      Joystick.setHatSwitch(1, 2);
    else if (stkX < 0)
      Joystick.setHatSwitch(1, 6);
    else
      Joystick.setHatSwitch(1, -1);





    //Joystick.setRxAxisRange(0, 360);

    //XpandShield2::setCursor(13, 6);
    //XpandShield2::printNum(sti0, XpandShield2::WHITE);
    //XpandShield2::setCursor(13, 23);
    //XpandShield2::printNum(sti1, XpandShield2::WHITE);

    if (!menu)
    {
      XpandShield2::drawVLine(8 + 16 + (STK20 >> 1), 5, 32, XpandShield2::WHITE);
      XpandShield2::drawHLine(9, 4 + 16 + (STK00 >> 1), 32, XpandShield2::WHITE);
    }

    Joystick.setXAxis((32 + STK20) << 4);
    Joystick.setYAxis((32 + STK00) << 4);

    //if ((32 - (sti1 >> 4)) > 0)
    if (!menu)
      XpandShield2::fillRect(58, 10, 32 - STK10, 4, XpandShield2::WHITE);
    //else
    //XpandShield2::fillRect(122 - (sti1 >> 4), 9, (sti1 >> 4) - 32, 6, XpandShield2::WHITE);


    if (!menu)
      XpandShield2::fillRect(58, 18, 32 - STK30, 4, XpandShield2::WHITE);

    Joystick.setRxAxis((32 - STK10) << 4);
    Joystick.setRyAxis((32 - STK30) << 4);


    //if ((sti3 >> 4) - 32 > 0)

    //else
    //XpandShield2::fillRect(58 + (sti3 >> 4), 17, 32 - (sti3 >> 4), 6, XpandShield2::WHITE);
    if (!menu)
    {
      XpandShield2::fillRect(58, 26, (sti4 >> 4), 4, XpandShield2::WHITE);
      XpandShield2::fillRect(58, 34, (sti5 >> 4), 4, XpandShield2::WHITE);
    }

    Joystick.setRzAxis(sti5);
    Joystick.setThrottle(sti4);

    //Do the menu stuff
    if (menu)
    {
      if (menuPos == 1)
        XpandShield2::fillRect(5, 5, 118, 10, XpandShield2::WHITE);
      else XpandShield2::drawRect(5, 5, 118, 10, XpandShield2::WHITE);
      XpandShield2::setCursor(6, 6);
      XpandShield2::print("Calibrate", menuPos == 1 ? XpandShield2::WHITE : XpandShield2::BLACK);

      if (menuPos == 2)
        XpandShield2::fillRect(5, 20, 118, 10, XpandShield2::WHITE);
      else XpandShield2::drawRect(5, 20, 118, 10, XpandShield2::WHITE);
      XpandShield2::setCursor(6, 21);
      XpandShield2::print("Edit Deadzone", menuPos == 2 ? XpandShield2::WHITE : XpandShield2::BLACK);

      if (menuPos == 3)
        XpandShield2::fillRect(5, 35, 118, 10, XpandShield2::WHITE);
      else XpandShield2::drawRect(5, 35, 118, 10, XpandShield2::WHITE);
      XpandShield2::setCursor(6, 36);
      XpandShield2::print("Test", menuPos == 3 ? XpandShield2::WHITE : XpandShield2::BLACK);


    //XpandShield2::setCursor(40, 16);
    //XpandShield2::printNum(sti2, XpandShield2::WHITE);
    //XpandShield2::setCursor(40, 33);
    //XpandShield2::printNum(sti3, XpandShield2::WHITE);


    //XpandShield2::setCursor(69, 23);
    //XpandShield2::printNum(sti4, XpandShield2::WHITE);
    //XpandShield2::setCursor(100, 23);
    //XpandShield2::printNum(sti5, XpandShield2::WHITE);


    XpandShield2::display();
    Joystick.sendState();




  }
}
