#ifndef __TEST_MONITOR_DISPLAY_H__
#define __TEST_MONITOR_DISPLAY_H__

#include "MonitorDisplay.h"

class TestMonitorDisplay : public MonitorDisplay {

    public:
        void print(int x, int y, const char *text, Color color);

};

#endif