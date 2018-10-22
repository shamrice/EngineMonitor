#include "TestMonitorDisplay.h"

TestMonitorDisplay::TestMonitorDisplay() {
    tft.begin();  
    tft.clear();        
    tft.setOrientation(ILI9225_VERTICAL_WINDOW_ADDR2);    
    tft.setBacklightBrightness(TFT_BRIGHTNESS);

    currentLine = 1;
}

void TestMonitorDisplay::printSensorScreen(float tempSensorValue, float oilSensorValue) {
    
    //tft.setBacklightBrightness(tempSensorValue);

    char tempSensorValueStr[100];
    sprintf(tempSensorValueStr, "%.0f   ", tempSensorValue);

    char oilSensorValueStr[100];
    sprintf(oilSensorValueStr, "%.0f   ", oilSensorValue);

    char text[255];
    strcpy(text, "Temp: ");
    strcat(text, tempSensorValueStr);

    tft.setFont(Terminal12x16);
    tft.drawRectangle(10, 10, 160, 50, COLOR_BLUE);
    
    if (tempSensorValue < 210) {
        tft.drawText(20, 20, text, COLOR_GREEN);
    } else if (tempSensorValue >= 210 && tempSensorValue < 250) {
        tft.drawText(20, 20, text, COLOR_YELLOW);
    } else {
        tft.drawText(20, 20, text, COLOR_RED);
    }

    char oilText[255];    
    strcpy(oilText, oilSensorValueStr);
    strcat(oilText, " psi");

    //tft.setFont(Terminal6x8);
    tft.setFont(Terminal12x16);
    tft.drawRectangle(10, 60, 160, 130, COLOR_GRAY);
    
    tft.drawText(20, 80, "Oil Pressure", COLOR_WHITE);

    if (oilSensorValue < 80) {
        tft.drawText(20, 100, oilText, COLOR_GREEN);
    } else if (oilSensorValue >= 80 && oilSensorValue < 120) {
        tft.drawText(20, 100, oilText, COLOR_YELLOW);
    } else {
        tft.drawText(20, 100, oilText, COLOR_RED);
    }

}

void TestMonitorDisplay::print(int x, int y, const char *text, Color color) {
    currentLine += 10;
    if (currentLine >= 200) {
        currentLine = 1;
        tft.clear();
    }
    tft.drawText(x, currentLine, text, COLOR_GREENYELLOW);
    
}