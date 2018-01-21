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

using namespace std;

class GPSAgent {
    public:
        /* --- constructors / destructors --- */
        GPSAgent() {};

        /* --- miscellaneous --- */
        void init();
        void receiveGeoData();
        void receiveDataFromGPSChip() const;
        void saveGeoData(GeoData);
        GeoData convertReceivedDataIntoGeoData() const;

private:
    vector<GeoData> storedGeoData;

};

#endif // GPSAgent_H
