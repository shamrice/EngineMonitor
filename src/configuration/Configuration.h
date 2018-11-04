#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <memory>

#include "ConfigurationValues.h"
#include "../logger/SerialLogger.h"
#include "../display/MonitorDisplay.h"
#include "../display/TFT_ILI9225_MonitorDisplay.h"
#include "../sensor/SensorManager.h"
#include "../sensor/types/SensorType.h"
#include "../sensor/temperature/TestTemperatureSensor.h"
#include "../sensor/oil/TestOilPressureSensor.h"

class Configuration {

    public:
        Configuration();
        int getDisplayRefreshFrequency();
        int getPinForSensor(SensorType sensorType);        
        SensorManager getSensorManager();

    private:
        void configureTime();
        SensorManager sensorManager;

};

#endif