#ifndef __DATE_TIME_H__
#define __DATE_TIME_H__

#include "../logger/SerialLogger.h"

class DateTime {

    public:
        DateTime();
        DateTime(int y, int m, int d, int h, int min, int sec);
        int getYear();
        int getMonth();
        int getDay();
        int getHour();
        int getMinute();
        int getSecond();
        String toString();
        String getTimeString();
        String getDateString();

        void setYear(int y);
        void setMonth(int m);
        void setDay(int d);
        void setHour(int h);
        void setMinute(int min);
        void setSecond(int sec);

    private:
        int day = 0;
        int month = 0;
        int year = 0;
        int hour = 0;
        int minute = 0;
        int second = 0;

};

#endif