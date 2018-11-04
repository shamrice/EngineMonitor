#include "DateTime.h"

DateTime::DateTime() {

}

DateTime::DateTime(int y, int m, int d, int h, int min, int sec) {
    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min;
    second = sec;
}
    
int DateTime::getYear() {
    return year;
}

int DateTime::getMonth() {
    return month;
}

int DateTime::getDay() {
    return day;
}


int DateTime::getHour() {
    return hour;
}
        
int DateTime::getMinute() {
    return minute;
}
        
int DateTime::getSecond() {
    return second;
}

String DateTime::toString() {
    String timeString = getDateString();
    timeString += " ";
    timeString += getTimeString();
    
    return timeString;
}


String DateTime::getTimeString() {
    String timeString;

    if (hour < 10) { 
        timeString += "0";
    }

    if (hour > 12) {
        timeString += "0";
        int hourToShow = hour - 12;
        timeString += hourToShow;
    } else {        
        timeString += hour;
    }

    timeString += ":";

    if (minute < 10) { 
        timeString += "0";
    }

    timeString += minute;
    timeString += ":";

    if (second < 10) { 
        timeString += "0";
    }
    timeString += second;
 
    return timeString;
}


String DateTime::getDateString() {
    String timeString; 

    if (month < 10) {
        timeString += "0";
    }
    timeString += month;
    timeString += "/";

    if (day < 10) {
        timeString += "0";
    }
    timeString += day;
    timeString += "/";
    timeString += year;

    return timeString;
}

void DateTime::setYear(int y) {
    year = y;
}
        
void DateTime::setMonth(int m) {
    month = m;
}
        
void DateTime::setDay(int d) {
    day = d;
}
        
void DateTime::setHour(int h) {
    hour = h;
}
        
void DateTime::setMinute(int min) {
    minute = min;
}
        
void DateTime::setSecond(int sec) {
    second = sec;
}
