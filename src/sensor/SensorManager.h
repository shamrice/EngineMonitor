#ifndef __SENSOR_MANAGER_H__
#define __SENSOR_MANAGER_H__

#include "types/SensorType.h"
#include "SensorInput.h"
#include "../logger/SerialLogger.h"

#include <memory>
#include <array>

const int MAX_SENSORS = 200;

class SensorManager {

    public:
        SensorManager();
        ~SensorManager();
        bool addSensor(std::shared_ptr<SensorInput> sensorInput);
        bool removeSensor(SensorType sensorType);
        void refreshSensorValues();
        float getSensorValue(SensorType sensorType);  

    private:    
        std::array<std::shared_ptr<SensorInput>, MAX_SENSORS> sensorInputArray;
        const char* CLASS_NAME = "SensorManager";
};

#endif