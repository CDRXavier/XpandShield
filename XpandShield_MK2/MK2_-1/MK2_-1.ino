#include <SPI.h>
SPISettings spiSettings = SPISettings(8000UL, MSBFIRST, SPI_MODE0);
uint8_t input;
void setup() {
  if (!Serial) delay(1);
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  delay(1000);


  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  
  SPI.begin();
  //async parallel load
  digitalWrite(13, LOW);
  //clock enable (active low)
  digitalWrite(4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    digitalWrite(13, HIGH);
    
    SPI.beginTransaction(spiSettings);
    digitalWrite(4, LOW);
    input = SPI.transfer(0x23);
    //delay(900);
    digitalWrite(4, HIGH);
    SPI.endTransaction();
    
    digitalWrite(13, LOW);
    //input = 0xFF;
//Serial.print(input);
    if ((input & 0b00000001) == 0b00000001)
      Serial.print('H');
    else
      Serial.print('L');
      //Serial.print(input);
    if ((input & 0b00000010)==0b00000010)
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

    //Serial.print(input);
    Serial.print('\n');
    
    //delay(10);
    
    delay(900);
 
}
