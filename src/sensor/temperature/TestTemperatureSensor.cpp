#include "TestTemperatureSensor.h"

void TestTemperatureSensor::refresh() {
    
    value = analogRead(pin);

    String logMessage = "Refreshing temp sensor with value of: ";
    logMessage += value;

    SerialLogger::getInstance().log(LogLevel::INFO, "TestTemperatureSensor", logMessage);
    
}