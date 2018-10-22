#ifndef __SENSOR_INPUT_H__
#define __SENSOR_INPUT_H__

#include "WProgram.h"
#include "../logger/SerialLogger.h"
#include "types/SensorType.h"

const int MAX_VALUE_SUM = 1000000;

class SensorInput {

    public:
        SensorInput(SensorType type, int pinNumber);
        virtual ~SensorInput() { };
        SensorType getSensorType();
        int getPin();
        int getValue();
        
        virtual void refresh() = 0;

    protected:
        int value = 0;
        int pin = 0;
        int refreshCount = 0;

    private:
        SensorType sensorType;        
};

#endif