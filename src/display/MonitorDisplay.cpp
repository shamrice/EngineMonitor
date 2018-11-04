#include "MonitorDisplay.h"

void MonitorDisplay::setScreen(Screen screen) {
    currentScreen = screen;
    clearScreen();
}