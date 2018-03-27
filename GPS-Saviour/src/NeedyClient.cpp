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
 *
 * initializes
 *  - storingTimer, sendingTimer
 *  - storingStatus, sendingStatus
 *  - continouslySendingFinishedUntilTime
 * TODO
 */
void NeedyClient::init() {
    storingTimer.init(DEFAULT_STORING_TIMER_INTERVAL);
    sendingTimer.init(DEFAULT_SENDING_TIMER_INTERVAL);
    setStoringStatus(StoringStatus::storingDisabled);
    setSendingStatus(SendingStatus::sendingDisabled);
    setContinouslySendingFinishedUntilTime(0);
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

    // check if initialization package is received, if so initialize client
    checkReveivedInitialization();

    if (checkReceivedRequestForStatusChange()) {
        // process storing and sending tasks
        processTasks();
    } else {
        if (getAuthIsRequired()) {
            sendRequestForAuth();

            // wait until either auth package is received or timeout is up
            Timer authTimeOutTimer;
            authTimeOutTimer.init(WAIT_FOR_AUTH_PACKAGE_TIMEOUT);
            authTimeOutTimer.start();
            while ( (! authTimeOutTimer.checkTimerIsUp()) && (!checkReceivedAuthPackage())) {
                // wait
            }

            // if needy client was not able to receive an auth-package or
            // if the package was not valid send error-package
            // otherwise save the requested status (this defines which tasks to execute during processTasks())
            if (! checkAuthCompleted()) {
                if (authTimeOutTimer.checkTimerIsUp()) {
                    sendErrorPackage(AUTH_TIMEOUT_ERROR);
                } else {
                    sendErrorPackage(AUTH_INVALID_ERROR);
                }
            } else {
                saveRequestedStatus();
            }
        } else {
            saveRequestedStatus();
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

/**
 * NeedyClient::getSendingTimerInterval
 * @brief getter function of member variable sendingTimerInterval
 * @return value of the member variable sendingTimerInterval
 */
int NeedyClient::getSendingTimerInterval() const {
    return sendingTimerInterval;
}

/**
 * NeedyClient::setSendingTimerInterval
 * @brief setter function of member variable sendingTimerInterval
 * @param val_ new value for member variable sendingTimerInterval
 */
void NeedyClient::setSendingTimerInterval(int val_) {
    sendingTimerInterval = val_;
}

/**
 * NeedyClient::getStoringTimerInterval
 * @brief getter function of member variable storingTimerInterval
 * @return value of the member variable storingTimerInterval
 */
int NeedyClient::getStoringTimerInterval() const {
    return storingTimerInterval;
}

/**
 * NeedyClient::setStoringTimerInterval
 * @brief setter function of member variable storingTimerInterval
 * @param val_ new value for member variable storingTimerInterval
 */
void NeedyClient::setStoringTimerInterval(int val_) {
    storingTimerInterval = val_;
}

/**
 * NeedyClient::getContinouslySendingFinishedUntilTime
 * @brief getter function of member variable continouslySendingFinishedUntilTime
 * @return value of the member variable continouslySendingFinishedUntilTime
 */
int NeedyClient::getContinouslySendingFinishedUntilTime() const {
    return continouslySendingFinishedUntilTime;
}

/**
 * NeedyClient::setContinouslySendingFinishedUntilTime
 * @brief setter function of member variable continouslySendingFinishedUntilTime
 * @param val_ new value for member variable continouslySendingFinishedUntilTime
 */
void NeedyClient::setContinouslySendingFinishedUntilTime(int val_) {
    continouslySendingFinishedUntilTime = val_;
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
 * @brief check if a status change was requested (by pressing a button or receiving a GSM-package)
 * @return returns true if any status change was requested
 * TODO
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
 * @brief checks if GSMAgent has received an authentication package
 * @return returns true if a valid authentication package has been received
 * TODO
 */
bool NeedyClient::checkReceivedAuthPackage() {

}

/**
 * NeedyClient::checkAuthCompleted
 * @brief checks if received authentication package was valid
 * @return returns true if received authentication package was valid
 * TODO
 */
bool NeedyClient::checkAuthCompleted() {

}

/**
 * NeedyClient::sendErrorPackage 
 * @brief sends an error-package with the given error-text
 * @param errorText_ error text to send
 * TODO
 */
void NeedyClient::sendErrorPackage(const string &errorText_) {

}

/**
 * NeedyClient::saveRequestedStatus
 * @brief save requested status in member variables storingStatus and sendingStatus
 *
 * This function is used to save the requested storing-status and sending-status
 * in the member variables storingStatus and sendingStatus.
 * Use this function if auth is not necessary or the auth was finished successfully
 * TODO
 */
void NeedyClient::saveRequestedStatus() {

}

/* --- sub execution functions --- */
/**
 * NeedyClient::storeGPSData
 * @brief store the current GPS-data of the GPSAgent depending on storing status
 *
 * This function stores the current GPS-data of the GPSAgent.
 *  - if storingStatus == storeSingleData store the current GPS-data and reset the storingStatus
 *  - if storingStatus == storeContinuously store the current GPS-data if storingTimer is up
 */
void NeedyClient::storeGPSData() {
    // storingStatus == storeSingleData store the current GPS-data and reset the storingStatus
    if (getStoringStatus() == StoringStatus::storeSingleData) {
        storeData();
        setStoringStatus(StoringStatus::storingDisabled);

    // if storingStatus == storeContinuously store the current GPS-data if storingTimer is up
    } else if (getStoringStatus() == StoringStatus::storeContinuously) {
        if (!storingTimer.checkTimerIsStarted()) {
            storingTimer.start();
        }

        if (storingTimer.checkTimerIsUp()) {
            storeData();
            storingTimer.stopAndReset();
            storingTimer.start();
        }
    }
}

/**
 * NeedyClient::storeData
 * @brief tell GPSAgent to store the current GPSAgent
 */
void NeedyClient::storeData() {
    gpsAgent.receiveAndStoreGeoData();
}


/**
 * NeedyClient::sendData
 * @brief send stored data out of the GPSAgent by the GSMAgent
 *
 * This function sends stored GPS-data by using the GSMAgent.
 * Depending on the sendingStatus different amounts of data are sent
 *  - if sendingStatus == sendSingleData : send the last stored value, reset sendingStatus
 *  - if sendingStatus == sendSingleDataArray : send all values between startTime and endTime
 *  - if sendingStatus == check if sendingTimerIsUp and send all values which are not sent yet
 */
void NeedyClient::sendData() {
    vector<GeoData> storedGeoData = gpsAgent.getStoredGeoData();
    vector<GeoData> geoDataToSend;

    // if sendingStatus == sendSingleData
    // send last stored value
    if (getSendingStatus() == SendingStatus::sendSingleData) {
        geoDataToSend.push_back(storedGeoData[storedGeoData.size() - 1]);
        gsmAgent.sendData(geoDataToSend);
        setSendingStatus(SendingStatus::sendingDisabled);

    // if sendingStatus == sendSingleDataArray
    // send all values between startTime and endTime
    } else if (getSendingStatus() == SendingStatus::sendSingleDataArray) {

        for(unsigned int i = 0; i < storedGeoData.size(); i++) {
            if ( (storedGeoData[i].getCTime() >= getRequestedDataArrayStartTime()) &&
                 (storedGeoData[i].getCTime() <= getRequestedDataArrayEndTime()) ) {
                geoDataToSend.push_back(storedGeoData[i]);
            }
        }
        gsmAgent.sendData(geoDataToSend);

    // if sendingStatus == sendContinuously
    // check if sendingTimerIsUp and send all values which are not sent yet
    } else if (getSendingStatus() == SendingStatus::sendContinuously) {
        // start timer if necessary
        if (! sendingTimer.checkTimerIsStarted()) {
            sendingTimer.start();
        }

        // if sending-interval is up send all values which were stored later than
        // getContinouslySendingFinishedUntilTime and restart timer
        if (sendingTimer.checkTimerIsUp()) {

            // find values to send
            for(unsigned int i = 0; i < storedGeoData.size(); i++) {
                if (storedGeoData[i].getCTime() > getContinouslySendingFinishedUntilTime()) {
                    geoDataToSend.push_back(storedGeoData[i]);
                }
            }
            // send data
            gsmAgent.sendData(geoDataToSend);

            // restart timer
            sendingTimer.stopAndReset();
            sendingTimer.start();
            setContinouslySendingFinishedUntilTime(sendingTimer.getCurrentTime());
        }

    }
}

