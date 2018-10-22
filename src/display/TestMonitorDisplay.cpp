#include "TestMonitorDisplay.h"

TestMonitorDisplay::TestMonitorDisplay() {
    tft.begin();  
    tft.clear();        
    tft.setOrientation(ILI9225_VERTICAL_WINDOW_ADDR2);    
    tft.setBacklightBrightness(TFT_BRIGHTNESS);

    currentLine = 1;
}

void TestMonitorDisplay::printSensorScreen(int tempSensorValue, int oilSensorValue) {
    
    tft.setFont(Terminal12x16);
    
    // draw water temperature
    String tempSensorValueStr = tempSensorValue;
    tempSensorValueStr += " degrees    ";

    tft.drawRectangle(10, 10, 200, 60, COLOR_BLUE);
    tft.drawText(20, 20, "Temperature", COLOR_WHITE);
    
    if (tempSensorValue < 180) {
        tft.drawText(20, 40, tempSensorValueStr, COLOR_BLUE);
    } else if (  tempSensorValue >= 180 && tempSensorValue < 210) {
        tft.drawText(20, 40, tempSensorValueStr, COLOR_GREEN);
    } else if (tempSensorValue >= 210 && tempSensorValue < 250) {
        tft.drawText(20, 40, tempSensorValueStr, COLOR_YELLOW);
    } else {
        tft.drawText(20, 40, tempSensorValueStr, COLOR_RED);
    }

    // draw oil pressure 
    String oilSensorValueStr = oilSensorValue;
    oilSensorValueStr += " psi        ";

    tft.drawRectangle(10, 100, 200, 140, COLOR_GRAY);
    tft.drawText(20, 80, "Oil Pressure", COLOR_WHITE);

    if (oilSensorValue < 80) {
        tft.drawText(20, 110, oilSensorValueStr, COLOR_GREEN);
    } else if (oilSensorValue >= 80 && oilSensorValue < 120) {
        tft.drawText(20, 110, oilSensorValueStr, COLOR_YELLOW);
    } else {
        tft.drawText(20, 110, oilSensorValueStr, COLOR_RED);
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