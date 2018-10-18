#ifndef __APPLICATION_SERVICES_H__
#define __APPLICATION_SERVICES_H__

#include "MonitorCore.h"

class ApplicationServices {

    public: 
        ApplicationServices();
        void run();

    private:
        MonitorCore &monitorCore = MonitorCore::getInstance();        

};

#endif