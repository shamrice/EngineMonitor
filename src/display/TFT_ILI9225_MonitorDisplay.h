#ifndef __TEST_MONITOR_DISPLAY_H__
#define __TEST_MONITOR_DISPLAY_H__

#include "MonitorDisplay.h"
#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include "../core/State.h"

class TFT_ILI9225_MonitorDisplay : public MonitorDisplay {

    public:
        static TFT_ILI9225_MonitorDisplay& getInstance() {
            static TFT_ILI9225_MonitorDisplay instance;
            return instance;
        };
        TFT_ILI9225_MonitorDisplay(TFT_ILI9225_MonitorDisplay const&) = delete;
        void operator=(TFT_ILI9225_MonitorDisplay const&) = delete;

        void displayCurrentScreen(State state);

        void clearScreen();
        void print(int x, int y, const char *text, Color color);        
        void drawBitmapScreen();
        void drawWelcomeText();

    private:
        TFT_ILI9225_MonitorDisplay();
        void printSensorScreen(int tempSensorValue, int oilSensorValue);
        void printTimeScreen(DateTime dateTime);
        int currentLine;        
        TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);


};

#endif