#include "Configuration.h"

Configuration::Configuration() {

}

int Configuration::getPinForSensor() {
    return ConfigurationValues::TEMP_SENSOR_INPUT_PIN;
}

SensorManager Configuration::getSensorManager() {
    return sensorManager;
}