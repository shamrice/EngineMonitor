#ifndef __SENSOR_INPUT_H__
#define __SENSOR_INPUT_H__

#include "types/SensorType.h"

class SensorInput {

    public:
        SensorInput(SensorType type, int pinNumber);
        virtual ~SensorInput() { };
        SensorType getSensorType();
        int getPin();
        float getValue();
        
        virtual void refresh() = 0;

    protected:
        float value = 0;

    private:
        SensorType sensorType;
        int pin = 0;
};

#endif