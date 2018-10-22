#include "Configuration.h"

Configuration::Configuration() {
    
    //set up sensor manager
    std::shared_ptr<SensorInput> tempSensor = std::make_shared<TestTemperatureSensor>(
        SensorType::TEMPERATURE, 
        ConfigurationValues::TEMP_SENSOR_INPUT_PIN        
    );

    std::shared_ptr<SensorInput> oilPressureSensor = std::make_shared<TestOilPressureSensor>(
        SensorType::OIL_PRESSURE,
        ConfigurationValues::OIL_PRESSURE_SENSOR_INPUT_PIN
    );    

    sensorManager.addSensor(tempSensor);
    sensorManager.addSensor(oilPressureSensor);
}

int Configuration::getPinForSensor(SensorType sensorType) {

    switch (sensorType) {
        case SensorType::OIL_PRESSURE:
            return ConfigurationValues::OIL_PRESSURE_SENSOR_INPUT_PIN;
        
        case SensorType::TEMPERATURE:
            return ConfigurationValues::TEMP_SENSOR_INPUT_PIN;
    }

    return -1;
}

SensorManager Configuration::getSensorManager() {
    return sensorManager;
}