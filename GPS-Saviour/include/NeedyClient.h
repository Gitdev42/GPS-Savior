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

        /* --- initialization / main execution function --- */
        void init();
        void execute();

        /* --- getters / setters --- */


        bool getAuthIsRequired() const;
        void setAuthIsRequired(bool val_);

private:
        GPSAgent gpsAgent;
        GSMAgent gsmAgent;

        bool authIsRequired;


        /* --- Needy Features --- */

        /* --- main execution functions --- */
        void checkReveivedInitialization();
        bool checkReceivedRequesForStatusChange();
        void processTasks();
        void sendRequestForAuth();
        bool checkReceivedAuthPackage();
        bool checkTimeoutIsUp();
        bool checkAuthCompleted();
        void sendErrorPackage();
        void saveRequestedStatus();



};

#endif // NeedyClient_H
