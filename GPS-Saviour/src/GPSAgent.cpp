/**
 * GPSAgent.cpp
 * Purpose: implements class GPSAgent
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/GPSAgent.h"

/* --- getters / setters --- */
/**
 * GPSAgent::setConnectionEstablished
 * @brief sets the class member connectionEstablished by the given value val_
 * @param val_ new value for class member connectionEstablished
 */
void GPSAgent::setConnectionEstablished(bool val_) {
    connectionEstablished = val_;
}

/**
 * GPSAgent::getConnectionEstablished
 * @brief returns the current value of the class member connectionEstablished
 * @return returns the current value of the class member connectionEstablished
 */
bool GPSAgent::getConnectionEstablished() const {
    return connectionEstablished;
}

/* --- constructors / destructors --- */
/**
 * GPSAgent::GPSAgent
 * @brief constructor of class GPSAgent
 * The constructor of class GPSAgent sets the member connectionEstablished to
 * false and starts the initialization of the GPSAgent
 */
GPSAgent::GPSAgent() {
    setConnectionEstablished(false);
    init();
}

/* --- miscellaneous --- */

/**
 * GPSAgent::init
 * @brief initializes the GPSAgent class and GPS-chip
 * @return returns true if initialization has succeeded
 *
 * If the connection is not established yet, this initializes the GPSAgent object
 * and the GPS-chip. After initialization is finished and connecton is etablished the
 * member connectionEstablished is set to true.
 */
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
 * This function receives the raw gps-data from the gps-chip and converts it
 * into a GeoData-object. After conversion the GeoData-object is added to
 * the vector storedGeoData.
 */
bool GPSAgent::receiveGeoData() {
    // if everything is initialized / connection is established
    if (init()){
        GeoData receivedData;
        // receive, convert and save data
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
 * GPSAgent::saveGeoData
 * @brief save GeoData-object receivedData_ in the vector storedGeoData
 * @param receivedData_ GeoData-object to save in vector
 *
 * This function saves the GeoData-object receivedData_ within the vector
 * of GeoData storedGeoData.
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


