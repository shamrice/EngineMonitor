#ifndef __MONITOR_DISPLAY_H__
#define __MONITOR_DISPLAY_H__

#include "colors/Color.h"

class MonitorDisplay {

    public:
        virtual void print(int x, int y, const char *text, Color color);

};

#endif