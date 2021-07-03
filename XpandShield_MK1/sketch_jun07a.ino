#include <SPI.h>
#include <Wire.h>
#include "XpandShield.h"

uint8_t CalcCrc(uint8_t data_a, uint8_t data_b)
{
  uint8_t crc = 0xFF;
  crc ^= data_a;
  for (uint8_t biter = 8; biter > 0; --biter) {
    if (crc & 0x80)
      crc = (crc << 1) ^ 0x31u;
    else
      crc = (crc << 1);
  }
  crc ^= data_b;
  for (uint8_t biter = 8; biter > 0; --biter) {
    if (crc & 0x80)
      crc = (crc << 1) ^ 0x31u;
    else
      crc = (crc << 1);
  }
  return crc;
}


enum class Sensor : uint8_t {SHT3X, STS30, SGP3X};

short choice;
short choicer;
bool indec;
bool rep;
bool measuring;
bool datarewrewer;


short temp;
short tempC;
short hum;
short airQ;

unsigned short daten_a;
unsigned short daten_b;
unsigned short daten_c;
unsigned short daten_d;

bool techDisp;
unsigned short daten_e;
unsigned short daten_f;
unsigned short daten_g;
unsigned short daten_h;
unsigned short daten_i;
unsigned short daten_j;


Sensor activeSensor;

#define ADDR_A 0x44
#define ADDR_B 0x69


void setup() {

XpandShield::Startup();
  XpandShield::setFrameDiff(100);
  
  activeSensor = Sensor::SHT3X;

  choice = 0;
  indec = false;
  choicer = 0;
  measuring = false;
  datarewrewer = false;
  temp = 0;
  tempC = 0;
  hum = 0;
  airQ = 0;

  daten_a = 0;
  daten_b = 0;
  daten_c = 0;
  daten_d = 0;


  techDisp = false;
  daten_e = 0;
  daten_f = 0;
  daten_g = 0;
  daten_h = 0;
  daten_i = 0;
  daten_j = 0;


  Wire.begin();
  //Serial.begin(9600);
}

