/**
 * GPSAgent.h
 * Purpose: defines class GPSAgent
 *
 * @author TODO2
 * @version 1.0
 */

#ifndef GPSAgent_H
#define GPSAgent_H

#include <iostream>
#include <vector>

#include "GeoData.h"
#include "TestBuffer.h"


using namespace std;

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
        bool getConnectionEstablished();

private:
    bool connectionEstablished;
    vector<GeoData> storedGeoData;
    TestBuffer& buffer = TestBuffer::getInstance();

};

#endif // GPSAgent_H
