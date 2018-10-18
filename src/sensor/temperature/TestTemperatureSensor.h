#ifndef __TEST_TEMPERATURE_SENSOR_H__
#define __TEST_TEMPERATURE_SENSOR_H__

#include "../SensorInput.h"

class TestTemperatureSensor : public SensorInput {
    
    public:
        TestTemperatureSensor(SensorType type, int pinNum) : SensorInput(type, pinNum) {};
        ~TestTemperatureSensor() { }; 

        void refresh();

};

#endif