void loop() {
  //time for each frame (in millis)
  if (XpandShield::nextFrame()) {
    //***********************************
    //*           BEGIN INTERFACE
    //************************************/
    if (activeSensor == Sensor::SHT3X) {

      if (XpandShield::justPressed(XpandShield::UP_BUTTON)) {
        if (indec)
          choicer--;
        else
          choice--;
      }
      if (XpandShield::justPressed(XpandShield::DOWN_BUTTON)) {
        if (indec)
          choicer++;
        else
          choice++;
      }

      if (XpandShield::justPressed(XpandShield::RIGHT_BUTTON)) {
        if (choice != 0)
          indec = true;
        if (choice == 0 && !rep)
          activeSensor = Sensor::STS30;

      }
      if (XpandShield::justPressed(XpandShield::LEFT_BUTTON)) {
        //if (choice != 0)
        indec = false;
        choicer = 0;
      }
      if (choice < 0)
        choice = 0;
      if (choice > 4)
        choice = 4;
      if (rep) {
        if (choice < 2)
          choice = 2;
        if (choice > 3)
          choice = 3;
        indec = false;
      }
      XpandShield::clearDisplay();
      XpandShield::drawPixel(0, 0, XpandShield::WHITE);
      XpandShield::drawPixel(127, 63, XpandShield::WHITE);
      
      XpandShield::drawRect(0, 0, 64, 10, XpandShield::WHITE);
      
      XpandShield::setCursor(0, 12);
      XpandShield::print("t\0", XpandShield::WHITE);
      XpandShield::setCursor(18, 12);
      XpandShield::printNum(temp / 10, XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::printNum(temp % 10, XpandShield::WHITE);
      XpandShield::setCursor(52, 12);
      XpandShield::printNum(tempC / 10, XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::printNum(tempC % 10, XpandShield::WHITE);
      XpandShield::setCursor(80, 12);
      XpandShield::print("hum\0", XpandShield::WHITE);
      XpandShield::setCursor(102, 12);
      XpandShield::printNum(hum, XpandShield::WHITE);
      XpandShield::write('%', XpandShield::WHITE);

      if (rep) {
        XpandShield::setCursor(10, 34);
        XpandShield::print("stop\0", XpandShield::WHITE);
        XpandShield::setCursor(10, 44);
        XpandShield::print("s. rst\0", XpandShield::WHITE);
      }
      else {
        XpandShield::setCursor(10, 24);
        XpandShield::print("1 shot\0", XpandShield::WHITE);
        XpandShield::setCursor(10, 34);
        XpandShield::print("multi.\0", XpandShield::WHITE);
        XpandShield::setCursor(10, 44);
        XpandShield::print("s. rst\0", XpandShield::WHITE);
        XpandShield::setCursor(10, 54);
        XpandShield::print("t.heat\0", XpandShield::WHITE);
        if (indec)
          switch (choice) {
            case 1:
            case 2:
              XpandShield::setCursor(59, 24);
              XpandShield::print("low rep\0", XpandShield::WHITE);
              XpandShield::setCursor(59, 34);
              XpandShield::print("med rep\0", XpandShield::WHITE);
              XpandShield::setCursor(59, 44);
              XpandShield::print("high rep\0", XpandShield::WHITE);
              if (choicer < 0)
                choicer = 0;
              if (choicer > 2)
                choicer = 2;
              break;
            case 3:
              XpandShield::setCursor(59, 24);
              XpandShield::print("no\0", XpandShield::WHITE);
              XpandShield::setCursor(59, 34);
              XpandShield::print("yes\0", XpandShield::WHITE);
              if (choicer < 3)
                choicer = 3;
              if (choicer > 4)
                choicer = 4;
              break;
            case 4:
              XpandShield::setCursor(59, 24);
              XpandShield::print("on\0", XpandShield::WHITE);
              XpandShield::setCursor(59, 34);
              XpandShield::print("off\0", XpandShield::WHITE);
              if (choicer < 5)
                choicer = 5;
              if (choicer > 6)
                choicer = 6;
          }

      }


      switch (choice) {
        case 0:
          XpandShield::fillRect(28, 3, 6, 4, XpandShield::WHITE);
          break;
        case 1:
        XpandShield::fillRect(5,26,2,2,XpandShield::WHITE);
          break;
        case 2:
        XpandShield::fillRect(5,37,2,2,XpandShield::WHITE);
          break;
        case 3:
        XpandShield::fillRect(5,47,2,2,XpandShield::WHITE);
          break;
        case 4:
        XpandShield::fillRect(5,57,2,2,XpandShield::WHITE);
          
      }
      if (indec)
        switch (choicer) {
          case 0:
          case 3:
          case 5:
          XpandShield::fillRect(53,26,2,2,XpandShield::WHITE);
            break;
          case 1:
          case 4:
          case 6:
          XpandShield::fillRect(53,37,2,2,XpandShield::WHITE);
            break;
          case 2:
          XpandShield::fillRect(53,47,2,2,XpandShield::WHITE);
        }

    }
    if (activeSensor == Sensor::STS30) {
      //choicer = 0;
      //indec = false;
      if (XpandShield::justPressed(XpandShield::UP_BUTTON))
        choice--;

      if (XpandShield::justPressed(XpandShield::DOWN_BUTTON))
        choice++;

      if (XpandShield::justPressed(XpandShield::LEFT_BUTTON))
        if (choice == 0)
          activeSensor = Sensor::SHT3X;

      if (XpandShield::justPressed(XpandShield::B_BUTTON))
        techDisp = !techDisp;

      XpandShield::clearDisplay();
      XpandShield::drawPixel(0, 0, XpandShield::WHITE);
      XpandShield::drawPixel(127, 63, XpandShield::WHITE);
      XpandShield::drawRect(64, 0, 64, 10, XpandShield::WHITE);
      
      XpandShield::setCursor(0, 12);
      XpandShield::print("AirQ\0", XpandShield::WHITE);
      XpandShield::setCursor(30, 12);
      XpandShield::printNum(airQ, XpandShield::WHITE);

      if (measuring) {
        XpandShield::setCursor(10, 24);
        XpandShield::print("stop\0", XpandShield::WHITE);
        XpandShield::setCursor(10, 34);
        XpandShield::print("clean\0", XpandShield::WHITE);
        if (choice < 3)
          choice = 3;
        if (choice > 4)
          choice = 4;
      } else {
        XpandShield::setCursor(10, 24);
        XpandShield::print("start\0", XpandShield::WHITE);
        //setCursor(20, 40);
        //print("sleep\0", WHITE);
        //the reason to not include sleep is because of two reasons:
        // 1. Sleep is not available to all STS30 modules, only to ones with firmware 2.0
        // 2. I'm lazy.
        // 3. It does not make much sense.
        XpandShield::setCursor(10, 34);
        XpandShield::print("s. rst\0", XpandShield::WHITE);
        if (choice < 0)
          choice = 0;
        if (choice > 2)
          choice = 2;
      }

      switch (choice) {
        case 0:
          XpandShield::fillRect(80, 3, 6, 4, XpandShield::WHITE);
          break;
        case 1:
        case 3:
          XpandShield::fillRect(5, 26, 2,2,XpandShield::WHITE);
          break;
        case 2:
        case 4:
        XpandShield::fillRect(5,37,2,2, XpandShield::WHITE);
          
          break;
      }
      if (techDisp) {
        XpandShield::drawVLine(68, 20, 20, XpandShield::WHITE);
        //number concentration: pm 0.5
        XpandShield::setCursor(71, 11);
        XpandShield::printNum(daten_e, XpandShield::WHITE);
        //1
        XpandShield::setCursor(71, 23);
        XpandShield::printNum(daten_f, XpandShield::WHITE);
        //2.5
        XpandShield::setCursor(71, 33);
        XpandShield::printNum(daten_g, XpandShield::WHITE);
        //4
        XpandShield::setCursor(71, 43);
        XpandShield::printNum(daten_h, XpandShield::WHITE);
        //10
        XpandShield::setCursor(71, 53);
        XpandShield::printNum(daten_i, XpandShield::WHITE);

      } else {
        //concentration: pm 1
        XpandShield::setCursor(71, 23);
        XpandShield::printNum(daten_a, XpandShield::WHITE);
        //2.5
        XpandShield::setCursor(71, 33);
        XpandShield::printNum(daten_b, XpandShield::WHITE);
        //4
        XpandShield::setCursor(71, 43);
        XpandShield::printNum(daten_c, XpandShield::WHITE);
        //10
        XpandShield::setCursor(71, 53);
        XpandShield::printNum(daten_d, XpandShield::WHITE);
        //typical particle size
        XpandShield::setCursor(71, 11);
        XpandShield::printNum(daten_j, XpandShield::WHITE);
      }

    }
    XpandShield::display();
    XpandShield::pollButtons();

    //***********************************
    //*           END INTERFACE
    //************************************

    if (XpandShield::justPressed(XpandShield::A_BUTTON)) {
      //***********************************
      //*           BEGIN COMMAND
      //***********************************
      if (activeSensor == Sensor::SHT3X) {

        Wire.beginTransmission(byte(ADDR_A));
        switch (choice) {
          case 1:
            //singleshot
            Wire.write(byte(0x24)); //clock stretching disabled
            //Wire.write(byte(0x2C)); //clock stretching enabled
            //clock stretching is disabled for stability;
            switch (choicer) {
              case 0:
                //low rep
                Wire.write(byte(0x16));
                break;
              case 1:
                //med rep
                Wire.write(byte(0x0B));;
                break;
              case 2:
                //high rep
                Wire.write(byte(0x00));
                break;

            }
            break;
          case 2:
            //periodic measure
            if (rep) {
              //stop
              Wire.write(byte(0x30));
              Wire.write(byte(0x93));
              rep = false;
            }
            else {
              Wire.write(byte(0x21));
              //0x20 0.5Hz    0x21 1Hz
              //0x22 2Hz      0x32 4Hz
              //0x27 10Hz
              //at high frequencies sensor might overheat
              switch (choicer) {
                case 0:
                  //low rep
                  Wire.write(byte(0x2D));
                  break;
                case 1:
                  //med rep
                  Wire.write(byte(0x26));
                  break;
                case 2:
                  //high rep
                  Wire.write(byte(0x30));
              }
              rep = true;
            }
            Wire.endTransmission();

            break;
          case 3:
            //reset
            if (choicer == 4 || rep) {
              //reset
              Wire.write(byte(0x30));
              Wire.write(byte(0xA2));
              rep = false;
            }

            break;
          case 4:
            Wire.write(0x30);
            switch (choicer) {
              case 5:
                //heater enable
                Wire.write(0x6D);
                break;
              case 6:
                //heater disable
                Wire.write(0x66);
                break;
            }
        }
        Wire.endTransmission();
        
        choice = 0;
        indec = false;
        choicer = 0;
      }
      if (activeSensor == Sensor::STS30) {
        Wire.beginTransmission(byte(ADDR_B));
        switch (choice) {
          case 1:
            measuring = true;
            //start measurement 0x0010
            Wire.write(byte(0x00));
            Wire.write(byte(0x10));
            //set measurement output to unsigned 16 bit integer
            Wire.write(byte(0x05));
            //dummy byte
            Wire.write(byte(0x00));
            //checksum for the above two bytes
            Wire.write(CalcCrc(0x05, 0x00));
            break;
          case 2:
            //soft reset
            Wire.write(0xD3);
            Wire.write(0x04);
            break;
          case 3:
            measuring = false;
            //end measurement
            Wire.write(byte(0x01));
            Wire.write(byte(0x04));
            break;
          case 4:
            //start fan cleaning
            Wire.write(byte(0x56));
            Wire.write(byte(0x07));
        }
        Wire.endTransmission();
        choice = 0;

        indec = false;
        choicer = 0;
      }

    }

    //***********************************
    //*           END COMMAND
    //***********************************
  }
  //if (perXFrame(50)) battery = 1126400L/*1.1x1024x1000*/ / rawADC(ADC_VOLTAGE);

  if (XpandShield::perXFrame(5)) {
    //every .5 second. Not too often, not too few.
    if (activeSensor == Sensor::SHT3X) {
      //we check to see if there is bytes to be read
      Wire.beginTransmission(byte(ADDR_A));
      if (rep) {
        Wire.write(byte(0xE0));
        Wire.write(byte(0x00));
      }
      if (Wire.requestFrom(byte(ADDR_A), 6, true))
        datarewrewer = true;
    }
    if (activeSensor == Sensor::STS30) {
      //we check to see if data is ready
      Wire.beginTransmission(byte(ADDR_B));
      //read data-ready flag
      Wire.write(0x02);
      Wire.write(0x02);
      Wire.endTransmission();

      if (Wire.requestFrom(byte(ADDR_B), 3, true)) {
        //first byte is unused.
        Wire.read();
        //if the second byte is 0x01
        if (Wire.read() == 0x01)
          //then new measurements are ready to read
          datarewrewer = true;
        Wire.read();
        //we don't really need the hash.
      }
      Wire.endTransmission();
    }
  }
  //***********************************
  //*          BEGIN READ
  //***********************************

  if (datarewrewer) {
    if (activeSensor == Sensor::SHT3X) {
        uint8_t c = Wire.read();    // receive a byte
        uint8_t d = Wire.read();    // receive a byte
        unsigned short e = ((c << 8) | d);
        //from the datasheet:
        //convert to farenheit
        //e = (315 * e) / 65535 - 49;
        //convert to celcius
        //e = (175 * e) / 65535 - 45;
        tempC = 10 * ((175.0 * (static_cast<float>(e) / 65535.0)) - 45);
        temp = 10 * ((315.0 * (static_cast<float>(e) / 65535.0)) - 49);
      
      Wire.read(); // we don't need the hash
            
        c = Wire.read();    // receive a byte
        d = Wire.read();    // receive a byte
        e = (c << 8) | d;
        //Serial.println(e);         // print the number
        //from the datasheet: convert to value (0 for 0%, 1 for 100%)
        //e = (e * 100) / 65535;
        hum = (100 * static_cast<float>(e)) / 65535.0;

      Wire.read(); //we don't need the hash
      Wire.endTransmission();
      datarewrewer = false;
    }
    if (activeSensor == Sensor::STS30) {
      Wire.beginTransmission(byte(ADDR_B));
      //read measurement values
      Wire.write(0x03);
      Wire.write(0x00);
      Wire.endTransmission();

      if (Wire.requestFrom(byte(ADDR_B), 30, true)) {
        uint8_t tmp_a = 0;
        uint8_t tmp_b = 0;
        unsigned short e = 0;

        //mass concentration PM 1.0
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_a = e;
        
        //throw away that hash
        Wire.read();

        //mass concentration PM 2.5
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_b = e;
        //throw away that hash
        Wire.read();

        //mass concentration PM 4.0
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_c = e;
        //throw away that hash
        Wire.read();

        //mass concentration PM 10
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_d = e;
        //throw away that hash
        Wire.read();

        //number concentration PM 0.5
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_e = e;
        //throw away that hash
        Wire.read();

        //number concentration PM 1.0
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_f = e;
        //throw away that hash
        Wire.read();

        //number concentration PM 2.5
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_g = e;
        //throw away that hash
        Wire.read();

        //number concentration PM 4.0
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_h = e;
        //throw away that hash
        Wire.read();

        //number concentration PM 10
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_i = e;
        //throw away that hash
        Wire.read();

        //typical particle size
        tmp_a = Wire.read();
        tmp_b = Wire.read();
        e = ((tmp_a << 8) | tmp_b);
        daten_j = e;
        //throw away that hash
        Wire.read();
      }

      Wire.endTransmission();
      datarewrewer = false;
    }
  }
  //***********************************
  //*            END READ
  //***********************************
}
