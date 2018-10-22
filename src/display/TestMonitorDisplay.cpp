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
    tempSensorValue *= 3;

    String tempSensorValueStr = tempSensorValue;
    tempSensorValueStr += " degrees    ";

    tft.drawRectangle(10, 10, 200, 75, COLOR_BLUE);
    tft.drawText(20, 0, "Temperature", COLOR_WHITE);

    // TODO : refactor this section.    
    unsigned short color = COLOR_BLUE;
    int minThreshold = 180;
    int midThreshold = 230;
    int maxThreshold = 260;

    int yVal = tempSensorValue / 2;
    if (yVal > 180) {
        yVal = 180;
    } else if (yVal < 20) {
        yVal = 20;
    }

    tft.fillRectangle(yVal, 40, 180, 50, COLOR_BLACK);

    if (tempSensorValue < minThreshold) {
        color = COLOR_BLUE;
        tft.fillRectangle(20, 40, yVal, 50, COLOR_BLUE);

    } else if (tempSensorValue >= minThreshold && tempSensorValue < midThreshold) {
        color = COLOR_GREEN;        
        tft.fillRectangle(minThreshold / 2, 40, yVal, 50, COLOR_GREEN);

        tft.fillRectangle(20, 40, minThreshold / 2, 50, COLOR_BLUE);
    } else if (tempSensorValue >= midThreshold && tempSensorValue < maxThreshold) {
        color = COLOR_YELLOW;
        tft.fillRectangle(midThreshold / 2, 40, yVal, 50, COLOR_YELLOW);

        tft.fillRectangle(20, 40, minThreshold / 2, 50, COLOR_BLUE);
        tft.fillRectangle(minThreshold / 2, 40, midThreshold / 2, 50, COLOR_GREEN);
    } else {
        color = COLOR_RED;       
        tft.fillRectangle(maxThreshold / 2, 40, yVal, 50, COLOR_RED);

        tft.fillRectangle(20, 40, minThreshold / 2, 50, COLOR_BLUE);
        tft.fillRectangle(minThreshold / 2, 40, midThreshold / 2, 50, COLOR_GREEN);
        tft.fillRectangle(midThreshold / 2, 40, maxThreshold / 2, 50, COLOR_YELLOW);
    }

    tft.drawText(20, 20, tempSensorValueStr, color);    


    // draw oil pressure 
    String oilSensorValueStr = oilSensorValue;
    oilSensorValueStr += " psi        ";

    tft.drawRectangle(10, 110, 200, 140, COLOR_GRAY);
    tft.drawText(20, 100, "Oil Pressure", COLOR_WHITE);

    if (oilSensorValue < 80) {
        tft.drawText(20, 120, oilSensorValueStr, COLOR_GREEN);
    } else if (oilSensorValue >= 80 && oilSensorValue < 120) {
        tft.drawText(20, 120, oilSensorValueStr, COLOR_YELLOW);
    } else {
        tft.drawText(20, 120, oilSensorValueStr, COLOR_RED);
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