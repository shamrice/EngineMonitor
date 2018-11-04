#include "Configuration.h"

Configuration::Configuration() {

    //enable serial logger if enabled    
    SerialLogger::getInstance().setEnabled(ConfigurationValues::IS_SERIAL_LOGS_ENABLED);    
    
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

int Configuration::getDisplayRefreshFrequency() {
    return ConfigurationValues::DISPLAY_REFRESH_FREQUENCY;
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

void Configuration::configureTime() {

}