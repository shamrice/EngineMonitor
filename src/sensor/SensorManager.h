#ifndef __SENSOR_MANAGER_H__
#define __SENSOR_MANAGER_H__

#include "types/SensorType.h"
#include "SensorInput.h"

class SensorManager {

    public:
        void addSensor(SensorType sensorType, SensorInput* sensorInput);
        float getSensorValue(SensorType sensorType);
        void refreshSensorValues();

    private:
        //map of sensorType, SensorInput
};

#endif