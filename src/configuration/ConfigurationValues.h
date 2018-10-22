#ifndef __CONFIGURATION_VALUES_H__
#define __CONFIGURATION_VALUES_H__

/**
 * For time being, device has no on board storage so values are set 
 * in this header file and read by the Configuration class.
*/

namespace ConfigurationValues {

    const int NUM_SENSORS = 2;
    const int TEST_LED_OUTPUT_PIN = 13;
    const int TEMP_SENSOR_INPUT_PIN = 0;
    const int OIL_PRESSURE_SENSOR_INPUT_PIN = 23;

    const int SENSOR_VALUE_REFRESH_FREQUENCY = 5;
}

#endif