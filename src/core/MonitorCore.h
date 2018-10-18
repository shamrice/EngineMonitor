#ifndef __MONITOR_CORE_H__
#define __MONITOR_CORE_H__

#include "configuration/Configuration.h"

class MonitorCore {

    public:
        void setConfiguration(Configuration config);
        void refreshSensorValues();
        void displaySensorValues();

    private:
        Configuration configuration;
    

};

#endif