#include "TFT_ILI9225_MonitorDisplay.h"

TFT_ILI9225_MonitorDisplay::TFT_ILI9225_MonitorDisplay() {
    tft.begin();         
    tft.setOrientation(ILI9225_VERTICAL_WINDOW_ADDR2);    
    tft.setBacklightBrightness(TFT_BRIGHTNESS);
    tft.clear();     

    currentLine = 1;
}

void TFT_ILI9225_MonitorDisplay::clearScreen() {
    tft.clear();
}

void TFT_ILI9225_MonitorDisplay::printSensorScreen(int tempSensorValue, int oilSensorValue) {
    
    tft.setFont(Terminal12x16);
    tft.setBackgroundColor(COLOR_BLACK);
    
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

void TFT_ILI9225_MonitorDisplay::print(int x, int y, const char *text, Color color) {
    currentLine += 10;
    if (currentLine >= 200) {
        currentLine = 1;
        tft.clear();
    }
    tft.drawText(x, currentLine, text, COLOR_GREENYELLOW);
    
}

void TFT_ILI9225_MonitorDisplay::drawBitmapScreen() {

    // from example code.

    static const unsigned char PROGMEM adafruit_icon[] = { 
        B00000000, B11000000,
        B00000001, B11000000,
        B00000001, B11000000,
        B00000011, B11100000,
        B11110011, B11100000,
        B11111110, B11111000,
        B01111110, B11111111,
        B00110011, B10011111,
        B00011111, B11111100,
        B00001101, B01110000,
        B00011011, B10100000,
        B00111111, B11100000,
        B00111111, B11110000,
        B01111100, B11110000,
        B01110000, B01110000,
        B00000000, B00110000 
    };

    int ADAFRUIT_LOGO_HEIGHT = 16;
    int ADAFRUIT_LOGO_WIDTH = 16;
    uint16_t cCount = random(0xFFFF);    

   for(int y = 0; y < 320; y += 20) {
        for(int x = 0; x < 240; x += 20) {
            if(cCount >= 0xFFFF)
                cCount = 0;
            else            
                tft.drawBitmap(x, y, adafruit_icon, 16, 16, cCount);
      
        cCount = random(0xFFFF);
        }
    }

}

void TFT_ILI9225_MonitorDisplay::drawWelcomeText() {
    tft.setFont(Terminal12x16);    
    tft.setBackgroundColor(COLOR_WHITE);
    tft.drawText(20, 65, "! W E L C O M E !", COLOR_WHITE);
    tft.drawText(20, 85, "! W E L C O M E !", COLOR_WHITE);
    tft.drawText(20, 75, "! W E L C O M E !", COLOR_BLACK);
}

