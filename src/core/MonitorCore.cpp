#include "MonitorCore.h"

MonitorCore::MonitorCore() {

    sensorManager = configuration.getSensorManager();

    //init i/o pins
    pinMode(ConfigurationValues::TEST_LED_OUTPUT_PIN, OUTPUT);
    pinMode(ConfigurationValues::EXTERNAL_TEST_LED_PIN, OUTPUT);

    pinMode(configuration.getPinForSensor(SensorType::OIL_PRESSURE), INPUT);
    pinMode(configuration.getPinForSensor(SensorType::TEMPERATURE), INPUT);    

    pinMode(ConfigurationValues::INPUT_LEFT_PIN, INPUT);
    pinMode(ConfigurationValues::INPUT_RIGHT_PIN, INPUT);
    pinMode(ConfigurationValues::INPUT_UP_PIN, INPUT);
    pinMode(ConfigurationValues::INPUT_DOWN_PIN, INPUT);
    pinMode(ConfigurationValues::INPUT_BUTTON_DOWN_PIN, INPUT);

    TFT_ILI9225_MonitorDisplay::getInstance().setScreen(Screen::SENSOR);
}

void MonitorCore::refreshSensorValues() {
    sensorManager.refreshSensorValues();
}

void MonitorCore::displayScreen() {
    State state(sensorManager, clockTime.getDateTime());
    TFT_ILI9225_MonitorDisplay::getInstance().displayCurrentScreen(state);
    clockTime.logCurrentTime();
}

void MonitorCore::readInput() {

    int left = analogRead(ConfigurationValues::INPUT_LEFT_PIN);
    int right = analogRead(ConfigurationValues::INPUT_RIGHT_PIN);
    int up = analogRead(ConfigurationValues::INPUT_UP_PIN);
    int down = analogRead(ConfigurationValues::INPUT_DOWN_PIN);
    int button = analogRead(ConfigurationValues::INPUT_BUTTON_DOWN_PIN);

    if (left == 1 || right == 1 || up == 1 || down == 1 || button == 1) {
        digitalWrite(ConfigurationValues::EXTERNAL_TEST_LED_PIN, HIGH);
    } else {
        digitalWrite(ConfigurationValues::EXTERNAL_TEST_LED_PIN, LOW);
    }

    if (left == 1) {
        TFT_ILI9225_MonitorDisplay::getInstance().setScreen(Screen::SENSOR);
    }

    if (right == 1) {
        TFT_ILI9225_MonitorDisplay::getInstance().setScreen(Screen::TIME);
    }

    String logText = "LEFT=";
    logText += left;
    logText += " RIGHT=";
    logText += right;
    logText += " UP=";
    logText += up;
    logText += " DOWN=";
    logText += down;    
    logText += " BUTTON=";
    logText += button;

    //SerialLogger::getInstance().log(LogLevel::DEBUG, "MonitorCore::readInput()", logText);
}