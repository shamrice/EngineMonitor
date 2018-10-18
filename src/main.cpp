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
		digitalWriteFast(13, HIGH);
		delay(config.getPinForSensor());
		digitalWriteFast(13, LOW);
		delay(config.getSensorManager().getSensorValue(SensorType::TEMPERATURE));
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

