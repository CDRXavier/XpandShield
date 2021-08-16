#include <SPI.h>
namespace XpandShield2 {

constexpr int8_t BLACK = 0;
constexpr int8_t WHITE = 1;
constexpr int8_t INVERSE = 2;

constexpr uint8_t UP_BUTTON =0x16;
constexpr uint8_t DOWN_BUTTON =0x17;
constexpr uint8_t LEFT_BUTTON =0x18;
constexpr uint8_t RIGHT_BUTTON= 0x19;
constexpr uint8_t A_BUTTON =0x1A;
constexpr uint8_t B_BUTTON =0x1B;
constexpr uint8_t C_BUTTON = 0x1C;
constexpr uint8_t X_BUTTON = 0x1D;
constexpr uint8_t Y_BUTTON = 0x1E;
constexpr uint8_t Z_BUTTON = 0x1F;
constexpr uint8_t START_BUTTON = 0x20;
constexpr uint8_t SELECT_BUTTON = 0x21;
constexpr uint8_t MENU_BUTTON = 0x22;
constexpr uint8_t L1_BUTTON = 0x23;
constexpr uint8_t R1_BUTTON = 0x24;
constexpr uint8_t L2_BUTTON = 0x25;
constexpr uint8_t R2_BUTTON = 0x26;
constexpr uint8_t STK_U_BUTTON = 0x27;
constexpr uint8_t STK_D_BUTTON = 0x28;
constexpr uint8_t STK_L_BUTTON = 0x29;
constexpr uint8_t STK_R_BUTTON = 0x2A;
constexpr uint8_t STK_S_BUTTON = 0x2B;
constexpr uint8_t C1_BUTTON = 0x2C;
constexpr uint8_t C2_BUTTON = 0x2D;


constexpr uint8_t OLED_DC   =  4;
constexpr uint8_t OLED_RESET = 6;
constexpr uint8_t OLED_CS   =  12;

constexpr uint8_t BUTN_CE = 10;
constexpr uint8_t BUTN_PL = 9;

constexpr uint8_t WIDTH =128;
constexpr uint8_t HEIGHT =64;


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

SPISettings spiSet = SPISettings(8000000UL, MSBFIRST, SPI_MODE0);
SPISettings spiSet2 = SPISettings(8000000UL, MSBFIRST, SPI_MODE0);

uint8_t *buffer;
uint8_t buttonsreg = 0b00000000;
//      buttonsreg   0bUDLRABSS
//      actually depend on the output from the registers
uint8_t buttonsreg1 = 0b00000000;
uint8_t buttonsreg2 = 0b00000000;
uint8_t prevbuttons;
uint8_t prevbuttons1;
uint8_t prevbuttons2;
int16_t cursor_x;
int16_t cursor_y;

void PInit
(void)
{
  pinMode(OLED_DC, OUTPUT); // Set data/command pin as output
  pinMode(OLED_CS, OUTPUT); // Same for chip select
  pinMode(OLED_RESET, OUTPUT); // Same for reset
  pinMode(BUTN_CE, OUTPUT);
  pinMode(BUTN_PL, OUTPUT);

  //pinMode(RED_LED, OUTPUT);
  //pinMode(GREEN_LED, OUTPUT);
  //pinMode(BLUE_LED, OUTPUT);
  //pinMode(7, INPUT_PULLUP);
  //pinMode(8, INPUT_PULLUP);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void LCDBoot
(void)
{
  // Reset SSD1306
  //pinMode(OLED_RESET, OUTPUT);
  digitalWrite(OLED_CS, LOW);
  digitalWrite(OLED_RESET, HIGH);
  delay(1);                       // VDD goes high at start, pause for 1 ms
  digitalWrite(OLED_RESET, LOW);  // Bring reset low
  delay(10);                      // Wait 10 ms
  digitalWrite(OLED_RESET, HIGH); // Bring out of reset


  SPI.begin();
  SPI.beginTransaction(spiSet);
digitalWrite(OLED_DC, LOW);

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
  digitalWrite(OLED_CS, HIGH);
}

void display(void) {
  digitalWrite(OLED_CS, LOW);
digitalWrite(OLED_DC, LOW);
  SPI.beginTransaction(spiSet);
  SPI.transfer(0x22); //SSD_1306_PAGEADDR
  SPI.transfer(0);   // Page start address
  SPI.transfer(0xFF);   // Page end (not really, but works here)
  SPI.transfer(0x21);//SSD1306_COLUMNADDR
  SPI.transfer(0); // Column start address
  SPI.transfer(WIDTH - 1); // Column end address

  uint16_t count = WIDTH * ((HEIGHT + 7) / 8);
  uint8_t *ptr = buffer;
  //SPI_TRANSACTION_END;
digitalWrite(OLED_DC, HIGH);
  //SPI_TRANSACTION_START;

  // SPI
  while (count--)
    SPI.transfer(*ptr++);
  digitalWrite(OLED_CS, HIGH);
  SPI.endTransaction();
}

void pollButtons
(void)
{
  prevbuttons = buttonsreg;
  prevbuttons1 = buttonsreg1;
  prevbuttons2 = buttonsreg2;
  digitalWrite(BUTN_PL, HIGH);
    //delay(10);
    //enable clock
    digitalWrite(BUTN_CE, LOW);
    //delay(1);
    SPI.beginTransaction(spiSet2);
    //digitalWrite(A2, HIGH);
    buttonsreg = SPI.transfer(0x00);
    buttonsreg1 = SPI.transfer(0x00);
    buttonsreg2 = SPI.transfer(0x00);
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
    
    //delay(1);
    digitalWrite(BUTN_CE, HIGH);
    digitalWrite(BUTN_PL, LOW);
}

void clearDisplay
(void)
{
  memset(buffer, 0, WIDTH * ((HEIGHT + 7) / 8));
}

void drawPixel
(int16_t x, int16_t y, int8_t color)
{
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

unsigned long lastFrameStart;
unsigned long nextFrameStart;
bool justRendered;
uint8_t lastFrameDurationMs;
uint16_t frameCount;
uint16_t frameDiff;


bool setFrameDiff
(uint16_t rate)
{
  frameDiff = rate;
}

bool nextFrame
(void)
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
  nextFrameStart = now + frameDiff;
  frameCount++;
  //if (frameCount > 20000)
    //frameCount = frameCount - 20000;
  return true;
}

//From Adafruit
void drawBitmap
(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, int8_t color)
{

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

void Startup
(void)
{
  if ((!buffer) && !(buffer = (uint8_t *)malloc(WIDTH * ((HEIGHT + 7) / 8))))
    return;

  PInit();
  digitalWrite(OLED_CS, LOW);
digitalWrite(BUTN_CE, HIGH);
digitalWrite(BUTN_PL, LOW);
  LCDBoot();
  clearDisplay();
  display();
  delay(500);
  drawBitmap((WIDTH - splash2_width) / 2,(HEIGHT - splash2_height) / 2,splash2_data,splash2_width,splash2_height, WHITE);
  display();
  digitalWrite(OLED_CS, HIGH);
  lastFrameStart = 0;
  nextFrameStart = 0;
  justRendered = false;
  lastFrameDurationMs = 0;
  delay(5000);
  
}

void drawHLine
(int16_t x, int16_t y, uint8_t w, int8_t color)
{
  int16_t end = x + w;
  for (int16_t a = max(0, x); a < min(end, WIDTH); a++)
    drawPixel(a, y, color);
}

void drawVLine
(int16_t x, int16_t y, uint8_t h, int8_t color)
{
  int16_t end = y + h;
  for (int16_t a = max(0, y); a < min(end, HEIGHT); a++)
    drawPixel(x, a, color);
}

void drawLine
(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color)
{
  // bresenham's algorithm - thx wikpedia
  boolean steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    int16_t temp = x0;
    x0 = y0;
    y0 = temp;
    temp = x1;
    x1 = y1;
    y1 = temp;
  }
  if (x0 > x1) {
    int16_t temp = x0;
    x0 = x1;
    x1 = temp;
    temp = y0;
    y0 = y1;
    y1 = temp;
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);
  int16_t err = dx >> 1;
  int8_t ystep;
  if (y0 < y1)
    ystep = 1;
  else
    ystep = -1;
  while (x0 <= x1) {
    if (steep)
      drawPixel(y0, x0, color);
    else
      drawPixel(x0, y0, color);
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
    x0++;
  }
}

void drawRect
(int16_t x, int16_t y, uint8_t w, uint8_t h, int8_t color)
{
  drawHLine(x, y, w, color);
  drawHLine(x, y + h - 1, w, color);
  drawVLine(x, y, h, color);
  drawVLine(x + w - 1, y, h, color);
}

void fillRect
(int16_t x, int16_t y, uint8_t w, uint8_t h, int8_t color)
{
  // stupidest version - update in subclasses if desired!
  for (int16_t i = x; i < x + w; i++)
    drawVLine(i, y, h, color);
}

void drawCircle
(int16_t x0, int16_t y0, uint8_t r, int8_t color)
{
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  drawPixel(x0, y0 + r, color);
  drawPixel(x0, y0 - r, color);
  drawPixel(x0 + r, y0, color);
  drawPixel(x0 - r, y0, color);

  while (x < y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }

    x++;
    ddF_x += 2;
    f += ddF_x;

    drawPixel(x0 + x, y0 + y, color);
    drawPixel(x0 - x, y0 + y, color);
    drawPixel(x0 + x, y0 - y, color);
    drawPixel(x0 - x, y0 - y, color);
    drawPixel(x0 + y, y0 + x, color);
    drawPixel(x0 - y, y0 + x, color);
    drawPixel(x0 + y, y0 - x, color);
    drawPixel(x0 - y, y0 - x, color);
  }
}




bool perXFrame
(uint8_t rate)
{
  if ((frameCount % rate) == 0)
    return true;
  return false;
}

int8_t drawChar
(int16_t x, int16_t y, char c, int8_t color)
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
int8_t write
(char assds, int8_t color)
{
  if (assds != '\0') {
    drawChar(cursor_x, cursor_y, assds, color);
    cursor_x += 6;
    return 0;
  }
  return 1;
}
int8_t print
(const char *bufr, int8_t color)
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

int8_t printNum
(unsigned int n, int8_t color)
{
  boolean FP = true;
  int TMP = n;
  int Digit = 1;
  while (FP) {
    TMP = TMP / 10;
    if (TMP > 0) {
      Digit = Digit + 1;
    } else {
      FP = false;
    }
  }
  char bufr[Digit + 1];

  char *str = &bufr[sizeof(bufr) - 1];

  *str = '\0'; //null terminated string

  // prevent crash if called with base == 1
  //if (base < 2) base = 10;
  do {
    char c = n % 10;
    n /= 10;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while (n);
  return print(bufr, color);
}

int8_t printFlt(float number, const uint8_t digits, const int8_t color)
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








bool justPressed
(int8_t butn)
{
  switch (butn) {
case DOWN_BUTTON:
return ((buttonsreg & 0b10000000) && !(prevbuttons & 0b10000000));
case LEFT_BUTTON:
return ((buttonsreg & 0b01000000) && !(prevbuttons & 0b01000000));
case RIGHT_BUTTON:
return ((buttonsreg & 0b00100000) && !(prevbuttons & 0b00100000));

case UP_BUTTON:
return ((buttonsreg & 0b00010000) && !(prevbuttons & 0b00010000));

case A_BUTTON:
return ((buttonsreg & 0b00001000) && !(prevbuttons & 0b00001000));
case X_BUTTON:
return ((buttonsreg & 0b00000100) && !(prevbuttons & 0b00000100));
case START_BUTTON:
return ((buttonsreg & 0b00000010) && !(prevbuttons & 0b00000010));
case SELECT_BUTTON:
return ((buttonsreg & 0b00000001) && !(prevbuttons & 0b00000001));

case Y_BUTTON:
return ((buttonsreg1 & 0b10000000) && !(prevbuttons1 & 0b10000000));
case Z_BUTTON:
return ((buttonsreg1 & 0b01000000) && !(prevbuttons1 & 0b01000000));
case B_BUTTON:
return ((buttonsreg1 & 0b00100000) && !(prevbuttons1 & 0b00100000));
case C_BUTTON:
return ((buttonsreg1 & 0b00010000) && !(prevbuttons1 & 0b00010000));
case L1_BUTTON:
return ((buttonsreg1 & 0b00001000) && !(prevbuttons1 & 0b00001000));
case L2_BUTTON:
return ((buttonsreg1 & 0b00000100) && !(prevbuttons1 & 0b00000100));
case R1_BUTTON:
return ((buttonsreg1 & 0b00000010) && !(prevbuttons1 & 0b00000010));
case R2_BUTTON:
return ((buttonsreg1 & 0b00000001) && !(prevbuttons1 & 0b00000001));


case C1_BUTTON:
return ((buttonsreg2 & 0b10000000) && !(prevbuttons2 & 0b10000000));
case C2_BUTTON:
return ((buttonsreg2 & 0b01000000) && !(prevbuttons2 & 0b01000000));
case MENU_BUTTON:
return ((buttonsreg2 & 0b00100000) && !(prevbuttons2 & 0b00100000));
case STK_S_BUTTON:
return ((buttonsreg2 & 0b00010000) && !(prevbuttons2 & 0b00010000));
case STK_R_BUTTON:
return ((buttonsreg2 & 0b00001000) && !(prevbuttons2 & 0b00001000));
case STK_L_BUTTON:
return ((buttonsreg2 & 0b00000100) && !(prevbuttons2 & 0b00000100));
case STK_U_BUTTON:
return ((buttonsreg2 & 0b00000010) && !(prevbuttons2 & 0b00000010));
case STK_D_BUTTON:
return ((buttonsreg2 & 0b00000001) && !(prevbuttons2 & 0b00000001));
  }
  return false;
}

bool pressed
(int8_t buttn)
{
  switch (buttn) {
case SELECT_BUTTON:
return ((buttonsreg & 0b10000000) != 0);
case START_BUTTON:
return ((buttonsreg & 0b01000000) != 0);
case X_BUTTON:
return ((buttonsreg & 0b00100000) != 0);
case A_BUTTON:
return ((buttonsreg & 0b00010000) != 0);
case UP_BUTTON:
return ((buttonsreg & 0b00001000) != 0);
case RIGHT_BUTTON:
return ((buttonsreg & 0b00000100) != 0);
case LEFT_BUTTON:
return ((buttonsreg & 0b00000010) != 0);
case DOWN_BUTTON:
return ((buttonsreg & 0b00000001) != 0);

case R2_BUTTON:
return ((buttonsreg1 & 0b10000000) != 0);
case R1_BUTTON:
return ((buttonsreg1 & 0b01000000) != 0);
case L2_BUTTON:
return ((buttonsreg1 & 0b00100000) != 0);
case L1_BUTTON:
return ((buttonsreg1 & 0b00010000) != 0);
case C_BUTTON:
return ((buttonsreg1 & 0b00001000) != 0);
case B_BUTTON:
return ((buttonsreg1 & 0b00000100) != 0);
case Z_BUTTON:
return ((buttonsreg1 & 0b00000010) != 0);
case Y_BUTTON:
return ((buttonsreg1 & 0b00000001) != 0);


case STK_U_BUTTON:
return ((buttonsreg2 & 0b10000000) != 0);
case STK_D_BUTTON:
return ((buttonsreg2 & 0b01000000) != 0);
case STK_L_BUTTON:
return ((buttonsreg2 & 0b00100000) != 0);
case STK_R_BUTTON:
return ((buttonsreg2 & 0b00010000) != 0);
case STK_S_BUTTON:
return ((buttonsreg2 & 0b00001000) != 0);
case MENU_BUTTON:
return ((buttonsreg2 & 0b00000100) != 0);
case C1_BUTTON:
return ((buttonsreg2 & 0b00000010) != 0);
case C2_BUTTON:
return ((buttonsreg2 & 0b00000001) != 0);


default:
return false;
  }
  return false;
}


}
