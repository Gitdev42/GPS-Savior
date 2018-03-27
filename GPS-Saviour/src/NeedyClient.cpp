/**
 * NeedyClient.cpp
 * Purpose: implements class NeedyClient
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/NeedyClient.h"

/* --- constructors / destructors --- */

/* --- initialization / main execution function --- */
/**
 * NeedyClient::init
 * @brief initializes the class NeedyClient
 * TODO
 */
void NeedyClient::init() {

}

/**
 * NeedyClient::execute
 * @brief main execution function of the class NeedyClient
 * The function execute is the main execution function of the class NeedyClient.
 * Run this function in an endless loop after calling NeedyClient.init().
 *  -- check if initialization package was received
 *  -- check if any status change (e.g. by pressing a button or receiving a GSM-package) was requested
 *     -- if necessary check authentication of request
 *        -- save requested status
 *        -- run storing data - and sending data - tasks
 */
void NeedyClient::execute() {
    while(true) { // TODO


        // check if initialization package is received, if so initialize client
        checkReveivedInitialization();

        if (checkReceivedRequestForStatusChange()) {
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

/* --- getters / setters --- */
/**
 * NeedyClient::getAuthIsRequired
 * @brief getter function of member variable authIsRequired
 * @return value of the member variable authIsRequired
 */
bool NeedyClient::getAuthIsRequired() const {
    return authIsRequired;
}

/**
 * NeedyClient::setAuthIsRequired
 * @brief setter function of member variable authIsRequired
 * @param val_ new value for member variable authIsRequired
 */
void NeedyClient::setAuthIsRequired(bool val_) {
    authIsRequired = val_;
}

/**
 * NeedyClient::getStoringStatus
 * @brief getter function of member variable storingStatus
 * @return value of the member variable storingStatus
 */
StoringStatus NeedyClient::getStoringStatus() const {
    return storingStatus;
}

/**
 * NeedyClient::setStoringStatus
 * @brief setter function of member variable storingStatus
 * @param val_ new value for member variable storingStatus
 */
void NeedyClient::setStoringStatus(const StoringStatus &val_) {
    storingStatus = val_;
}

/**
 * NeedyClient::getSendingStatus
 * @brief getter function of member variable sendingStatus
 * @return value of the member variable sendingStatus
 */
SendingStatus NeedyClient::getSendingStatus() const {
    return sendingStatus;
}

/**
 * NeedyClient::setSendingStatus
 * @brief setter function of member variable sendingStatus
 * @param val_ new value for member variable sendingStatus
 */
void NeedyClient::setSendingStatus(const SendingStatus &val_) {
    sendingStatus = val_;
}

/**
 * NeedyClient::getRequestedDataArrayStartTime
 * @brief getter function of member variable requestedDataArrayStartTime
 * @return value of the member variable requestedDataArrayStartTime
 */
int NeedyClient::getRequestedDataArrayStartTime() const {
    return requestedDataArrayStartTime;
}

/**
 * NeedyClient::setRequestedDataArrayStartTime
 * @brief setter function of member variable requestedDataArrayStartTime
 * @param val_ new value for member variable requestedDataArrayStartTime
 */
void NeedyClient::setRequestedDataArrayStartTime(int val_) {
    requestedDataArrayStartTime = val_;
}

/**
 * NeedyClient::getRequestedDataArrayEndTime
 * @brief getter function of member variable requestedDataArrayEndTime
 * @return value of the member variable requestedDataArrayEndTime
 */
int NeedyClient::getRequestedDataArrayEndTime() const {
    return requestedDataArrayEndTime;
}

/**
 * NeedyClient::setRequestedDataArrayEndTime
 * @brief setter function of member variable requestedDataArrayEndTime
 * @param val_ new value for member variable requestedDataArrayEndTime
 */
void NeedyClient::setRequestedDataArrayEndTime(int val_) {
    requestedDataArrayEndTime = val_;
}

/* --- main execution functions --- */

/**
 * NeedyClient::checkReveivedInitialization
 * @brief checks if GSMAgent has received an initialization package and initializes NeedyClient
 * TODO : feature not enabled yet
 */
void NeedyClient::checkReveivedInitialization() {

}

/**
 * NeedyClient::checkReceivedRequestForStatusChange
 * @brief
 * @return
 */
bool NeedyClient::checkReceivedRequestForStatusChange() {

}

/**
 * NeedyClient::processTasks
 * @brief process all enabled tasks (e.g. store GPS data and send data by GSM)
 */
void NeedyClient::processTasks() {
    storeGPSData();
    sendData();
}

/**
 * NeedyClient::sendRequestForAuth
 * @brief send a request for authentication
 * TODO
 */
void NeedyClient::sendRequestForAuth() {

}

/**
 * NeedyClient::checkReceivedAuthPackage
 * @brief checks if GSMAgent has received an authentication package and checks if auth is okay
 * TODO
 * @return
 */
bool NeedyClient::checkReceivedAuthPackage() {

}

/**
 * NeedyClient::checkAuthCompleted
 * @brief
 * @return
 */
bool NeedyClient::checkAuthCompleted() {

}

/**
 * NeedyClient::sendErrorPackage
 * @brief
 */
void NeedyClient::sendErrorPackage() {

}

/**
 * NeedyClient::saveRequestedStatus
 * @brief
 */
void NeedyClient::saveRequestedStatus() {

}

/* --- sub execution functions --- */
/**
 * NeedyClient::storeGPSData
 * @brief
 */
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

/**
 * NeedyClient::storeData
 * @brief
 */
void NeedyClient::storeData() {
    gpsAgent.receiveAndStoreGeoData();
}


/**
 * NeedyClient::sendData
 * @brief
 */
void NeedyClient::sendData() {
    vector<GeoData> storedGeoData = gpsAgent.getStoredGeoData();
    vector<GeoData> geoDataToSend;

    // if SendingStatus == sendSingleData
    // send last stored value
    if (getSendingStatus() == SendingStatus::sendSingleData) {
        geoDataToSend.push_back(storedGeoData[storedGeoData.size() - 1]);
        gsmAgent.sendData(geoDataToSend);
    } else if (getSendingStatus() == SendingStatus::sendSingleDataArray) {
        // if SendingStatus == sendSingleDataArray
        // send all values between startTime and endTime
        for(int i = 0; i < storedGeoData.size(); i++) {
            if ( (storedGeoData[i].getCTime() >= getRequestedDataArrayStartTime()) &&
                 (storedGeoData[i].getCTime() <= getRequestedDataArrayEndTime()) ) {
                geoDataToSend.push_back(storedGeoData[i]);
            }
        }
        gsmAgent.sendData(geoDataToSend);
    } else if (getSendingStatus() == SendingStatus::sendContinuously) {
        // TODO
    }
}

