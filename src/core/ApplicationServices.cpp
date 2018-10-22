#include "ApplicationServices.h"

ApplicationServices::ApplicationServices() {  
    monitorCore.refreshSensorValues();
}

void ApplicationServices::run() {
    
    int refreshFrame = 0;

    while (true) {

        //manage how often display is drawn for refrsh.
        if (refreshFrame > configuration.getDisplayRefreshFrequency()) {                        
            monitorCore.displaySensorValues();      
            refreshFrame = 0;
        }

        monitorCore.refreshSensorValues();              

        refreshFrame++;
        //delay(100);  
    }
}