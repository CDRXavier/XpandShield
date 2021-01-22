#include <SPI.h>
#include <Wire.h>

#define BLACK 0   ///< Draw 'off' pixels
#define WHITE 1   ///< Draw 'on' pixels
#define INVERSE 2 ///< Invert pixels

#define OLED_DC     4  //4 is used as chip select for alternate spi mode. how about 9?
//#define OLED_CS     12
#define OLED_RESET  6

#define RED_LED   10
#define GREEN_LED 11
#define BLUE_LED  9

#define WIDTH 128
#define HEIGHT 64

#define WHITE 1
#define BLACK 0

static const unsigned char font[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
  0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
  0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
  0x18, 0x3C, 0x7E, 0x3C, 0x18,
  0x1C, 0x57, 0x7D, 0x57, 0x1C,
  0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
  0x00, 0x18, 0x3C, 0x18, 0x00,
  0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
  0x00, 0x18, 0x24, 0x18, 0x00,
  0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
  0x30, 0x48, 0x3A, 0x06, 0x0E,
  0x26, 0x29, 0x79, 0x29, 0x26,
  0x40, 0x7F, 0x05, 0x05, 0x07,
  0x40, 0x7F, 0x05, 0x25, 0x3F,
  0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
  0x7F, 0x3E, 0x1C, 0x1C, 0x08,
  0x08, 0x1C, 0x1C, 0x3E, 0x7F,
  0x14, 0x22, 0x7F, 0x22, 0x14,
  0x5F, 0x5F, 0x00, 0x5F, 0x5F,
  0x06, 0x09, 0x7F, 0x01, 0x7F,
  0x00, 0x66, 0x89, 0x95, 0x6A,
  0x60, 0x60, 0x60, 0x60, 0x60,
  0x94, 0xA2, 0xFF, 0xA2, 0x94,
  0x08, 0x04, 0x7E, 0x04, 0x08,
  0x10, 0x20, 0x7E, 0x20, 0x10,
  0x08, 0x08, 0x2A, 0x1C, 0x08,
  0x08, 0x1C, 0x2A, 0x08, 0x08,
  0x1E, 0x10, 0x10, 0x10, 0x10,
  0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
  0x30, 0x38, 0x3E, 0x38, 0x30,
  0x06, 0x0E, 0x3E, 0x0E, 0x06,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x5F, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x07, 0x00,
  0x14, 0x7F, 0x14, 0x7F, 0x14,
  0x24, 0x2A, 0x7F, 0x2A, 0x12,
  0x23, 0x13, 0x08, 0x64, 0x62,
  0x36, 0x49, 0x56, 0x20, 0x50,
  0x00, 0x08, 0x07, 0x03, 0x00,
  0x00, 0x1C, 0x22, 0x41, 0x00,
  0x00, 0x41, 0x22, 0x1C, 0x00,
  0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
  0x08, 0x08, 0x3E, 0x08, 0x08,
  0x00, 0x80, 0x70, 0x30, 0x00,
  0x08, 0x08, 0x08, 0x08, 0x08,
  0x00, 0x00, 0x60, 0x60, 0x00,
  0x20, 0x10, 0x08, 0x04, 0x02,
  0x3E, 0x51, 0x49, 0x45, 0x3E,
  0x00, 0x42, 0x7F, 0x40, 0x00,
  0x72, 0x49, 0x49, 0x49, 0x46,
  0x21, 0x41, 0x49, 0x4D, 0x33,
  0x18, 0x14, 0x12, 0x7F, 0x10,
  0x27, 0x45, 0x45, 0x45, 0x39,
  0x3C, 0x4A, 0x49, 0x49, 0x31,
  0x41, 0x21, 0x11, 0x09, 0x07,
  0x36, 0x49, 0x49, 0x49, 0x36,
  0x46, 0x49, 0x49, 0x29, 0x1E,
  0x00, 0x00, 0x14, 0x00, 0x00,
  0x00, 0x40, 0x34, 0x00, 0x00,
  0x00, 0x08, 0x14, 0x22, 0x41,
  0x14, 0x14, 0x14, 0x14, 0x14,
  0x00, 0x41, 0x22, 0x14, 0x08,
  0x02, 0x01, 0x59, 0x09, 0x06,
  0x3E, 0x41, 0x5D, 0x59, 0x4E,
  0x7C, 0x12, 0x11, 0x12, 0x7C,
  0x7F, 0x49, 0x49, 0x49, 0x36,
  0x3E, 0x41, 0x41, 0x41, 0x22,
  0x7F, 0x41, 0x41, 0x41, 0x3E,
  0x7F, 0x49, 0x49, 0x49, 0x41,
  0x7F, 0x09, 0x09, 0x09, 0x01,
  0x3E, 0x41, 0x41, 0x51, 0x73,
  0x7F, 0x08, 0x08, 0x08, 0x7F,
  0x00, 0x41, 0x7F, 0x41, 0x00,
  0x20, 0x40, 0x41, 0x3F, 0x01,
  0x7F, 0x08, 0x14, 0x22, 0x41,
  0x7F, 0x40, 0x40, 0x40, 0x40,
  0x7F, 0x02, 0x1C, 0x02, 0x7F,
  0x7F, 0x04, 0x08, 0x10, 0x7F,
  0x3E, 0x41, 0x41, 0x41, 0x3E,
  0x7F, 0x09, 0x09, 0x09, 0x06,
  0x3E, 0x41, 0x51, 0x21, 0x5E,
  0x7F, 0x09, 0x19, 0x29, 0x46,
  0x26, 0x49, 0x49, 0x49, 0x32,
  0x03, 0x01, 0x7F, 0x01, 0x03,
  0x3F, 0x40, 0x40, 0x40, 0x3F,
  0x1F, 0x20, 0x40, 0x20, 0x1F,
  0x3F, 0x40, 0x38, 0x40, 0x3F,
  0x63, 0x14, 0x08, 0x14, 0x63,
  0x03, 0x04, 0x78, 0x04, 0x03,
  0x61, 0x59, 0x49, 0x4D, 0x43,
  0x00, 0x7F, 0x41, 0x41, 0x41,
  0x02, 0x04, 0x08, 0x10, 0x20,
  0x00, 0x41, 0x41, 0x41, 0x7F,
  0x04, 0x02, 0x01, 0x02, 0x04,
  0x40, 0x40, 0x40, 0x40, 0x40,
  0x00, 0x03, 0x07, 0x08, 0x00,
  0x20, 0x54, 0x54, 0x78, 0x40,
  0x7F, 0x28, 0x44, 0x44, 0x38,
  0x38, 0x44, 0x44, 0x44, 0x28,
  0x38, 0x44, 0x44, 0x28, 0x7F,
  0x38, 0x54, 0x54, 0x54, 0x18,
  0x00, 0x08, 0x7E, 0x09, 0x02,
  0x18, 0xA4, 0xA4, 0x9C, 0x78,
  0x7F, 0x08, 0x04, 0x04, 0x78,
  0x00, 0x44, 0x7D, 0x40, 0x00,
  0x20, 0x40, 0x40, 0x3D, 0x00,
  0x7F, 0x10, 0x28, 0x44, 0x00,
  0x00, 0x41, 0x7F, 0x40, 0x00,
  0x7C, 0x04, 0x78, 0x04, 0x78,
  0x7C, 0x08, 0x04, 0x04, 0x78,
  0x38, 0x44, 0x44, 0x44, 0x38,
  0xFC, 0x18, 0x24, 0x24, 0x18,
  0x18, 0x24, 0x24, 0x18, 0xFC,
  0x7C, 0x08, 0x04, 0x04, 0x08,
  0x48, 0x54, 0x54, 0x54, 0x24,
  0x04, 0x04, 0x3F, 0x44, 0x24,
  0x3C, 0x40, 0x40, 0x20, 0x7C,
  0x1C, 0x20, 0x40, 0x20, 0x1C,
  0x3C, 0x40, 0x30, 0x40, 0x3C,
  0x44, 0x28, 0x10, 0x28, 0x44,
  0x4C, 0x90, 0x90, 0x90, 0x7C,
  0x44, 0x64, 0x54, 0x4C, 0x44,
  0x00, 0x08, 0x36, 0x41, 0x00,
  0x00, 0x00, 0x77, 0x00, 0x00,
  0x00, 0x41, 0x36, 0x08, 0x00,
  0x02, 0x01, 0x02, 0x04, 0x02,
  0x3C, 0x26, 0x23, 0x26, 0x3C,
  0x1E, 0xA1, 0xA1, 0x61, 0x12,
  0x3A, 0x40, 0x40, 0x20, 0x7A,
  0x38, 0x54, 0x54, 0x55, 0x59,
  0x21, 0x55, 0x55, 0x79, 0x41,
  0x21, 0x54, 0x54, 0x78, 0x41,
  0x21, 0x55, 0x54, 0x78, 0x40,
  0x20, 0x54, 0x55, 0x79, 0x40,
  0x0C, 0x1E, 0x52, 0x72, 0x12,
  0x39, 0x55, 0x55, 0x55, 0x59,
  0x39, 0x54, 0x54, 0x54, 0x59,
  0x39, 0x55, 0x54, 0x54, 0x58,
  0x00, 0x00, 0x45, 0x7C, 0x41,
  0x00, 0x02, 0x45, 0x7D, 0x42,
  0x00, 0x01, 0x45, 0x7C, 0x40,
  0xF0, 0x29, 0x24, 0x29, 0xF0,
  0xF0, 0x28, 0x25, 0x28, 0xF0,
  0x7C, 0x54, 0x55, 0x45, 0x00,
  0x20, 0x54, 0x54, 0x7C, 0x54,
  0x7C, 0x0A, 0x09, 0x7F, 0x49,
  0x32, 0x49, 0x49, 0x49, 0x32,
  0x32, 0x48, 0x48, 0x48, 0x32,
  0x32, 0x4A, 0x48, 0x48, 0x30,
  0x3A, 0x41, 0x41, 0x21, 0x7A,
  0x3A, 0x42, 0x40, 0x20, 0x78,
  0x00, 0x9D, 0xA0, 0xA0, 0x7D,
  0x39, 0x44, 0x44, 0x44, 0x39,
  0x3D, 0x40, 0x40, 0x40, 0x3D,
  0x3C, 0x24, 0xFF, 0x24, 0x24,
  0x48, 0x7E, 0x49, 0x43, 0x66,
  0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
  0xFF, 0x09, 0x29, 0xF6, 0x20,
  0xC0, 0x88, 0x7E, 0x09, 0x03,
  0x20, 0x54, 0x54, 0x79, 0x41,
  0x00, 0x00, 0x44, 0x7D, 0x41,
  0x30, 0x48, 0x48, 0x4A, 0x32,
  0x38, 0x40, 0x40, 0x22, 0x7A,
  0x00, 0x7A, 0x0A, 0x0A, 0x72,
  0x7D, 0x0D, 0x19, 0x31, 0x7D,
  0x26, 0x29, 0x29, 0x2F, 0x28,
  0x26, 0x29, 0x29, 0x29, 0x26,
  0x30, 0x48, 0x4D, 0x40, 0x20,
  0x38, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x38,
  0x2F, 0x10, 0xC8, 0xAC, 0xBA,
  0x2F, 0x10, 0x28, 0x34, 0xFA,
  0x00, 0x00, 0x7B, 0x00, 0x00,
  0x08, 0x14, 0x2A, 0x14, 0x22,
  0x22, 0x14, 0x2A, 0x14, 0x08,
  0x95, 0x00, 0x22, 0x00, 0x95,
  0xAA, 0x00, 0x55, 0x00, 0xAA,
  0xAA, 0x55, 0xAA, 0x55, 0xAA,
  0x00, 0x00, 0x00, 0xFF, 0x00,
  0x10, 0x10, 0x10, 0xFF, 0x00,
  0x14, 0x14, 0x14, 0xFF, 0x00,
  0x10, 0x10, 0xFF, 0x00, 0xFF,
  0x10, 0x10, 0xF0, 0x10, 0xF0,
  0x14, 0x14, 0x14, 0xFC, 0x00,
  0x14, 0x14, 0xF7, 0x00, 0xFF,
  0x00, 0x00, 0xFF, 0x00, 0xFF,
  0x14, 0x14, 0xF4, 0x04, 0xFC,
  0x14, 0x14, 0x17, 0x10, 0x1F,
  0x10, 0x10, 0x1F, 0x10, 0x1F,
  0x14, 0x14, 0x14, 0x1F, 0x00,
  0x10, 0x10, 0x10, 0xF0, 0x00,
  0x00, 0x00, 0x00, 0x1F, 0x10,
  0x10, 0x10, 0x10, 0x1F, 0x10,
  0x10, 0x10, 0x10, 0xF0, 0x10,
  0x00, 0x00, 0x00, 0xFF, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0xFF, 0x10,
  0x00, 0x00, 0x00, 0xFF, 0x14,
  0x00, 0x00, 0xFF, 0x00, 0xFF,
  0x00, 0x00, 0x1F, 0x10, 0x17,
  0x00, 0x00, 0xFC, 0x04, 0xF4,
  0x14, 0x14, 0x17, 0x10, 0x17,
  0x14, 0x14, 0xF4, 0x04, 0xF4,
  0x00, 0x00, 0xFF, 0x00, 0xF7,
  0x14, 0x14, 0x14, 0x14, 0x14,
  0x14, 0x14, 0xF7, 0x00, 0xF7,
  0x14, 0x14, 0x14, 0x17, 0x14,
  0x10, 0x10, 0x1F, 0x10, 0x1F,
  0x14, 0x14, 0x14, 0xF4, 0x14,
  0x10, 0x10, 0xF0, 0x10, 0xF0,
  0x00, 0x00, 0x1F, 0x10, 0x1F,
  0x00, 0x00, 0x00, 0x1F, 0x14,
  0x00, 0x00, 0x00, 0xFC, 0x14,
  0x00, 0x00, 0xF0, 0x10, 0xF0,
  0x10, 0x10, 0xFF, 0x10, 0xFF,
  0x14, 0x14, 0x14, 0xFF, 0x14,
  0x10, 0x10, 0x10, 0x1F, 0x00,
  0x00, 0x00, 0x00, 0xF0, 0x10,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
  0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0xFF,
  0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
  0x38, 0x44, 0x44, 0x38, 0x44,
  0x7C, 0x2A, 0x2A, 0x3E, 0x14,
  0x7E, 0x02, 0x02, 0x06, 0x06,
  0x02, 0x7E, 0x02, 0x7E, 0x02,
  0x63, 0x55, 0x49, 0x41, 0x63,
  0x38, 0x44, 0x44, 0x3C, 0x04,
  0x40, 0x7E, 0x20, 0x1E, 0x20,
  0x06, 0x02, 0x7E, 0x02, 0x02,
  0x99, 0xA5, 0xE7, 0xA5, 0x99,
  0x1C, 0x2A, 0x49, 0x2A, 0x1C,
  0x4C, 0x72, 0x01, 0x72, 0x4C,
  0x30, 0x4A, 0x4D, 0x4D, 0x30,
  0x30, 0x48, 0x78, 0x48, 0x30,
  0xBC, 0x62, 0x5A, 0x46, 0x3D,
  0x3E, 0x49, 0x49, 0x49, 0x00,
  0x7E, 0x01, 0x01, 0x01, 0x7E,
  0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
  0x44, 0x44, 0x5F, 0x44, 0x44,
  0x40, 0x51, 0x4A, 0x44, 0x40,
  0x40, 0x44, 0x4A, 0x51, 0x40,
  0x00, 0x00, 0xFF, 0x01, 0x03,
  0xE0, 0x80, 0xFF, 0x00, 0x00,
  0x08, 0x08, 0x6B, 0x6B, 0x08,
  0x36, 0x12, 0x36, 0x24, 0x36,
  0x06, 0x0F, 0x09, 0x0F, 0x06,
  0x00, 0x00, 0x18, 0x18, 0x00,
  0x00, 0x00, 0x10, 0x10, 0x00,
  0x30, 0x40, 0xFF, 0x01, 0x01,
  0x00, 0x1F, 0x01, 0x01, 0x1E,
  0x00, 0x19, 0x1D, 0x17, 0x12,
  0x00, 0x3C, 0x3C, 0x3C, 0x3C,
  0x00, 0x00, 0x00, 0x00, 0x00,
};




