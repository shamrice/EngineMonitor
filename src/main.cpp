#include "WProgram.h"
#include "core/MonitorCore.h"

#define USING_MAKEFILE

extern "C" int main(void)
{
#ifdef USING_MAKEFILE

	Configuration config;
	MonitorCore::getInstance().setConfiguration(config);

	config.getSensorManager().refreshSensorValues();
	
	pinMode(13, OUTPUT);
	while (1) {
		int tempSensorValue = config.getSensorManager().getSensorValue(SensorType::TEMPERATURE);
		int oilSensorValue = config.getSensorManager().getSensorValue(SensorType::OIL_PRESSURE);

		if (tempSensorValue > 0 && oilSensorValue > 0) {
			digitalWriteFast(13, HIGH);
			delay(tempSensorValue);
			digitalWriteFast(13, LOW);
			delay(oilSensorValue);
		}
	}


#else
	// Arduino's main() function just calls setup() and loop()....
	setup();
	while (1) {
		loop();
		yield();
	}
#endif

}

