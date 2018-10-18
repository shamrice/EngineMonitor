#include "SensorManager.h"

SensorManager::SensorManager() { }

SensorManager::~SensorManager() { }

void SensorManager::addSensor(std::shared_ptr<SensorInput> sensorInput) {
    
    for (auto it = sensorInputArray.begin(); it != sensorInputArray.end(); ++it) {
        if (*it == nullptr) {
            it->swap(sensorInput);
        }
    }

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

}