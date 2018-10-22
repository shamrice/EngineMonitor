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

        void setEnabled(bool enabled);
        void log(LogLevel level, String message);
        void log(LogLevel level, String source, String message);

    private:
        SerialLogger();
        bool isEnabled = false;
        String getLogLevelString(LogLevel level);
};

#endif