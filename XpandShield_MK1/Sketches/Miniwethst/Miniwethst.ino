/*
  Hello, World! example
  June 11, 2015
  Copyright (C) 2015 David Martinez
  All rights reserved.
  This code is the most basic barebones code for writing a program for Arduboy.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
*/
#define addr 0x44
#include "Arduboy.h"
#include <Wire.h>
// make an instance of arduboy used for many functions
Arduboy arduboy;
unsigned short dot;
int choice;
bool blin;
bool measuring;
// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
int sendMeasurementCommand();

void setup() {
  // initiate arduboy instance
  blin = false;
  choice = 0;
  arduboy.begin();

  Wire.begin(0x2C);                // join i2c bus (address optional for master)
  //Serial.begin(9600);          // start serial communication at 9600bps
  //while (!Serial) {}
  int nDevices = 0;
  arduboy.setCursor(0, 0);
  arduboy.println("Scanning...");
  for (byte address = 1; address < 127; ++address) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();
    if (error == 0) {
      arduboy.print("I2C device at 0x");
      if (address < 16)
        arduboy.print("0");
      arduboy.print(address, HEX);
      arduboy.println("  !");
      ++nDevices;
    }
    else {
      if (error == 4) {
        arduboy.print("Unknown error at 0x");
        if (address < 16)
          arduboy.print("0");
        arduboy.println(address, HEX);
      }
    }
  }
  if (nDevices == 0)
    arduboy.println("No I2C devices found\n");
  else
    arduboy.println("done\n");

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);

arduboy.clear();
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // first we clear our screen to black
  

  // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0)
  //arduboy.setCursor(4, 9);

  //if (Serial.available() > 0) {
    arduboy.clear();
    //choice = arduboy.read();
    
    if (arduboy.pressed(UP_BUTTON)) {
      //109 is '\n' + 'm'
      measuring = true;
      arduboy.print("starting measurement");
      //Serial.println(addr, HEX);
      arduboy.display();
    }
    //else {
    if (arduboy.pressed(DOWN_BUTTON)) {
      //arduboy.clear();
      //99 is '\n' + 'c'
      //assume controller is busy
      Wire.beginTransmission(byte(addr));
      arduboy.print("Received ");
      //byte istr =
      arduboy.print(Wire.requestFrom(byte(addr), 6, true));
      arduboy.println(" bytes");
      //if (istr == 0) {
      //  Serial.println("busy");
      //controller is busy
      //  measuring = true;
      //}
      //else {
      arduboy.display();
    }
    if (arduboy.pressed(A_BUTTON)) {
      arduboy.clear();
      //100 is '\n' + 'd'
      //controller is free
      //  measuring = false;
      //Serial.print("Stream received \n");
      //while (Wire.available()) {
      // slave may send less than requested
      arduboy.println("temp");
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
        arduboy.println(-45.0 + (175.0 * (static_cast<double>(e) / 65535.0)));
        arduboy.println(-49.0 + (315.0 * (static_cast<double>(e) / 65535.0)));
        // print the number
      }

      if (Wire.available()) Wire.read(); // throw away that hash we don't need it rn
      //}
      arduboy.println("humidity:");
      if (Wire.available() > 1) {
        uint8_t c = Wire.read();    // receive a byte
        uint8_t d = Wire.read();    // receive a byte
        //Serial.println(c);
        //Serial.println(d);
        unsigned short e = (c << 8) | d;
        //Serial.println(e);         // print the number
        //from the datasheet: convert to value (0 for 0%, 1 for 100%)
        //e = (e * 100) / 65535;
        arduboy.println(static_cast<double>(e) / 65535.0);
        arduboy.println(e);         // print the number
      }
      //}
      if (Wire.available()) Wire.read(); // throw away that hash we don't need it rn

      Wire.endTransmission();
      
    }
  
  //if (currentMillis - previousMillis >= interval) {
  // save the last time you blinked the LED
  //previousMillis = currentMillis;
  //Serial.print('.');
  ++dot;
  if (dot > 20) {
    //  Serial.print('\n');
      dot = 0;
    if (blin) {
      digitalWrite(LED_BUILTIN, HIGH);
      blin = false;
    } else {
      blin = true;
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  // then we print to screen what is in the Quotation marks ""
  //arduboy.print(F("Hello, world!"));

  // then we finaly we tell the arduboy to display what we just wrote to the display
}

int sendMeasurementCommand() {
  Wire.beginTransmission(byte(addr));
      Wire.write(byte(0x24));
      Wire.write(byte(0x0B));
      //single shot measurement, medium repeatability, clock stretching disabled
      Wire.endTransmission();      // stop transmitting
      

}
