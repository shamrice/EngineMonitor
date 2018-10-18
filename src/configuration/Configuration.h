#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include "ConfigurationValues.h"
#include "../sensor/SensorManager.h"

class Configuration {

    public:
        Configuration();
        int getPinForSensor();
        SensorManager getSensorManager();

    private:
        SensorManager sensorManager;

};

#endif