/*************************
        SPLASH
**************************/

#define splash2_width 115
#define splash2_height 32

const uint8_t PROGMEM splash2_data[] = {
  B00000000, B00000000, B01100000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B11100000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000001, B11100000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000001, B11110000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, B11110000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000111,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000111, B11111000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00001111, B11111000, B00000000, B00000000, B00000000, B00000011,
  B11000000, B00000000, B01111110, B00000000, B00000000, B00000001, B11100000,
  B00000000, B01111111, B00001111, B11111000, B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000, B11111110, B00000000, B00000000, B00000001,
  B11100000, B00000000, B11111111, B11101111, B11111000, B00000000, B00000000,
  B00000000, B00000011, B11000000, B00000000, B11111110, B00000000, B00000000,
  B00000001, B11100000, B00000000, B11111111, B11111111, B11111000, B00000000,
  B00000000, B00000000, B00000011, B11000000, B00000000, B11110000, B00000000,
  B00000000, B00000000, B00001111, B00000000, B01111111, B11111110, B01111111,
  B11000000, B00000000, B00000000, B00000011, B11000000, B00000000, B11110000,
  B00000000, B00000000, B00000000, B00001111, B00000000, B00111111, B11111110,
  B01111111, B11111000, B00111111, B11110001, B11111011, B11001111, B11111100,
  B11111110, B11110011, B10111100, B00111101, B11101111, B11100000, B00011111,
  B11111110, B01111111, B11111111, B01111111, B11111011, B11111111, B11011111,
  B11111110, B11111110, B11111111, B10111100, B00111101, B11101111, B11100000,
  B00011111, B11000110, B11111111, B11111111, B01111111, B11111011, B11111111,
  B11011111, B11111110, B11111110, B11111111, B10111100, B00111101, B11101111,
  B11100000, B00001111, B11100011, B11000111, B11111110, B01111000, B01111011,
  B11000011, B11011110, B00011110, B11110000, B11111111, B10111100, B00111101,
  B11101111, B00000000, B00000111, B11111111, B10000111, B11111100, B01111000,
  B01111011, B11000011, B11011110, B00011110, B11110000, B11111000, B00111100,
  B00111101, B11101111, B00000000, B00000001, B11111111, B11111111, B11110000,
  B00000000, B01111011, B11000011, B11000000, B00011110, B11110000, B11110000,
  B00111100, B00111101, B11101111, B00000000, B00000001, B11110011, B01111111,
  B11100000, B00111111, B11111011, B11000011, B11001111, B11111110, B11110000,
  B11110000, B00111100, B00111101, B11101111, B00000000, B00000011, B11100011,
  B00111111, B10000000, B01111111, B11111011, B11000011, B11011111, B11111110,
  B11110000, B11110000, B00111100, B00111101, B11101111, B00000000, B00000111,
  B11100111, B00111100, B00000000, B01111000, B01111011, B11000011, B11011110,
  B00011110, B11110000, B11110000, B00111100, B00111101, B11101111, B00000000,
  B00000111, B11111111, B10111110, B00000000, B01111000, B01111011, B11000011,
  B11011110, B00011110, B11110000, B11110000, B00111100, B00111101, B11101111,
  B00000000, B00000111, B11111111, B11111110, B00000000, B01111000, B01111011,
  B11000011, B11011110, B00011110, B11110000, B11110000, B00111100, B00111101,
  B11101111, B00000000, B00001111, B11111111, B11111110, B00000000, B01111111,
  B11111011, B11111111, B11011111, B11111110, B11110000, B11110000, B00111111,
  B11111101, B11101111, B11100000, B00001111, B11111111, B11111111, B00000000,
  B01111111, B11111011, B11111111, B11011111, B11111110, B11110000, B11110000,
  B00111111, B11111101, B11101111, B11100000, B00001111, B11111001, B11111111,
  B00000000, B00111110, B01111001, B11111001, B11001111, B10011110, B11110000,
  B11110000, B00011111, B00111101, B11100111, B11100000, B00011111, B11110001,
  B11111111, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00011111,
  B10000000, B11111111, B00000000, B01111111, B11111111, B11111111, B11111111,
  B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11100000,
  B00011100, B00000000, B01111111, B00000000, B01111111, B11111111, B11111111,
  B11111111, B11111110, B10110100, B01101101, B10001000, B10001101, B00011000,
  B11100000, B00000000, B00000000, B00011111, B00000000, B01111111, B11111111,
  B11111111, B11111111, B11111110, B10010101, B10101101, B01111101, B10110101,
  B01110111, B11100000, B00000000, B00000000, B00001111, B00000000, B01111111,
  B11111111, B11111111, B11111111, B11111110, B10100101, B10101101, B10011101,
  B10001101, B00011001, B11100000, B00000000, B00000000, B00000110, B00000000,
  B01111111, B11111111, B11111111, B11111111, B11111110, B10110101, B10101101,
  B11101101, B10110101, B01111110, B11100000,
};

