#ifndef __TEST_OIL_PRESSURE_SENSOR_H__
#define __TEST_OIL_PRESSURE_SENSOR_H__

#include "../SensorInput.h"

class TestOilPressureSensor : public SensorInput {
    
    public:
        TestOilPressureSensor(SensorType type, int pinNum) : SensorInput(type, pinNum) {};
        ~TestOilPressureSensor() { }; 

        void refresh();

};

#endif