#ifndef __SENSOR_INPUT_H__
#define __SENSOR_INPUT_H__

class SensorInput {

    protected: 
        virtual float getValue() = 0;
        virtual void refresh() = 0;
};

#endif