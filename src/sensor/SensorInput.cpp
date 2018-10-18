#include "SensorInput.h"

SensorInput::SensorInput(SensorType type) {
    sensorType = type;
}

SensorType SensorInput::getSensorType() {
    return sensorType;
}

