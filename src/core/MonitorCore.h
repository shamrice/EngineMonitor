#ifndef __MONITOR_CORE_H__
#define __MONITOR_CORE_H__

#include "WProgram.h"
#include "configuration/Configuration.h"
#include "../time/ClockTime.h"
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
        void displayScreen();
        void readInput();

    private:
        MonitorCore();
        SensorManager sensorManager;
        ClockTime clockTime;
        Configuration configuration;
    

};

#endif