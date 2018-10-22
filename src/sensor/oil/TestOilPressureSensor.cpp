#include "TestOilPressureSensor.h"

void TestOilPressureSensor::refresh() {
    refreshCount++;
    if (value < 3000) {
        value += 1;
    }
}