/**
 * GPSAgent.cpp
 * Purpose: implements class GPSAgent
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/GPSAgent.h"

/* ---------- PUBLIC FUNCTIONS ---------- */

/* --- constructors / destructors --- */
/**
 * GPSAgent::GPSAgent
 * @brief constructor of class GPSAgent
 * The constructor of class GPSAgent sets the member connectionEstablished to
 * false and starts the initialization of the GPSAgent
 */
GPSAgent::GPSAgent() {
    setGPSConnectionEstablished(false);
    init();
}

/* --- initialize / receive --- */

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
    if (! getGPSConnectionEstablished()) {
        setGPSConnectionEstablished(true);
        cout << "initialized GPSAgent" << endl;
    }
    return getGPSConnectionEstablished();
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
        receiveDataFromGPSChip();
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

/* ---------- PRIVATE FUNCTIONS ---------- */

/* --- getters / setters --- */
/**
 * GPSAgent::setGPSConnectionEstablished
 * @brief sets the class member connectionEstablished by the given value val_
 * @param val_ new value for class member connectionEstablished
 */
void GPSAgent::setGPSConnectionEstablished(bool val_) {
    gpsConnectionEstablished = val_;
}

/**
 * GPSAgent::getGPSConnectionEstablished
 * @brief returns the current value of the class member connectionEstablished
 * @return returns the current value of the class member connectionEstablished
 */
bool GPSAgent::getGPSConnectionEstablished() const {
    return gpsConnectionEstablished;
}

/**
 * GPSAgent::getStoredGeoData
 * @brief returns the class member storedGeoData
 * @return returns the class member storedGeoData
 */
vector<GeoData> GPSAgent::getStoredGeoData() const {
    return storedGeoData;
}

/* --- receive / convert / save --- */
/**
 * GPSAgent::receiveDataFromGPSChip
 * @brief receive raw data from GPS-chip
 *
 * This function receives the raw binary data from the hardware GPS-chip.
 */
void GPSAgent::receiveDataFromGPSChip()  {
    cout << "Received Data From GPS Chip" << endl;
}

/**
 * GPSAgent::testRecievedData
 * @brief checks if received data is valid
 * @return returns true if received data is valid
 */
bool GPSAgent::testRecievedData() const {
   return true;
}

/**
 * GPSAgent::saveGeoData
 * @brief save GeoData-object receivedData_ in the vector storedGeoData
 * @param receivedData_ GeoData-object to save in vector
 *
 * This function saves the GeoData-object receivedData_ within the vector
 * of GeoData storedGeoData.
 */
void GPSAgent::saveGeoData(const GeoData& receivedData_) {
    cout << "GeoData Dummy received" << endl;
    storedGeoData.push_back(receivedData_);
}

/**
 * GPSAgent::convertReceivedDataIntoGeoData
 * @brief convert raw gps-data into GeoData-object
 * @return return GeoData-object which contains the data of the raw gps-data
 */
GeoData GPSAgent::convertReceivedDataIntoGeoData() const {
    return buffer.getGeoData();
}


