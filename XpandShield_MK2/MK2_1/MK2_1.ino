#include <XpandShield2.h>

int16_t sti0;
int16_t sti1;
int16_t sti2;
int16_t sti3;
int16_t sti4;
int16_t sti5;
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
  XpandShield2::setFrameDiff(100);

  sti0 = 0;
  sti1 = 0;
  sti2 = 0;
  sti3 = 0;
  sti4 = 0;
  sti5 = 0;

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
    //dpad
    if (XpandShield2::pressed(XpandShield2::UP_BUTTON))
      XpandShield2::drawRect(23, 40, 3, 5, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::DOWN_BUTTON))
      XpandShield2::drawRect(23, 58, 3, 5, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::LEFT_BUTTON))
      XpandShield2::drawRect(13, 50, 5, 3, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::RIGHT_BUTTON))
      XpandShield2::drawRect(31, 50, 5, 3, XpandShield2::WHITE);



    XpandShield2::drawCircle(61, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(69, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(77, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(85, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(93, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(101, 43, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::A_BUTTON))
      fillCircle(61, 43, 2, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::B_BUTTON))
      fillCircle(69, 43, 2, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::C_BUTTON))
      fillCircle(77, 43, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::X_BUTTON))
      fillCircle(85, 43, 2, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::Y_BUTTON))
      fillCircle(93, 43, 2, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::Z_BUTTON))
      fillCircle(101, 43, 2, XpandShield2::WHITE);




    XpandShield2::drawCircle(109, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(117, 43, 2, XpandShield2::WHITE);
    XpandShield2::drawCircle(61, 51, 2, XpandShield2::WHITE);

    if (XpandShield2::pressed(XpandShield2::START_BUTTON))
      fillCircle(109, 43, 2, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::SELECT_BUTTON))
      fillCircle(117, 43, 2, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::MENU_BUTTON))
      fillCircle(61, 51, 2, XpandShield2::WHITE);




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

    if (XpandShield2::pressed(XpandShield2::STK_S_BUTTON))
      fillCircle(101, 51, 2, XpandShield2::WHITE);



    if (XpandShield2::pressed(XpandShield2::L1_BUTTON))
      XpandShield2::fillRect(58, 1, 32, 6, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::R1_BUTTON))
      XpandShield2::fillRect(91, 1, 32, 6, XpandShield2::WHITE);




    XpandShield2::drawVLine(24, 45, 5, XpandShield2::WHITE);
    XpandShield2::drawVLine(24, 53, 5, XpandShield2::WHITE);
    XpandShield2::drawHLine(18, 51, 5, XpandShield2::WHITE);
    XpandShield2::drawHLine(26, 51, 5, XpandShield2::WHITE);






    if (XpandShield2::pressed(XpandShield2::STK_U_BUTTON))
      XpandShield2::drawRect(23, 45, 3, 5, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::STK_D_BUTTON))
      XpandShield2::drawRect(23, 53, 3, 5, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::STK_L_BUTTON))
      XpandShield2::drawRect(18, 50, 5, 3, XpandShield2::WHITE);
    if (XpandShield2::pressed(XpandShield2::STK_R_BUTTON))
      XpandShield2::drawRect(26, 50, 5, 3, XpandShield2::WHITE);







    //XpandShield2::setCursor(13, 6);
    //XpandShield2::printNum(sti0, XpandShield2::WHITE);
    //XpandShield2::setCursor(13, 23);
    //XpandShield2::printNum(sti1, XpandShield2::WHITE);


    XpandShield2::drawVLine(8 + (sti2 >> 5), 5, 32, XpandShield2::WHITE);
    XpandShield2::drawHLine(9, 4 + (sti0 >> 5), 32, XpandShield2::WHITE);

    
    if ((32-(sti1 >> 4)) > 0)
      XpandShield2::fillRect(90, 9, 32-(sti1 >> 4), 6, XpandShield2::WHITE);
    else
      XpandShield2::fillRect(122 - (sti1 >> 4), 9, (sti1 >> 4)-32, 6, XpandShield2::WHITE);


    if ((sti3 >> 4) - 32 > 0)
      XpandShield2::fillRect(90, 17, (sti3 >> 4) - 32, 6, XpandShield2::WHITE);
    else
      XpandShield2::fillRect(58 + (sti3 >> 4), 17, 32-(sti3 >> 4), 6, XpandShield2::WHITE);
    XpandShield2::fillRect(58, 25, (sti4 >> 4), 6, XpandShield2::WHITE);
    XpandShield2::fillRect(58, 33, (sti5 >> 4), 6, XpandShield2::WHITE);
    //XpandShield2::setCursor(40, 16);
    //XpandShield2::printNum(sti2, XpandShield2::WHITE);
    //XpandShield2::setCursor(40, 33);
    //XpandShield2::printNum(sti3, XpandShield2::WHITE);


    //XpandShield2::setCursor(69, 23);
    //XpandShield2::printNum(sti4, XpandShield2::WHITE);
    //XpandShield2::setCursor(100, 23);
    //XpandShield2::printNum(sti5, XpandShield2::WHITE);


    XpandShield2::display();





  }
}
