#include "TestTemperatureSensor.h"

void TestTemperatureSensor::refresh() {
    
    value = analogRead(pin);

    
    char valueStr[100];
    sprintf(valueStr, "%f", value);

    char logMessage[255] = "Refreshing temp sensor with value of ";
    strcat(logMessage, valueStr);

    SerialLogger::getInstance().log(LogLevel::INFO, logMessage);
    
}