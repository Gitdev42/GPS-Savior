/**
 * TODO1.cpp
 * Purpose: implements class TODO1
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/NeedyClient.h"


/* --- getters / setters --- */




void NeedyClient::init() {
    vector<int> temp;
    gpsAgent.init();
    gsmAgent.init(temp,0);
}

void NeedyClient::execute() {
    GSMPackage gsmPackageToReceive;
    if (buttonActiv) {
        if (buttonPressed) {
            if (! gpsAgent.getGPSConnectionEstablished()) {
                 gpsAgent.init();
                 cout << "initialized GPSAgent" << endl;
            }
            gsmAgent.sendData(gpsAgent.getStoredGeoData());
        }
    } else if (receiveActiv) {
        if (requestReceived)  {
            gsmPackageToReceive = gsmAgent.receiveRequest();
            gsmAgent.sendRequestForAuth();

            /**r

            hier könnte ihre werbung stehen ;)



            **/
        }

    } else if (secureAreaActiv) {
        if (outsideSecureArea) {
            gsmAgent.sendData(gpsAgent.getStoredGeoData());
        }
    }

}
