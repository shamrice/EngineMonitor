#include "TestOilPressureSensor.h"

void TestOilPressureSensor::refresh() {
     if (value < 3000) {
         value += 1;
     }
}