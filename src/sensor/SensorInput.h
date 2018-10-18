#ifndef __SENSOR_INPUT_H__
#define __SENSOR_INPUT_H__

#include "types/SensorType.h"

class SensorInput {

    public:
        SensorInput(SensorType type);
        virtual ~SensorInput() { };
        SensorType getSensorType();
        virtual float getValue() = 0;
        virtual void refresh() = 0;

    private:
        SensorType sensorType;
};

#endif