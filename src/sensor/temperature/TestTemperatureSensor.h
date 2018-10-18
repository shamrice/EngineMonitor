#ifndef __TEST_TEMPERATURE_SENSOR_H__
#define __TEST_TEMPERATURE_SENSOR_H__

#include "../SensorInput.h"

class TestTemperatureSensor : public SensorInput {
    
    public:
        TestTemperatureSensor(SensorType type) : SensorInput(type) {};
        ~TestTemperatureSensor() { }; 

        float getValue();
        void refresh();

};

#endif