#include "SensorInput.h"

SensorInput::SensorInput(SensorType type, int pinNumber) {
    sensorType = type;
    pin = pinNumber;
}

SensorType SensorInput::getSensorType() {
    return sensorType;
}

int SensorInput::getValue() {
    int returnVal = value / refreshCount;
    refreshCount = 0;
    value = 0;
    return returnVal;    
}

int SensorInput::getPin() {
    return pin;
}

