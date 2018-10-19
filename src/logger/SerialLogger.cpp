#include "SerialLogger.h"

SerialLogger::SerialLogger() {
    Serial.begin(9600);
}

void SerialLogger::log(LogLevel level, const char* source, const char* message) {
    Serial.printf("%s :: %s :: %s\n", getLogLevelString(level), source, message);
}

void SerialLogger::log(LogLevel level, const char* message) {
    Serial.printf("%s :: %s\n", getLogLevelString(level), message);

}

const char* SerialLogger::getLogLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:
            return "DEBUG";

        case LogLevel::ERROR:
            return "ERROR";

        case LogLevel::INFO:
            return "INFO";
    }

    return "UNDEFINED";
}