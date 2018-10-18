#ifndef __MONITOR_CORE_H__
#define __MONITOR_CORE_H__

#include "WProgram.h"
#include "configuration/Configuration.h"
#include <string>

class MonitorCore {

    public:
        static MonitorCore& getInstance() {
            static MonitorCore instance;
            return instance;
        }

        MonitorCore(MonitorCore const&) = delete;
        void operator=(MonitorCore const&) = delete;

        void refreshSensorValues();
        void displaySensorValues();

    private:
        MonitorCore();
        SensorManager sensorManager;
        MonitorDisplay *monitorDisplay;
        Configuration configuration;
    

};

#endif