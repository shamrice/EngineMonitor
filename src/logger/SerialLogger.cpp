#include "SerialLogger.h"

SerialLogger::SerialLogger() {
    Serial.begin(9600);
}

void SerialLogger::log(LogLevel level, String source, String message) {
    Serial.printf("%s :: %s :: %s\n", getLogLevelString(level).c_str(), source.c_str(), message.c_str());
}

void SerialLogger::log(LogLevel level, String message) {
    Serial.printf("%s :: %s\n", getLogLevelString(level).c_str(), message.c_str());

}

String SerialLogger::getLogLevelString(LogLevel level) {
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