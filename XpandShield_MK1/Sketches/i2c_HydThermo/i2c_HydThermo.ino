// I2C SRF10 or SRF08 Devantech Ultrasonic Ranger Finder
// by Nicholas Zambetti <http://www.zambetti.com>
// and James Tichenor <http://www.jamestichenor.net>

// Demonstrates use of the Wire library reading data from the
// Devantech Utrasonic Rangers SFR08 and SFR10

// Created 29 April 2006

// This example code is in the public domain.


#include <Wire.h>
#define addr 0x44

int choice = 0;
bool dot;
uint8_t gencrc(uint8_t *data, size_t len)
{
  uint8_t crc = 0xff;
  size_t i, j;
  for (i = 0; i < len; i++) {
    crc ^= data[i];
    for (j = 0; j < 8; j++) {
      if ((crc & 0x80) != 0)
        crc = (uint8_t)((crc << 1) ^ 0x31);
      else
        crc <<= 1;
    }
  }
  return crc;
}



unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 4000;
unsigned long currentMillis = 0;

void setup() {
  Wire.begin();                // join i2c bus (address optional for master)

  Serial.begin(9600);          // start serial communication at 9600bps
  while (!Serial) {}
  int nDevices = 0;
  Serial.println("Scanning...");
  for (byte address = 1; address < 127; ++address) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);


    byte error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      ++nDevices;
    }
    else {
      if (error == 4) {
        Serial.print("Unknown error at address 0x");
        if (address < 16)
          Serial.print("0");
        Serial.println(address, HEX);
      }
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
  dot = false;
  pinMode(11, OUTPUT);
}

void loop() {
  currentMillis = millis();
  // step 1: instruct sensor to read echoes

  //Wire.beginTransmission(112); // transmit to device #112 (0x70)
  //if (!measuring) {
  if (Serial.available() > 0) {
    choice = Serial.read();
    Serial.println(choice);
    if (choice == 109) {
      //109 is '\n' + 'm'
      Wire.beginTransmission(byte(addr));
      Wire.write(byte(0x24));
      Wire.write(byte(0x0B));
      //single shot measurement, medium repeatability, clock stretching disabled
      Wire.endTransmission();      // stop transmitting
      //measuring = true;
      Serial.print("Measurement command sent to ");
      Serial.println(addr, HEX);
    } else {
      if (choice == 99) {
        //99 is '\n' + 'c'
        //assume controller is busy
        Wire.beginTransmission(byte(addr));
        Serial.print("Received ");
        byte istr = Wire.requestFrom(byte(addr), 6, true);
        Serial.print(istr);
        Serial.println(" bytes");
        / if (istr == 0) {
          //  Serial.println("busy");
          //controller is busy
          measuring = true;
        } else {
          if (choice == 100) {
            //100 is '\n' + 'd'
            //controller is free
            //  measuring = false;
            //Serial.print("Stream received \n");
            //while (Wire.available()) {
            // slave may send less than requested
            Serial.println("temp");
            if (Wire.available() > 1) {
              uint8_t c = Wire.read();    // receive a byte
              uint8_t d = Wire.read();    // receive a byte
              //Serial.println(c);
              //Serial.println(d);
              unsigned short e = ((c << 8) | d);
              //Serial.println(e);         // print the number
              //from the datasheet: convert to farenheit
              //e = (315 * e) / 65535 - 49;
              //from the datasheet: convert to celcius
              //e = (175 * e) / 65535 - 45;
              Serial.println(-45.0 + (175.0 * (static_cast<double>(e) / 65535.0)));
              Serial.println(-49.0 + (315.0 * (static_cast<double>(e) / 65535.0)));
              // print the number
            }
          }
          if (Wire.available()) Wire.read(); // throw away that hash we don't need it rn
          //}
          Serial.println("humidity:");
          if (Wire.available() > 1) {
            uint8_t c = Wire.read();    // receive a byte
            uint8_t d = Wire.read();    // receive a byte
            //Serial.println(c);
            //Serial.println(d);
            unsigned short e = (c << 8) | d;
            //Serial.println(e);         // print the number
            //from the datasheet: convert to value (0 for 0%, 1 for 100%)
            //e = (e * 100) / 65535;
            Serial.println(static_cast<double>(e) / 65535.0);
            Serial.println(e);         // print the number
          }
        }
        if (Wire.available()) Wire.read(); // throw away that hash we don't need it rn

        Wire.endTransmission();
      }
    }
  }
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    if (dot) {
      digitalWrite(11, HIGH);
      dot = false;
    }
    else {
      dot = true;
      digitalWrite(11, LOW);
    }
  }
}

uint8_t crc8(const uint8_t *data, uint8_t len)
{
  // CRC-8 formula from page 14 of SHT spec pdf
  const uint8_t POLY(0x31);
  uint8_t crc(0xFF);

  for (uint8_t j = len; j; --j)
  {
    crc ^= *data++;

    for (uint8_t i = 8; i; --i)
    {
      crc = (crc & 0x80) ? (crc << 1) ^ POLY : (crc << 1);
    }
  }
  return crc;
}
