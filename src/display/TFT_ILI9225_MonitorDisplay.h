#ifndef __TEST_MONITOR_DISPLAY_H__
#define __TEST_MONITOR_DISPLAY_H__

#include "MonitorDisplay.h"
#include "SPI.h"
//#include "ILI9225_t3.h"
#include "TFT_22_ILI9225.h"

class TFT_ILI9225_MonitorDisplay : public MonitorDisplay {

    public:
        static TFT_ILI9225_MonitorDisplay& getInstance() {
            static TFT_ILI9225_MonitorDisplay instance;
            return instance;
        };
        TFT_ILI9225_MonitorDisplay(TFT_ILI9225_MonitorDisplay const&) = delete;
        void operator=(TFT_ILI9225_MonitorDisplay const&) = delete;

        void print(int x, int y, const char *text, Color color);
        void printSensorScreen(int tempSensorValue, int oilSensorValue);

    private:
        TFT_ILI9225_MonitorDisplay();
        int currentLine;
        //ILI9225_t3 tft = ILI9225_t3(TFT_CS, TFT_RS, TFT_RST, TFT_MOSI, TFT_CLK, TFT_MISO, TFT_LED);
        TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);


};

#endif