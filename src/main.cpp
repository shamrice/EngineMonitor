#include "WProgram.h"
#include "core/MonitorCore.h"

//#define USING_MAKEFILE

extern "C" int main(void)
{
#ifdef USING_MAKEFILE

	// To use Teensy 3.0 without Arduino, simply put your code here.
	// For example:

	MonitorCore core;
	Configuration config;

	core.setConfiguration(config);

	pinMode(13, OUTPUT);
	while (1) {
		digitalWriteFast(13, HIGH);
		delay(10000);
		digitalWriteFast(13, LOW);
		delay(10000);
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

