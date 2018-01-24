/**
 * GPSAgent.cpp
 * Purpose: implements class GPSAgent
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/GPSAgent.h"

/* --- getters / setters --- */
void GPSAgent::setConnectionEstablished(bool val_) {
    connectionEstablished = val_;
}

bool GPSAgent::getConnectionEstablished() {
    return connectionEstablished;
}

GPSAgent::GPSAgent() {
    setConnectionEstablished(false);
    init();
}

bool GPSAgent::init() {
    if (! getConnectionEstablished()) {
        setConnectionEstablished(true);
        cout << "initialized GPSAgent" << endl;
    }
    return getConnectionEstablished();
}

/**
 * GPSAgent::receiveGeoData
 * @brief receives and stores geo-data from gps-sensor
 * @return true if GPSAgent was able to receive and store data
 *
 * This function does bla bla bla bla
 * bla bla bla bla
 * bla bla bla bla
 * bla bla bla bla
 * bla bla bla bla
 * bla bla bla bla
 */
bool GPSAgent::receiveGeoData() {
    if (init()){
        GeoData receivedData;
        if (testRecievedData()){
            receivedData = convertReceivedDataIntoGeoData();
            saveGeoData(receivedData);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/**
 * @brief GPSAgent::saveGeoData
 * @param receivedData_
 */
void GPSAgent::saveGeoData(GeoData receivedData_) {
    cout << "GeoData Dummy received" << endl;
    storedGeoData.push_back(receivedData_);
}

void GPSAgent::receiveDataFromGPSChip() const {
    cout << "Received Data From GPS Chip" << endl;
}

bool GPSAgent::testRecievedData()
{
   return true;
}

GeoData GPSAgent::convertReceivedDataIntoGeoData() const {
    buffer.createDummyGeoData();
    return buffer.getGeoData();
}


