/**
 * GSMPackage.cpp
 * Purpose: implements class GSMPackage
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "GSMPackage.h"
#include "Types.h"

void GSMPackage::setPackageType(PackageType packageType_) {
    packageType = packageType_;
}

PackageType GSMPackage::getPackageType() {
    return packageType;
}

void GSMPackage::setGeoDataToSend(vector<GeoData> geoDataToSend_) {
    geoDataToSend = geoDataToSend_;
}

vector<GeoData> GSMPackage::getGeoDataToSend() {
    return geoDataToSend;
}

vector<int> GSMPackage::getReceipientTelephoneNumbers() const
{
    return receipientTelephoneNumbers;
}

void GSMPackage::setReceipientTelephoneNumbers(const vector<int> &val_)
{
    receipientTelephoneNumbers = val_;
}

int GSMPackage::getSenderTelephoneNumber() const
{
    return senderTelephoneNumber;
}

void GSMPackage::setSenderTelephoneNumber(int val_)
{
    senderTelephoneNumber = val_;
}
