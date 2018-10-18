#include "ApplicationServices.h"

ApplicationServices::ApplicationServices() {  }

void ApplicationServices::run() {
    
    while (true) {
        monitorCore.refreshSensorValues();
        monitorCore.displaySensorValues();        
    }
}