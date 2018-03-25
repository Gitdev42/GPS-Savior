/**
 * NeedyClient.cpp
 * Purpose: implements class NeedyClient
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/NeedyClient.h"

/* --- getters / setters --- */

bool NeedyClient::getAuthIsRequired() const {
    return authIsRequired;
}

void NeedyClient::setAuthIsRequired(bool value) {
    authIsRequired = value;
}

StoringStatus NeedyClient::getStoringStatus() const
{
    return storingStatus;
}

void NeedyClient::setStoringStatus(const StoringStatus &val_)
{
    storingStatus = val_;
}

SendingStatus NeedyClient::getSendingStatus() const
{
    return sendingStatus;
}

void NeedyClient::setSendingStatus(const SendingStatus &val_)
{
    sendingStatus = val_;
}


/* --- Needy Features --- */

/* --- main execution functions --- */

void NeedyClient::init() {

}

void NeedyClient::execute() {
    while(true) {


        // check if initialization package is received, if so initialize client
        checkReveivedInitialization();

        if (checkReceivedRequesForStatusChange()) {
            // process storing and sending tasks
            processTasks();
        } else {
            if (getAuthIsRequired()) {
                sendRequestForAuth();

                // wait until either auth package is received or timeout is up
                while ( (! checkTimeoutIsUp() ) && (!checkReceivedAuthPackage())) {
                    // wait
                }

                if (! checkAuthCompleted()) {
                    sendErrorPackage();
                } else {
                    saveRequestedStatus();
                }
            } else {
                saveRequestedStatus();
            }
        }
    }
}

/**
 * @brief NeedyClient::checkReveivedInitialization
 * feature not enabled yet
 */
void NeedyClient::checkReveivedInitialization() {

}

bool NeedyClient::checkReceivedRequesForStatusChange() {

}

/**
 * @brief NeedyClient::processTasks
 */
void NeedyClient::processTasks() {
    storeGPSData();
    sendData();
}

void NeedyClient::sendRequestForAuth()
{

}

bool NeedyClient::checkReceivedAuthPackage()
{

}

bool NeedyClient::checkTimeoutIsUp()
{

}

bool NeedyClient::checkAuthCompleted()
{

}

void NeedyClient::sendErrorPackage()
{

}

void NeedyClient::saveRequestedStatus()
{

}

/* --- sub execution functions --- */
void NeedyClient::storeGPSData() {
    if (getStoringStatus() == StoringStatus::storeSingleData) {
        storeData();
    } else if (getStoringStatus() == StoringStatus::storeContinuously) {
        if (!storingTimer.checkTimerIsStarted()) {
            storingTimer.start();
        }
        if (storingTimer.checkTimerIsUp()) {
            storeData();
        }
    }
}

void NeedyClient::storeData() {
    gpsAgent.receiveAndStoreGeoData();
}


void NeedyClient::sendData() {
    vector<GeoData> storedGeoData = gpsAgent.getStoredGeoData();
    vector<GeoData> geoDataToSend;

    // send last stored value
    if (getSendingStatus() == SendingStatus::sendSingleData) {
        geoDataToSend.push_back(storedGeoData[storedGeoData.size() - 1]);
        gsmAgent.sendData(geoDataToSend);
    } else if (getSendingStatus() == SendingStatus::sendSingleDataArray) {

    }
}

