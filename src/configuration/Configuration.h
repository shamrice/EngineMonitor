#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <memory>

#include "ConfigurationValues.h"
#include "../sensor/SensorManager.h"
#include "../sensor/temperature/TestTemperatureSensor.h"
#include "../sensor/oil/TestOilPressureSensor.h"

class Configuration {

    public:
        Configuration();
        int getPinForSensor();        
        SensorManager getSensorManager();

    private:
        SensorManager sensorManager;

};

#endif