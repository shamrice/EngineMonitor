#include "ApplicationServices.h"

ApplicationServices::ApplicationServices() {  
    monitorCore.refreshSensorValues();
}

void ApplicationServices::run() {
    
    monitorCore.displaySensorValues();      
    int refreshFrame = 0;

    while (true) {

        //manage how often display is drawn for refrsh.
        if (refreshFrame > configuration.getDisplayRefreshFrequency()) {                        
            monitorCore.displaySensorValues();      
            refreshFrame = 0;
        }

        monitorCore.refreshSensorValues();              

        refreshFrame++;
        //delay(10);  
    }
}