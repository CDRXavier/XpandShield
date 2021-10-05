#include <SPI.h>
#include <XpandShield.h>

short an8;
short an8_min;
short an8_mid;
short an8_max;
short an9;
short an9_min;
short an9_mid;
short an9_max;


int8_t x;
int8_t y;
int8_t mid_x;
int8_t mid_y;

void setup() {

XpandShield::Startup();
  XpandShield::setFrameDiff(50);
  
  pinMode(A0, INPUT);
pinMode(A2, INPUT);
  an8 = 0;
  an9 = 0;
x = 10;
y = 10;



delay(10);
an8_mid = analogRead(A0);
an9_mid = analogRead(A2);
an8_min = an8_mid;
an9_min = an9_mid;
an8_max = an8_mid;
an9_max = an9_mid;
}

void loop() {
  //time for each frame (in millis)
  if (XpandShield::nextFrame()) {

an8 = analogRead(A0);
an9 = analogRead(A2);
XpandShield::pollButtons();


if (XpandShield::pressed(XpandShield::B_BUTTON)){
  an8_mid = an8;
an9_mid = an9;
//mid_x = x;
//mid_y = y;
}
if (XpandShield::pressed(XpandShield::A_BUTTON)) {
  an8_min = an8_mid;
an9_min = an9_mid;
an8_max = an8_mid;
an9_max = an9_mid;
}

if (an8<an8_min)
an8_min = an8;

if (an8>an8_max)
an8_max = an8;


if (an9<an9_min)
an9_min = an9;

if (an9>an9_max)
an9_max = an9;

if (an8 > an8_mid)
x = (an8-an8_mid) * 32 / (an8_max-an8_mid);
else
x = (an8-an8_mid)*32 / (an8_mid-an8_min);


//y = (an9-an9_mid) * 32 / (an9_max-an9_mid);

if (an9 > an9_mid)
y = (an9-an9_mid) * 32 / (an9_max-an9_mid);
else
y = (an9-an9_mid)*32 / (an9_mid-an9_min);

mid_x = an8_mid * 64 / (an8_max-an8_min);
mid_y = an9_mid * 64 / (an9_max-an9_min);
      XpandShield::clearDisplay();
      
      
      XpandShield::drawVLine(x+64, 0,64, XpandShield::WHITE);
      XpandShield::drawHLine(32, y+32,64, XpandShield::WHITE);

      
      XpandShield::drawRect(32, 0, 64, 64, XpandShield::WHITE);
      
      XpandShield::drawRect(mid_x+32, mid_y, 4,4, XpandShield::WHITE);
      
      XpandShield::setCursor(5, 12);
      XpandShield::printNum(an8, XpandShield::WHITE);
      XpandShield::setCursor(5, 22);
      XpandShield::printNum(an8_min, XpandShield::WHITE);
      XpandShield::setCursor(5, 32);
      XpandShield::printNum(an8_max, XpandShield::WHITE);
      XpandShield::setCursor(5, 42);
      XpandShield::printNum(an8_mid, XpandShield::WHITE);
      
      XpandShield::setCursor(100, 12);
      XpandShield::printNum(an9, XpandShield::WHITE);
      XpandShield::setCursor(100, 22);
      XpandShield::printNum(an9_min, XpandShield::WHITE);
      XpandShield::setCursor(100, 32);
      XpandShield::printNum(an9_max, XpandShield::WHITE);
      XpandShield::setCursor(100, 42);
      XpandShield::printNum(an9_mid, XpandShield::WHITE);
      XpandShield::display();
  }
  //***********************************
  //*            END READ
  //***********************************
}
