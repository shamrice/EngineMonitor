#include "ApplicationServices.h"

ApplicationServices::ApplicationServices() {  
    monitorCore.refreshSensorValues();
}

void ApplicationServices::run() {
    
    monitorCore.displayScreen();      
    int refreshFrame = 0;

    while (true) {

        //manage how often display is drawn for refrsh.
        if (refreshFrame > configuration.getDisplayRefreshFrequency()) {    
                          
            monitorCore.displayScreen();      
            refreshFrame = 0;
        }

        monitorCore.refreshSensorValues();   
        monitorCore.readInput();           

        refreshFrame++;
        //delay(10);  
    }
}