///////////////////////////////
//          HARDWARE
///////////////////////////////

SPISettings spiSettings = SPISettings(8000000UL, MSBFIRST, SPI_MODE0);

//#define SSD1306_SELECT digitalWrite(OLED_CS, LOW);       ///< Device select
//#define SSD1306_DESELECT digitalWrite(OLED_CS, HIGH);    ///< Device deselect
#define SSD1306_MODE_COMMAND digitalWrite(OLED_DC, LOW); ///< Command mode
#define SSD1306_MODE_DATA digitalWrite(OLED_DC, HIGH);   ///< Data mode



#define SPI_TRANSACTION_START SPI.beginTransaction(spiSettings) ///< Pre-SPI
#define SPI_TRANSACTION_END SPI.endTransaction()                ///< Post-SPI


uint8_t *buffer;
uint8_t contrast; // normal contrast setting for this device
int rotation = 0;


void LCDBootProgram() {
  // Reset SSD1306
  //pinMode(OLED_RESET, OUTPUT);
  digitalWrite(OLED_RESET, HIGH);
  delay(1);                       // VDD goes high at start, pause for 1 ms
  digitalWrite(OLED_RESET, LOW);  // Bring reset low
  delay(10);                      // Wait 10 ms
  digitalWrite(OLED_RESET, HIGH); // Bring out of reset


  SPI.begin();
  SPI.beginTransaction(spiSettings);
  SSD1306_MODE_COMMAND

  // Init sequence
  SPI.transfer(0xAE);//SSD1306_DISPLAYOFF
  SPI.transfer(0xD5);//SSD1306_SETDISPLAYCLOCKDIV
  SPI.transfer(0x80);// the suggested ratio 0x80
  SPI.transfer(0xA8);//SSD1306_SETMULTIPLEX
  SPI.transfer(HEIGHT - 1); //set multiplex ratio

  SPI.transfer(0xD3); //SSD1306_SETDISPLAYOFFSET,
  SPI.transfer(0x0);  // no offset
  SPI.transfer(0x40 | 0x0); //SSD1306_SETSTARTLINE | line #0
  SPI.transfer(0x8D); //SSD1306_CHARGEPUMP
  SPI.transfer(0x14);  // Charge Pump Setting enable


  SPI.transfer(0x20); //SSD1306_MEMORYMODE
  SPI.transfer(0x00); // 0x0 act like ks0108
  SPI.transfer(0xA0 | 0x1); //SSD1306_SEGREMAP | 0x1
  SPI.transfer(0xC8); //SSD1306_COMSCANDEC

  SPI.transfer(0xDA); //SSD1306_SETCOMPINS
  SPI.transfer(0x12);
  SPI.transfer(0x81); //SSD1306_SETCONTRAST
  SPI.transfer(0xCF);
  SPI.transfer(0xD9); //SSD1306_SETPRECHARGE
  SPI.transfer(0xF1);

  SPI.transfer(0xDB);//SSD1306_SETVCOMDETECT
  SPI.transfer(0x40);
  SPI.transfer(0xA4);//SSD1306_DISPLAYALLON_RESUME
  SPI.transfer(0xA6);//SSD1306_NORMALDISPLAY
  SPI.transfer(0x2E);//SSD1306_DEACTIVATE_SCROLL
  SPI.transfer(0xAF);//SSD1306_DISPLAYON
  SPI.endTransaction();
  clearDisplay();

}

