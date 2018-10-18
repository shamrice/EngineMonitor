#include "SensorManager.h"

SensorManager::SensorManager() { }

SensorManager::~SensorManager() { }

bool SensorManager::addSensor(std::shared_ptr<SensorInput> sensorInput) {
    
    for (auto it = sensorInputArray.begin(); it != sensorInputArray.end(); ++it) {
        if (*it == nullptr) {
            it->swap(sensorInput);
            return true;
        }
    }

    return false;
}

bool SensorManager::removeSensor(SensorType sensorType) {

    for (auto it = sensorInputArray.begin(); it != sensorInputArray.end(); ++it) {
        if (*it != nullptr && it->get()->getSensorType() == sensorType) {
            it->reset();
            return true;
        }
    }    

    return false;
}

float SensorManager::getSensorValue(SensorType sensorType) {

    for (auto it = sensorInputArray.begin(); it != sensorInputArray.end(); ++it) {
        if (*it != nullptr && it->get()->getSensorType() == sensorType) {
            return it->get()->getValue();
        }
    }

    return -1;
}

void SensorManager::refreshSensorValues() {

    for (auto it = sensorInputArray.begin(); it != sensorInputArray.end(); ++it) {
        if (*it != nullptr) {
            it->get()->refresh();
        }
    }
}