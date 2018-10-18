#include "SensorInput.h"

SensorInput::SensorInput(SensorType type, int pinNumber) {
    sensorType = type;
    pin = pinNumber;
}

SensorType SensorInput::getSensorType() {
    return sensorType;
}

float SensorInput::getValue() {
    return value;
}

int SensorInput::getPin() {
    return pin;
}

