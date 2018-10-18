#include "TestTemperatureSensor.h"

void TestTemperatureSensor::refresh() {
    if (value < 3000) {
        value += 2;
    }
}