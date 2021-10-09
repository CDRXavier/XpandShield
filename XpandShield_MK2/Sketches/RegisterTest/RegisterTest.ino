#include <SPI.h>

SPISettings spiSettings = SPISettings(8000000UL, MSBFIRST, SPI_MODE0);
uint8_t input;
uint8_t input1;
uint8_t input2;
void setup() {
  if (!Serial) delay(1);
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  //pinMode(A1, INPUT);
  //pinMode(A2, OUTPUT);
  
  //pinMode(12, OUTPUT);
  //pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  //pinMode(8, OUTPUT);
  //pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  //pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  delay(1000);


  //digitalWrite(12, HIGH);
  //digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  //digitalWrite(8, HIGH);
  //digitalWrite(7, LOW);
  //digitalWrite(6, HIGH);
  //digitalWrite(5, LOW);
  
  SPI.begin();
  //async parallel load
  digitalWrite(9, LOW);
  //clock enable (active low)
  digitalWrite(10, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //disable parallel load (serial shift)
    digitalWrite(9, HIGH);
    delay(10);
    //enable clock
    digitalWrite(10, LOW);
    delay(1);
    SPI.beginTransaction(spiSettings);
    //digitalWrite(A2, HIGH);
    input = SPI.transfer(0x00);
    input1 = SPI.transfer(0x00);
    input2 = SPI.transfer(0x00);
    //delay(900);
//for (uint8_t i = 0; i < 8; i++){
  //digitalWrite(A2, LOW);
//if (digitalRead(A1)==HIGH)
//    Serial.print('H');
//  else
//    Serial.print('L');
//      digitalWrite(A2, HIGH);
//}
//digitalWrite(A2, LOW);
    SPI.endTransaction();
    
    delay(1);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    //input = 0x34;
//Serial.print(input);



    if (input & 0b00000001)
      Serial.print('H');
    else
      Serial.print('L');
      //Serial.print(input);
    if (input & 0b00000010)
      Serial.print('H');
    else
      Serial.print('L');
    if (input & 0b00000100)
      Serial.print('H');
    else
      Serial.print('L');
    if (input & 0b00001000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input & 0b00010000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input & 0b00100000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input & 0b01000000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input & 0b10000000)
      Serial.print('H');
    else
      Serial.print('L');


input = 0;

    if (input1 & 0b00000001)
      Serial.print('H');
    else
      Serial.print('L');
      //Serial.print(input);
    if (input1 & 0b00000010)
      Serial.print('H');
    else
      Serial.print('L');
    if (input1 & 0b00000100)
      Serial.print('H');
    else
      Serial.print('L');
    if (input1 & 0b00001000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input1 & 0b00010000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input1 & 0b00100000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input1 & 0b01000000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input1 & 0b10000000)
      Serial.print('H');
    else
      Serial.print('L');


input1 = 0;


    if (input2 & 0b00000001)
      Serial.print('H');
    else
      Serial.print('L');
      //Serial.print(input);
    if (input2 & 0b00000010)
      Serial.print('H');
    else
      Serial.print('L');
    if (input2 & 0b00000100)
      Serial.print('H');
    else
      Serial.print('L');
    if (input2 & 0b00001000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input2 & 0b00010000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input2 & 0b00100000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input2 & 0b01000000)
      Serial.print('H');
    else
      Serial.print('L');
    if (input2 & 0b10000000)
      Serial.print('H');
    else
      Serial.print('L');




      
input2 = 0;
    //Serial.print(input);
    
    Serial.print('\n');
    
    //delay(10);
    
    delay(90);
 
}