void drawPixel(int16_t x, int16_t y, uint16_t color) {
  if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)) {
    switch (color) {
      case WHITE:
        buffer[x + (y / 8) * WIDTH] |= (1 << (y & 7));
        break;
      case BLACK:
        buffer[x + (y / 8) * WIDTH] &= ~(1 << (y & 7));
        break;
      case INVERSE:
        buffer[x + (y / 8) * WIDTH] ^= (1 << (y & 7));
        break;
    }
  }
}

void clearDisplay(void) {
  memset(buffer, 0, WIDTH * ((HEIGHT + 7) / 8));
}
/*!
    @brief  Push data currently in RAM to SSD1306 display.
    @return None (void).
    @note   Drawing operations are not visible until this function is
            called. Call after each graphics command, or after a whole set
            of graphics commands, as best needed by one's own application.
*/
void display(void) {
  SSD1306_MODE_COMMAND
  SPI.beginTransaction(spiSettings);
  SPI.transfer(0x22); //SSD_1306_PAGEADDR
  SPI.transfer(0);   // Page start address
  SPI.transfer(0xFF);   // Page end (not really, but works here)
  SPI.transfer(0x21);//SSD1306_COLUMNADDR
  SPI.transfer(0); // Column start address
  SPI.transfer(WIDTH - 1); // Column end address

  uint16_t count = WIDTH * ((HEIGHT + 7) / 8);
  uint8_t *ptr = buffer;
  //SPI_TRANSACTION_END;
  SSD1306_MODE_DATA
  //SPI_TRANSACTION_START;

  // SPI
  while (count--)
    SPI.transfer(*ptr++);
  SPI.endTransaction();
}

