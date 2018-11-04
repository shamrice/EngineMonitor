#include "ClockTime.h"

time_t getTeensy3Time()
{
    return Teensy3Clock.get();
}

ClockTime::ClockTime() {
    setSyncProvider(getTeensy3Time);

    if (timeStatus()!= timeSet) {
        SerialLogger::getInstance().log(LogLevel::ERROR, "ClockTime::ClockTime()" "Unable to sync with RTC");
    } else {
        SerialLogger::getInstance().log(LogLevel::INFO, "ClockTime::ClockTime()" "RTC has set the system time");
    }
}

void ClockTime::logCurrentTime() {

    DateTime datetime(year(), month(), day(), hour(), minute(), second());    
    SerialLogger::getInstance().log(LogLevel::INFO, "ClockTime::ClockTime()", datetime.toString());
}

DateTime ClockTime::getDateTime() {
    //TODO : current manually adjusting timestamp to EST 
    DateTime datetime(year(), month(), day(), hour() - 5, minute(), second());
    return datetime;
}

void ClockTime::setDateTime(DateTime currentDateTime) {

    //TODO : get unix timestamp from datetime passed in and used that for the set call.

    time_t t = 0L;
    Teensy3Clock.set(t); // set the RTC

    setTime(
        currentDateTime.getHour(), 
        currentDateTime.getMinute(), 
        currentDateTime.getSecond(), 
        currentDateTime.getDay(), 
        currentDateTime.getMonth(), 
        currentDateTime.getYear()
    );
}