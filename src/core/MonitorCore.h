#ifndef __MONITOR_CORE_H__
#define __MONITOR_CORE_H__

#include "configuration/Configuration.h"

class MonitorCore {

    public:
        static MonitorCore& getInstance() {
            static MonitorCore instance;
            return instance;
        }

        MonitorCore(MonitorCore const&) = delete;
        void operator=(MonitorCore const&) = delete;

        void setConfiguration(Configuration config);
        void refreshSensorValues();
        void displaySensorValues();

    private:
        MonitorCore();
        Configuration configuration;
    

};

#endif