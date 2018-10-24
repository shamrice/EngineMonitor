#include "TestTemperatureSensor.h"

void TestTemperatureSensor::refresh() {
    
    int rawValue = analogRead(pin);

    if (value < MAX_VALUE_SUM) {
        value += rawValue / 10; 
        refreshCount++;
    } else {
        //to prevent value overflow if sensor value is not pulled for some reason.
        value = rawValue / 10;
        refreshCount = 1;
    }

    String logMessage = "Refreshing temp sensor with raw value of: ";
    logMessage += rawValue;
    logMessage += " sensor value=";
    logMessage += value;
    logMessage += " refreshCount=";
    logMessage += refreshCount;

    //SerialLogger::getInstance().log(LogLevel::INFO, "TestTemperatureSensor", logMessage);
    
}