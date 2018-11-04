#include "State.h"

State::State(SensorManager SensorManager, DateTime currentTime) {
    sensorManager = SensorManager;
    curTime = currentTime;
}

SensorManager State::getSensorManager()  {
    return sensorManager;
}

DateTime State::getDateTime() {
    return curTime;
}