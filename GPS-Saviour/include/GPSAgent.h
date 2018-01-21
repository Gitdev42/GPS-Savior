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
#include <stdlib.h>     /* srand, rand */

#include "GeoData.h"


using namespace std;

class GPSAgent {
    public:
        /* --- constructors / destructors --- */
        GPSAgent() {};

        /* --- miscellaneous --- */
        void init();
        void receiveGeoData();
        void receiveDataFromGPSChip() const;
        bool testRecievedData();
        void saveGeoData(GeoData);
        GeoData convertReceivedDataIntoGeoData() const;

        /* --- dummy test functions --- */
        unsigned int getTimeMs64() const;

private:
    vector<GeoData> storedGeoData;

};

#endif // GPSAgent_H