void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color) {

  int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
  uint8_t byte = 0;

  //startWrite();
  for (int16_t j = 0; j < h; j++, y++) {
    for (int16_t i = 0; i < w; i++) {
      if (i & 7)
        byte <<= 1;
      else
        byte = pgm_read_byte(&bitmap[j * byteWidth + i / 8]);
      if (byte & 0x80)
        drawPixel(x + i, y, color);
    }
  }
  //endWrite();
}


uint8_t buttonsreg = 0b00000000;
//      buttonsreg 0b00UDLRAB
uint8_t prevbuttons;
int16_t cursor_x;
int16_t cursor_y;
#define UP_BUTTON 0x16
#define DOWN_BUTTON 0x17
#define LEFT_BUTTON 0x18
#define RIGHT_BUTTON 0x19
#define A_BUTTON 0x20
#define B_BUTTON 0x21

void pollButtons()
{
  prevbuttons = buttonsreg;
  if (digitalRead(A0) == LOW) //U
    buttonsreg |= 0b00100000;
  // buttonsreg 0b00UDLRAB
  else
    buttonsreg &= 0b00011111;
  if (digitalRead(A1) == LOW) //R
    buttonsreg |= 0b00000100;
  // buttonsreg 0b00UDLRAB
  else
    buttonsreg &= 0b00111011;
  if (digitalRead(A2) == LOW) //L
    buttonsreg |= 0b00001000;
  // buttonsreg 0b00UDLRAB
  else
    buttonsreg &= 0b00110111;
  if (digitalRead(A3) == LOW) //D
    buttonsreg |= 0b00010000;
  // buttonsreg 0b00UDLRAB
  else
    buttonsreg &= 0b00101111;
  if (digitalRead(7) == LOW) //A
    buttonsreg |= 0b00000010;
  // buttonsreg 0b00UDLRAB
  else
    buttonsreg &= 0b00111101;
  if (digitalRead(8) == LOW) //B
    buttonsreg |= 0b00000001;
  // buttonsreg 0b00UDLRAB
  else
    buttonsreg &= 0b00111110;
}

