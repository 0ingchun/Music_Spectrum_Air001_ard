# Air001_Music_Spectrum
（按钮可调亮度版本）

## 材料 
 1. 麦克风（有模拟信号输出即可）：MAX4466
 2. 亚克力板：67 x 67 x 2 mm 黑茶色 透明非磨砂
 3. Ws2812灯板： 65 x 65 mm  8 x 8 = 64 LEDs
 4. 均光：普通硫酸纸或者用A4纸
 5. MCU：合宙Air001
 6. 按钮(可输出高低电平)：触摸或自复位按钮
 7. 电容，可选，推荐1000μF

## 注意事项
 1. ws2812B灯珠的排列方向不是蛇形走位，如果买到蛇形走位的，需要在程序中稍作修改
 2. 软件顶部工具栏，clock source and Frequency把Air001主频调到HSI 24 MHz，HCLK 48MHz的组合。
 3. 更改代码优化等级，顶部工具栏optimize修改为第二项（smallest（-OS）with LTO），不然会flash over flow
 4. ws2812b链接vbus或5v，不要连接3.3v
 5. 若麦克风没有放大元器件，调整MIC_AMP_NUM，麦克风接收放大倍率
 6. 若在无声情况下屏幕有跳动条形，可以考虑在麦克风电源（gnd，vcc）处加装电容（本人使用1000μF）

## 关于亮度的问题
> 可以在myws2812.cpp文件中等比例修改除数的值，从而改变灯的亮度,例如:
```cpp
void myWs2812b::SetLedColor(uint8_t ledid, uint8_t r, uint8_t g, uint8_t b) {
  // 这里可以更改后面的数值调节亮度，不除的话，亮度比较高，发热比较严重
  LED_MATRIX[ledid][0] = r/5;
  LED_MATRIX[ledid][1] = g/5;
  LED_MATRIX[ledid][2] = b/5;
}
```

## 接线
ws2182灯板：PA_7
按钮：PB_3
麦克风：PA_0
电容：麦克风的gnd，vcc之间

## 鸣谢/Thanks

本项目为 【weiruitong123】大佬的 https://github.com/weiruitong123/Air001_Music_Spectrum Air001声音频谱屏 项目的略微修改版本，外壳和arduino库文件全来自【weiruitong123】大佬，目前仅添加利用调节亮度的功能

![image2](E:\Document\Code\OtherProject\Air001_Music_Spectrum\图片\image2.jpg)