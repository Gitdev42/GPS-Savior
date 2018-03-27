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
#include "Timer.h"

using namespace std;

/**
 * @brief The NeedyClient class
 */
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

        StoringStatus getStoringStatus() const;
        void setStoringStatus(const StoringStatus &val_);

        SendingStatus getSendingStatus() const;
        void setSendingStatus(const SendingStatus &val_);

        int getRequestedDataArrayStartTime() const;
        void setRequestedDataArrayStartTime(int val_);

        int getRequestedDataArrayEndTime() const;
        void setRequestedDataArrayEndTime(int val_);

    private:
        /* --- class member variables --- */
        GPSAgent gpsAgent;
        GSMAgent gsmAgent;
        Timer storingTimer;

        bool authIsRequired;
        StoringStatus storingStatus;
        SendingStatus sendingStatus;

        int requestedDataArrayStartTime;
        int requestedDataArrayEndTime;

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

        /* --- sub execution functions --- */
        void storeGPSData();
        void storeData();
        void sendData();

};

#endif // NeedyClient_H
