#ifndef __MONITOR_DISPLAY_H__
#define __MONITOR_DISPLAY_H__

#include "colors/Color.h"
/*
#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  
#define TFT_MOSI 11  // Actually SDI / DOUT
#define TFT_MISO 12  // not used.
#define TFT_CLK 13  // SCK 
#define TFT_LED 6   // ground

#define ADAFRUIT_LOGO_HEIGHT 16
#define ADAFRUIT_LOGO_WIDTH  16
*/
#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED 3   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 1 // Initial brightness of TFT backlight (optional)

class MonitorDisplay {

    public:
        virtual void printSensorScreen(int tempSensorValue, int oilSensorValue);
        virtual void print(int x, int y, const char *text, Color color);

};

#endif