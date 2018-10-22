#ifndef __TEST_MONITOR_DISPLAY_H__
#define __TEST_MONITOR_DISPLAY_H__

#include "MonitorDisplay.h"
#include "SPI.h"
//#include "ILI9225_t3.h"
#include "TFT_22_ILI9225.h"

class TestMonitorDisplay : public MonitorDisplay {

    public:
        static TestMonitorDisplay& getInstance() {
            static TestMonitorDisplay instance;
            return instance;
        };
        TestMonitorDisplay(TestMonitorDisplay const&) = delete;
        void operator=(TestMonitorDisplay const&) = delete;

        void print(int x, int y, const char *text, Color color);
        void printSensorScreen(int tempSensorValue, int oilSensorValue);

    private:
        TestMonitorDisplay();
        int currentLine;
        //ILI9225_t3 tft = ILI9225_t3(TFT_CS, TFT_RS, TFT_RST, TFT_MOSI, TFT_CLK, TFT_MISO, TFT_LED);
        TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);


};

#endif