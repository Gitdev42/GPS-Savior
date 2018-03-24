/**
 * GSMPackage.h
 * Purpose: defines class GSMPackage
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef GSMPACKAGE_H
#define GSMPACKAGE_H

#include <vector>
#include "Types.h"
#include "GeoData.h"

using namespace std;

class GeoData;

class GSMPackage {
    public:
        /* --- constructors / destructors --- */
        GSMPackage() {};

        /* --- miscellaneous --- */

        /* --- getters / setters --- */
        void setPackageType(PackageType packageType_);
        PackageType getPackageType();

        void setGeoDataToSend(vector<GeoData> geoDataToSend_);
        vector<GeoData> getGeoDataToSend();

        void setReceipientTelephoneNumbers(const vector<int> &val_);
        vector<int> getReceipientTelephoneNumbers() const;

        void setSenderTelephoneNumber(int val_);
        int getSenderTelephoneNumber() const;

private:
        PackageType packageType;
        vector<GeoData> geoDataToSend;
        vector<int> receipientTelephoneNumbers;
        int senderTelephoneNumber;

};

#endif // GSMPACKAGE_H