/******************************************************************************************

     AA   RRRRRR DDDD   U    U  III  NN    N  OOOO        CCCC   OOOO  DDDD   EEEEEE
    A  A  R    R D   D  U    U   I   N N   N O    O      C    C O    O D   D  E
   A    A RRRRRR D    D U    U   I   N  N  N O    O      C      O    O D    D EEEEE
   AAAAAA R   R  D   D  U    U   I   N   N N O    O      C    C O    O D   D  E
   A    A R    R DDDD    UUUU   III  N    NN  OOOO        CCCC   OOOO  DDDD   EEEEEE

******************************************************************************************/

bool justPressed(int8_t butn)
{
  switch (butn) {
    case UP_BUTTON:
      return ((buttonsreg & 0b00100000) && !(prevbuttons & 0b00100000));
    case DOWN_BUTTON:
      return ((buttonsreg & 0b00010000) && !(prevbuttons & 0b00010000));
    case LEFT_BUTTON:
      return ((buttonsreg & 0b00001000) && !(prevbuttons & 0b00001000));
    case RIGHT_BUTTON:
      return ((buttonsreg & 0b00000100) && !(prevbuttons & 0b00000100));
    case A_BUTTON:
      return ((buttonsreg & 0b00000010) && !(prevbuttons & 0b00000010));
    case B_BUTTON:
      return ((buttonsreg & 0b00000001) && !(prevbuttons & 0b00000001));
  }
}

bool pressed(int8_t buttn)
{
  switch (buttn) {
    case UP_BUTTON:
      return (buttonsreg & 0b00100000) != 0;
    case DOWN_BUTTON:
      return (buttonsreg & 0b00010000) != 0;
    case LEFT_BUTTON:
      return (buttonsreg & 0b00001000) != 0;
    case RIGHT_BUTTON:
      return (buttonsreg & 0b00000100) != 0;
    case A_BUTTON:
      return (buttonsreg & 0b00000010) != 0;
    case B_BUTTON:
      return (buttonsreg & 0b00000001) != 0;
  }
}


unsigned long lastFrameStart;
unsigned long nextFrameStart;
bool justRendered;
uint8_t lastFrameDurationMs;
uint16_t frameCount;

bool nextFrame(unsigned short rate)
{
  unsigned long now = millis();
  bool tooSoonForNextFrame = now < nextFrameStart;

  if (justRendered) {
    lastFrameDurationMs = now - lastFrameStart;
    justRendered = false;
    return false;
  }
  else if (tooSoonForNextFrame) {
    if ((uint8_t)(nextFrameStart - now) > 1)
      delay(1);
    return false;
  }

  // pre-render
  justRendered = true;
  lastFrameStart = now;
  nextFrameStart = now + rate;
  frameCount++;

  return true;
}

bool perXFrame(uint8_t rate)
{
  if (frameCount > rate) {
    frameCount = 0;
    return true;
  }
  return false;
}

int8_t drawChar(int16_t x, int16_t y, char c, uint8_t color)
{
  uint8_t line;
  for (int8_t i = 0; i < 5; i++ ) {
    line = pgm_read_byte(font + (c * 5) + i);
    for (int8_t j = 0; j < 8; j++) {
      if (line & 0x1)
        //for (uint8_t a = 0; a < size; a++ ) {
        //for (uint8_t b = 0; b < size; b++ ) {
        drawPixel(x + i, y + j, color);
      //}
      //}

      line >>= 1;
    }
  }
  return 0;
}
int8_t write(char assds, uint8_t color) {
  if (assds != '\0') {
    drawChar(cursor_x, cursor_y, assds, color);
    cursor_x += 6;
  }
}
int8_t print(char *bufr, uint8_t color)
{
  do {
    //write(*bufr, color);
    if (*bufr == '\n') {
      cursor_y += 8;
      cursor_x = 0;
    } else if (*bufr == '\r') {
      //cursor_y += 8;
      //cursor_x = 0;
    }// else if (*bufr == '\0')
    //return 0;
    else {
      write(*bufr, color);
    }
    ++bufr;
  } while (*bufr != '\0');
  return 0;
}

int8_t printNum(unsigned long n, uint8_t color)
{
  char buf[sizeof(int16_t) + 1]; // Assumes 8-bit chars plus zero byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0'; //null terminated string

  // prevent crash if called with base == 1
  //if (base < 2) base = 10;
  do {
    char c = n % 10;
    n /= 10;
    --str;
    *str = c < 10 ? c + '0' : c + 'A' - 10;

  } while (n);
  return print(buf, color);
}

int8_t printFlt(float number, uint8_t digits, int8_t color)
{
  int8_t n = 0;

  //if (isnan(number)) return print("nan");
  //if (isinf(number)) return print("inf");
  //if (number > 4294967040.0) return print ("ovf");  // constant determined empirically
  //if (number <-4294967040.0) return print ("ovf");  // constant determined empirically

  // Handle negative numbers
  if (number < 0.0) {
    n += write('-', color);
    number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  //double rounding = 0.5;
  //for (uint8_t i=0; i<digits; ++i)
  //  rounding /= 10.0;

  //number += rounding;

  // Extract the integer part of the number and print it
  int int_part = (int)number;
  float remainder = number - (float)int_part;
  n += printNum(int_part, color);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
    n += write('.', color);
  }

  // Extract digits from the remainder one at a time
  unsigned short toPrint;
  //while(--digits > 0)
    //remainder *= 10.0;
    //
    //remainder -= toPrint;
    //--digits;
  
  toPrint = (unsigned short)(remainder);
  n += printNum(toPrint, color);
  return n;
}

