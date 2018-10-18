#include "WProgram.h"
#include "core/ApplicationServices.h"
#include "configuration/ConfigurationValues.h"

#define USING_MAKEFILE

extern "C" int main(void)
{
#ifdef USING_MAKEFILE

	ApplicationServices appServices;
	appServices.run();

#else
	// Arduino's main() function just calls setup() and loop()....
	setup();
	while (1) {
		loop();
		yield();
	}
#endif

}

