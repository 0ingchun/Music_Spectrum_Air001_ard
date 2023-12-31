#include "myws2812b.h"
#include "SPI.h"
#define CODE_1 (0xF8)
#define CODE_0 (0xC0)
uint8_t brightness = 50;
uint8_t bright_num = 5;
static uint8_t LED_MATRIX[64][3] = { 0 };

void myWs2812b::Writebit(uint8_t bit) {
  
  if (bit) {
    SPI.transfer(CODE_1);
  } else {
    SPI.transfer(CODE_0);
  }
}

void myWs2812b::WriteColor(uint8_t r, uint8_t g, uint8_t b) {
  for (uint8_t i = 0; i < 8; i++) {
    Writebit(g >> (7 - i));
  }
  for (uint8_t i = 0; i < 8; i++) {
    Writebit(r >> (7 - i));
  }
  for (uint8_t i = 0; i < 8; i++) {
    Writebit(b >> (7 - i));
  }
}
void myWs2812b::Show() {
  for (uint8_t i = 0; i < 64; i++) {
    WriteColor(LED_MATRIX[i][0], LED_MATRIX[i][1], LED_MATRIX[i][2]);
  }
  Reset();
}
void myWs2812b::Clear() {

  for (uint8_t i = 0; i < 64; i++) {
    LED_MATRIX[i][0] = 0;
    LED_MATRIX[i][1] = 0;
    LED_MATRIX[i][2] = 0;
    WriteColor(0, 0, 0);
  }
  Reset();
}
void myWs2812b::Reset() {
  for (int i = 0; i < 5; i++) {
    SPI.transfer(0);
  }
}
void myWs2812b::SetLedColor(uint8_t ledid, uint8_t r, uint8_t g, uint8_t b) {
  // 这里可以更改后面的数值调节亮度，不除的话，亮度比较高，发热比较严重
  LED_MATRIX[ledid][0] = r / bright_num;
  LED_MATRIX[ledid][1] = g / bright_num;
  LED_MATRIX[ledid][2] = b / bright_num;
  // LED_MATRIX[ledid][0] = r /5;
  // LED_MATRIX[ledid][1] = g /5;
  // LED_MATRIX[ledid][2] = b /5;
}


// void myWs2812b::SetLedColorBrightness(uint8_t ledid, uint8_t r, uint8_t g, uint8_t b) {
//   // 根据亮度值调整每个颜色分量
//   // 全局亮度变量，范围从0（完全关闭）到255（最大亮度）
//   uint8_t brightness = 50; // 例如，设置为50的亮度级别
//   LED_MATRIX[ledid][0] = (uint16_t)r * brightness / 255;
//   LED_MATRIX[ledid][1] = (uint16_t)g * brightness / 255;
//   LED_MATRIX[ledid][2] = (uint16_t)b * brightness / 255;
// }