void setCursor(int16_t x, int16_t y)
{
  cursor_x = x;
  cursor_y = y;
}

void setRGBled(uint8_t red, uint8_t green, uint8_t blue)
{
  // inversion is necessary because these are common annode LEDs
  analogWrite(RED_LED, 255 - red);
  analogWrite(GREEN_LED, 255 - green);
  analogWrite(BLUE_LED, 255 - blue);
}

///////////////////////////////////////////////////
//         M   M  AAA  IIIII NN   N
//         MM MM A   A   I   N N  N
//         M M M AAAAA   I   N  N N
//         M   M A   A   I   N   NN
//         M   M A   A IIIII N    N
///////////////////////////////////////////////////
short x;
short y;
short choice;
short choicer;
bool indec;
bool rep;
bool datarewrewer;
bool refresh;
short temp;
short tempC;
short hum;

#define addr 0x44

void setup() {
  if ((!buffer) && !(buffer = (uint8_t *)malloc(WIDTH * ((HEIGHT + 7) / 8))))
    return;
  // Using one of the SPI modes, either soft or hardware
  pinMode(OLED_DC, OUTPUT); // Set data/command pin as output
  //pinMode(OLED_CS, OUTPUT); // Same for chip select
  pinMode(OLED_RESET, OUTPUT); // Same for reset
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  LCDBootProgram();

  setRGBled(240, 0, 0);
  delay(500);
  setRGBled(0, 240, 0);
  delay(500);
  setRGBled(0, 0, 240);
  delay(500);
  setRGBled(0, 0, 0);
  drawBitmap((WIDTH - splash2_width) / 2, (HEIGHT - splash2_height) / 2, splash2_data, splash2_width, splash2_height, 1);
  display();
  delay(5000);

  lastFrameStart = 0;
  nextFrameStart = 0;
  justRendered = false;
  lastFrameDurationMs = 0;

  choice = 0;
  indec = false;
  choicer = 0;
  datarewrewer = false;
  refresh = false;
  temp = 0;
  tempC = 0;
  hum = 0;
  x = 0;
  y = 0;
  Wire.begin();
  //Serial.begin(9600);
}

