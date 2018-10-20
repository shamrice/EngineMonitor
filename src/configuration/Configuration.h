#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <memory>

#include "ConfigurationValues.h"
#include "../logger/SerialLogger.h"
#include "../display/MonitorDisplay.h"
#include "../display/TestMonitorDisplay.h"
#include "../sensor/SensorManager.h"
#include "../sensor/types/SensorType.h"
#include "../sensor/temperature/TestTemperatureSensor.h"
#include "../sensor/oil/TestOilPressureSensor.h"

class Configuration {

    public:
        Configuration();
        int getPinForSensor(SensorType sensorType);        
        SensorManager getSensorManager();
        //MonitorDisplay* getMonitorDisplay();

    private:
        SensorManager sensorManager;
        //std::shared_ptr<MonitorDisplay> monitorDisplay;

};

#endif