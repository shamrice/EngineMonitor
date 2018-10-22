#include "MonitorCore.h"

MonitorCore::MonitorCore() {

    sensorManager = configuration.getSensorManager();

    //init i/o pins
    pinMode(ConfigurationValues::TEST_LED_OUTPUT_PIN, OUTPUT);
    pinMode(configuration.getPinForSensor(SensorType::OIL_PRESSURE), INPUT);
    pinMode(configuration.getPinForSensor(SensorType::TEMPERATURE), INPUT);    }

void MonitorCore::refreshSensorValues() {
    sensorManager.refreshSensorValues();
}

void MonitorCore::displaySensorValues() {
    int tempSensorValue = sensorManager.getSensorValue(SensorType::TEMPERATURE);
	int oilSensorValue = sensorManager.getSensorValue(SensorType::OIL_PRESSURE);

    /*
	if (tempSensorValue > 0 && oilSensorValue > 0) {
		digitalWriteFast(ConfigurationValues::TEST_LED_OUTPUT_PIN, HIGH);
		delay(tempSensorValue);
		digitalWriteFast(ConfigurationValues::TEST_LED_OUTPUT_PIN, LOW);
		delay(oilSensorValue);
	}
    */

    SerialLogger::getInstance().log(LogLevel::DEBUG, "MonitorCore", "Test log");
/*
    
    char tempSensorValueStr[100];
    sprintf(tempSensorValueStr, "%d", tempSensorValue);

    char oilSensorValueStr[100];
    sprintf(oilSensorValueStr, "%d", oilSensorValue);

    char text[255];
    strcpy(text, "Temp: ");
    strcat(text, tempSensorValueStr);
    strcat(text, " :: Oil: ");
    strcat(text, oilSensorValueStr);
    strcat(text, " psi");

    TestMonitorDisplay::getInstance().print(1, 1, text, Color::BLUE);
    */

   TestMonitorDisplay::getInstance().printSensorScreen(tempSensorValue, oilSensorValue);

    //monitorDisplay.print(1, 1, "values", Color::GREEN);

}