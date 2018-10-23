#include "MonitorCore.h"

MonitorCore::MonitorCore() {

    sensorManager = configuration.getSensorManager();

    //init i/o pins
    pinMode(ConfigurationValues::TEST_LED_OUTPUT_PIN, OUTPUT);
    pinMode(configuration.getPinForSensor(SensorType::OIL_PRESSURE), INPUT);
    pinMode(configuration.getPinForSensor(SensorType::TEMPERATURE), INPUT);    

    /* test boot up screen */
    /*
    TFT_ILI9225_MonitorDisplay::getInstance().drawBitmapScreen();
    TFT_ILI9225_MonitorDisplay::getInstance().drawWelcomeText();
    delay(1500);
    TFT_ILI9225_MonitorDisplay::getInstance().clearScreen();
    TFT_ILI9225_MonitorDisplay::getInstance().drawBitmapScreen();
    */
}

void MonitorCore::refreshSensorValues() {
    sensorManager.refreshSensorValues();
}

void MonitorCore::displaySensorValues() {
    SerialLogger::getInstance().log(LogLevel::DEBUG, "MonitorCore", "Displaying sensor values to screen.");

    int tempSensorValue = sensorManager.getSensorValue(SensorType::TEMPERATURE);
	int oilSensorValue = sensorManager.getSensorValue(SensorType::OIL_PRESSURE);
    
    TFT_ILI9225_MonitorDisplay::getInstance().printSensorScreen(tempSensorValue, oilSensorValue);


}