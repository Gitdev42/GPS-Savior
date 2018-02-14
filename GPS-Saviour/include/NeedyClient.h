/**
 * TODO1.h
 * Purpose: defines class TODO1
 *
 * @author TODO2
 * @version 1.0
 */

#ifndef NeedyClient_H
#define NeedyClient_H

#include <iostream>
#include "Types.h"
#include "GPSAgent.h"
#include "GSMAgent.h"

using namespace std;

class NeedyClient {
    public:
        /* --- constructors / destructors --- */
        NeedyClient() {};
        void init();
        void execute();





        /* --- getters / setters --- */

    private:
        GPSAgent gpsAgent;
        GSMAgent gsmAgent;


        /* --- Needy Features --- */

        bool buttonActiv;
        bool receiveActiv;
        bool secureAreaActiv;
        bool buttonPressed;
        bool requestReceived;
        bool outsideSecureArea;


};

#endif // NeedyClient_H
