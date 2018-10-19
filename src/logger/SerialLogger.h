#ifndef __SERIAL_LOGGER_H__
#define __SERIAL_LOGGER_H__

#include "WProgram.h"

enum LogLevel {
    DEBUG,
    INFO,
    ERROR
};

class SerialLogger {

    public: 
        static SerialLogger& getInstance() {
            static SerialLogger instance;
            return instance;
        }

        SerialLogger(SerialLogger const&) = delete;
        void operator=(SerialLogger const&) = delete;

        void log(LogLevel level, const char* message);
        void log(LogLevel level, const char* source, const char* message);

    private:
        SerialLogger();
        const char* getLogLevelString(LogLevel level);
};

#endif