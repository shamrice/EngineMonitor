#include "ApplicationServices.h"

ApplicationServices::ApplicationServices() {  
    monitorCore.refreshSensorValues();
}

void ApplicationServices::run() {
    
    int refreshFrame = 0;

    while (true) {

        //manage how often sensor values are polled for refrsh.
        if (refreshFrame > configuration.getSensorValueRefreshFrequency()) {
            monitorCore.refreshSensorValues();
            refreshFrame = 0;
        }

        monitorCore.displaySensorValues();      

        refreshFrame++;
        delay(100);  
    }
}