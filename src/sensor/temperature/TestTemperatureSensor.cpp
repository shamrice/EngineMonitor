#include "TestTemperatureSensor.h"

void TestTemperatureSensor::refresh() {
    
    int rawValue = analogRead(pin);
    value += rawValue; 
    refreshCount++;

    String logMessage = "Refreshing temp sensor with raw value of: ";
    logMessage += rawValue;
    logMessage += " sensor value=";
    logMessage += value;
    logMessage += " refreshCount=";
    logMessage += refreshCount;

    SerialLogger::getInstance().log(LogLevel::INFO, "TestTemperatureSensor", logMessage);
    
}