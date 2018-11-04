#ifndef __STATE_H__
#define __STATE_H__

#include "../time/DateTime.h"
#include "../sensor/SensorManager.h"

class State {

    public:
        State(SensorManager SensorManager, DateTime currentTime); 
        SensorManager getSensorManager();
        DateTime getDateTime();

    private:
        SensorManager sensorManager;
        DateTime curTime;

};

#endif