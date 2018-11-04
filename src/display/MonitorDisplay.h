#ifndef __MONITOR_DISPLAY_H__
#define __MONITOR_DISPLAY_H__

#include "colors/Color.h"
#include "screens/Screen.h"
#include "../time/DateTime.h"
#include "../time/ClockTime.h"
#include "../core/State.h"

#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED 3   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 1 // Initial brightness of TFT backlight (optional)

class MonitorDisplay {

    public:

        void setScreen(Screen screen);

        virtual void displayCurrentScreen(State state);
        virtual void clearScreen();
        virtual void print(int x, int y, const char *text, Color color);

    protected:
        Screen currentScreen;

};

#endif