/**
 * GPSAgent.h
 * Purpose: defines class GPSAgent
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef GPSAgent_H
#define GPSAgent_H

#include <iostream>
#include <vector>

#include "GeoData.h"
#include "TestBuffer.h"


using namespace std;

/**
 * @brief The GPSAgent class handles all GPS-functions within this project
 *
 * The GPSAgent class handles all GPS functionality for this project.
 * This includes on one hand receiving raw data gps data, by interfacing a
 * gps-hardware sensor.
 * On the other hand this class implements functions for interpreting
 * the raw gps data and converting it into a GeoData-object.
 * Once the data is converted into a GeoData-object it is stored within a
 * vector of GeoData-objects.
 */
class GPSAgent {
    public:
        /* --- constructors / destructors --- */
        GPSAgent();

        /* --- miscellaneous --- */
        bool init();
        bool receiveGeoData();
        void receiveDataFromGPSChip() const;
        bool testRecievedData();
        void saveGeoData(GeoData receivedData_);
        GeoData convertReceivedDataIntoGeoData() const;

        /* --- getters / setters --- */
        void setConnectionEstablished(bool val_);
        bool getConnectionEstablished() const;

private:
    bool connectionEstablished;
    vector<GeoData> storedGeoData;
    // for testing purposes
    TestBuffer& buffer = TestBuffer::getInstance();

};

#endif // GPSAgent_H
