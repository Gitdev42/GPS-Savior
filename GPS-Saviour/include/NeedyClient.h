/**
 * NeedyClient.h
 * Purpose: defines class NeedyClient
 *
 * @author Wall.Of.Death
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



};

#endif // NeedyClient_H