void loop() {
  //time for each frame (in millis)
  if (nextFrame(100)) {
    //***********************************
    //*           BEGIN INTERFACE
    //************************************/
    if (!rep) {
      if (justPressed(UP_BUTTON)) {
        if (indec)
          choicer++;
        else
          choice++;
      }
      if (justPressed(DOWN_BUTTON)) {
        if (indec)
          choicer--;
        else
          choice--;
      }
      if (justPressed(RIGHT_BUTTON)) {
        if (choice != 0)
          indec = true;

      }
      if (justPressed(LEFT_BUTTON)) {
        indec = false;
        choicer = 0;
      }
      if (choice < 0)
        choice = 0;
      if (choice > 4)
        choice = 4;
    }
    clearDisplay();

    if (rep) {
      setCursor(20, 20);
      print("stop\0", WHITE);
    }
    else {
      setCursor(20, 20);
      print("1 shot\0", WHITE);
      setCursor(20, 30);
      print("multi.\0", WHITE);
      setCursor(20, 40);
      print("s. rst\0", WHITE);
      setCursor(20, 50);
      print("t.heat\0", WHITE);
      if (indec)
        switch (choice) {
          case 1:
          case 2:
            setCursor(64, 20);
            print("low rep\0", WHITE);
            setCursor(64, 30);
            print("med rep\0", WHITE);
            setCursor(64, 40);
            print("high rep\0", WHITE);
            if (choicer < 0)
              choicer = 0;
            if (choicer > 2)
              choicer = 2;
            break;
          case 3:
            setCursor(64, 20);
            print("no\0", WHITE);
            setCursor(64, 30);
            print("yes\0", WHITE);
            if (choicer < 3)
              choicer = 3;
            if (choicer > 4)
              choicer = 4;
            break;
          case 4:
            setCursor(64, 20);
            print("on\0", WHITE);
            setCursor(64, 30);
            print("off\0", WHITE);
            if (choicer < 5)
              choicer = 5;
            if (choicer > 6)
              choicer = 6;
        }

    }
    setCursor(0, 0);
    print("t\0", WHITE);
    setCursor(18, 0);
    printNum(temp/10, WHITE);
    write('.', WHITE);
    printNum(temp%10, WHITE);
    setCursor(52, 0);
    printNum(tempC/10, WHITE);
    write('.', WHITE);
    printNum(tempC%10, WHITE);
    setCursor(80, 0);
    print("hum\0", WHITE);
    setCursor(102, 0);
    printNum(hum, WHITE);
    write('%', WHITE);
    //printNum((hum) - (hum * 100), WHITE);
    //setCursor(100, 50);
    //printFlt(0.234, 1, WHITE);
    //setCursor(112, 50);
    //printNum(choicer, WHITE);

    switch (choice) {
      case 0:
        drawPixel(10, 10, WHITE);
        drawPixel(10, 11, WHITE);
        drawPixel(11, 10, WHITE);
        drawPixel(11, 11, WHITE);
        break;
      case 1:

        drawPixel(10, 20, WHITE);
        drawPixel(10, 21, WHITE);
        drawPixel(11, 20, WHITE);
        drawPixel(11, 21, WHITE);
        break;
      case 2:
        drawPixel(10, 30, WHITE);
        drawPixel(11, 30, WHITE);
        drawPixel(10, 31, WHITE);
        drawPixel(11, 31, WHITE);
        break;
      case 3:
        drawPixel(10, 40, WHITE);
        drawPixel(11, 40, WHITE);
        drawPixel(10, 41, WHITE);
        drawPixel(11, 41, WHITE);
        break;
      case 4:
        drawPixel(10, 50, WHITE);
        drawPixel(11, 50, WHITE);
        drawPixel(10, 51, WHITE);
        drawPixel(11, 51, WHITE);
    }
    if (indec)
      switch (choicer) {
        case 0:
        case 3:
        case 5:
          drawPixel(57, 20, WHITE);
          drawPixel(57, 21, WHITE);
          drawPixel(58, 20, WHITE);
          drawPixel(58, 21, WHITE);
          break;
        case 1:
        case 4:
        case 6:
          drawPixel(57, 30, WHITE);
          drawPixel(58, 30, WHITE);
          drawPixel(57, 31, WHITE);
          drawPixel(58, 31, WHITE);
          break;
        case 2:
          drawPixel(57, 40, WHITE);
          drawPixel(58, 40, WHITE);
          drawPixel(57, 41, WHITE);
          drawPixel(58, 41, WHITE);
      }
    display();
    pollButtons();
    //***********************************
    //*           END INTERFACE
    //************************************
    if (justPressed(A_BUTTON)) {
      //***********************************
      //*           BEGIN COMMAND
      //***********************************
      if (rep) {
        //stop
        Wire.beginTransmission(byte(addr));
        Wire.write(byte(0x30));
        Wire.write(byte(0x93));
        Wire.endTransmission();
        //  //Serial.println("stopping repetition");
        rep = false;
      } else
      {
        Wire.beginTransmission(byte(addr));
        switch (choice) {
          case 1:
            //singleshot
            Wire.write(byte(0x24));
            //Serial.println("singleshot1");
            //Wire.write(byte(0x2C));
            //clock stretching is disabled for stability;
            switch (choicer) {
              case 0:
                //low rep
                Wire.write(byte(0x16));
                //Serial.println("ssl");
                break;
              case 1:
                //med rep
                Wire.write(byte(0x0B));
                //Serial.println("ssm");
                break;
              case 2:
                //high rep
                Wire.write(byte(0x00));
                //Serial.println("ssh");
                break;
            }

            //Wire.endTransmission();
            break;
          case 2:
            //periodic measure
            //Wire.beginTransmission(byte(addr));
            Wire.write(byte(0x21));
            //Serial.println("per");
            //0x20 0.5Hz
            //0x21 1Hz
            //0x22 2Hz
            //0x32 4Hz
            //0x27 10Hz
            //at highest frequency sensor might overheat
            switch (choicer) {
              case 0:
                //low rep
                Wire.write(byte(0x2D));
                //Serial.println("perl");
                break;
              case 1:
                //med rep
                Wire.write(byte(0x26));
                //Serial.println("perm");
                break;
              case 2:
                //high rep
                Wire.write(byte(0x30));
                //Serial.println("perh");
            }
            Wire.endTransmission();
            rep = true;
            break;
          case 3:
            //reset
            if (choicer == 4) {
              //reset
              //Wire.beginTransmission(byte(addr));
              Wire.write(byte(0x30));
              Wire.write(byte(0xA2));
              //Wire.endTransmission();
              //Serial.println("sftrst");
            }
            break;
          case 4:
            //Wire.beginTransmission(byte(addr));
            Wire.write(0x30);
            //Serial.println("heet");
            switch (choicer) {
              case 5:
                //heater enable
                Wire.write(0x6D);
                //Serial.println("heon");
                break;
              case 6:
                //heater disable
                Wire.write(0x66);
                //Serial.println("heof");
                break;
            }
        }
        Wire.endTransmission();
      }
      //***********************************
      //*           END COMMAND
      //***********************************
      //reset interface
      choice = 0;
      choicer = 0;
      indec = false;
    }
    if (perXFrame(5)) {
      //Serial.println("B");
      //every .5 second we check to see if there is bytes to be read
      Wire.beginTransmission(byte(addr));
      if (rep) {
        Wire.write(byte(0xE0));
        Wire.write(byte(0x00));
        //Wire.endTransmission();
      }
      //int8_t res = ;
      //Serial.println(res);
      if (Wire.requestFrom(byte(addr), 6, true))
        //if (false)
        datarewrewer = true;
      //Serial.print("true");}
      //else
      //Serial.print("false");
      //  datarewrewer = false;
      //if (datarewrewer == true)
      //Serial.println("true");
      //else
      //Serial.println("false");
      //Serial.print(rep);


    }
    if (datarewrewer) {
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
        tempC = 10 * (-45.0 + (175.0 * (static_cast<float>(e) / 65535.0)));
        //tempC = tempC * 10;
        //
        //Serial.println(tempC);
        temp = 10 * (-49.0 + (315.0 * (static_cast<float>(e) / 65535.0)));
        //temp = temp * 10;
        //Serial.println(temp);
        // print the number
      }

      if (Wire.available()) Wire.read(); // throw away that hash we don't need it rn
      //}

      if (Wire.available() > 1) {
        uint8_t c = Wire.read();    // receive a byte
        uint8_t d = Wire.read();    // receive a byte
        //Serial.println(c);
        //Serial.println(d);
        unsigned short e = (c << 8) | d;
        //Serial.println(e);         // print the number
        //from the datasheet: convert to value (0 for 0%, 1 for 100%)
        //e = (e * 100) / 65535;
        hum = 100 * static_cast<float>(e) / 65535.0;
        //hum = hum * 10;
        //arduboy.println(e);         // print the number
      }
      //}
      if (Wire.available()) Wire.read(); // throw away that hash we don't need it rn

      Wire.endTransmission();
      datarewrewer = false;
    }
    //***********************************
    //*            END READ
    //***********************************

  }
}
