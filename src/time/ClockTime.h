#ifndef __CLOCK_TIME_H__
#define __CLOCK_TIME_H__

#include <TimeLib.h>
#include "DateTime.h"
#include "../logger/SerialLogger.h"

class ClockTime {

    public:
        ClockTime();
        void logCurrentTime();
        void setDateTime(DateTime currentDateTime);
        DateTime getDateTime();

};

#endif