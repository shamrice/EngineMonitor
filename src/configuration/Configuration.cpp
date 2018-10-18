#include "Configuration.h"

Configuration::Configuration() {
    
    std::shared_ptr<SensorInput> tempSensor = std::make_shared<TestTemperatureSensor>(SensorType::TEMPERATURE);
    std::shared_ptr<SensorInput> oilPressureSensor = std::make_shared<TestOilPressureSensor>(SensorType::OIL_PRESSURE);    

    sensorManager.addSensor(tempSensor);
    sensorManager.addSensor(oilPressureSensor);
    
}

int Configuration::getPinForSensor() {
    return ConfigurationValues::TEMP_SENSOR_INPUT_PIN;
}

SensorManager Configuration::getSensorManager() {
    return sensorManager;
}