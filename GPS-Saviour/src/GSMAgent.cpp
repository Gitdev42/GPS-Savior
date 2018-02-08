/**
 * GSMAgent.cpp
 * Purpose: implements class GSMAgent
 *
 * @author TODO2
 * @version 1.0
 */

#include <iostream>
#include "../include/GSMAgent.h"

using namespace std;

/* --- constructors / destructors --- */

/* --- miscellaneous --- */
/**
 * @brief GSMAgent::init
 * @param partnerTelephoneNumbers_
 * @param telephoneNumber_
 *
 */
void GSMAgent::init(vector<int> partnerTelephoneNumbers_, int telephoneNumber_) {
    cout << "initialized GSMAgent" << endl;
    setPartnerTelephoneNumbers(partnerTelephoneNumbers_);
    setTelephoneNumber(telephoneNumber_);
}

/* --- request and receive data --- */

/**
 * @brief GSMAgent::sendRequestForAuth
 */
void GSMAgent::sendRequestForAuth() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestForAuth);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);

}

/**
 * @brief GSMAgent::sendRequestForLogging
 */
void GSMAgent::sendRequestForLogging() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestLogging);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendRequesForData
 */
void GSMAgent::sendRequestForData() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestData);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendData
 */
void GSMAgent::sendData(const vector<GeoData> &dataToSend_) const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::sendData);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    gsmPackageToSend.setGeoDataToSend(dataToSend_);
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief receiveData
 */
void GSMAgent::receiveData(GSMPackage gsmPackageToReceive_) {
    if (gsmPackageToReceive_.getPackageType() == PackageType::sendData) {
        vector<GeoData> geoDataToSend = gsmPackageToReceive_.getGeoDataToSend();
        receivedData.insert(receivedData.end(),geoDataToSend.begin(),geoDataToSend.end());
    }
}

/**
 * @brief receiveRequest
 */
void GSMAgent::receiveRequest(GSMPackage gsmPackageToReceive_) {
    if (gsmPackageToReceive_.getPackageType() == PackageType::requestForAuth) {

    } else if (gsmPackageToReceive_.getPackageType() == PackageType::requestLogging) {
        lastReceivedGSMPackage = gsmPackageToReceive_.getPackageType();
        sendRequestForAuth();
    } else if (gsmPackageToReceive_.getPackageType() == PackageType::requestData) {

    }

}

/* --- getters / setters --- */
/**
 * @brief GSMAgent::setPartnerTelephoneNumbers
 * @param val_
 */
void GSMAgent::setPartnerTelephoneNumbers(vector<int> val_) {
    partnerTelephoneNumbers = val_;
}

/**
 * @brief GSMAgent::getPartnerTelephoneNumbers
 * @return
 */
vector<int> GSMAgent::getPartnerTelephoneNumbers() const {
    return partnerTelephoneNumbers;
}

/**
 * @brief setTelephoneNumber
 * @param val_
 */
void GSMAgent::setTelephoneNumber(int val_) {
    telephoneNumber = val_;
}

/**
 * @brief GSMAgent::getTelephoneNumber
 * @return
 */
int GSMAgent::getTelephoneNumber() const {
    return telephoneNumber;
}

/* --- send / receive --- */
/**
 * @brief GSMAgent::receiveGSMPackage
 */
GSMPackage GSMAgent::receiveGSMPackage() {
    return buffer.getGsmPackage();
}

/**
 * @brief sendGSMPackage
 */
void GSMAgent::sendGSMPackage(GSMPackage gsmPackageToSend_) const {
    cout << "succesfully sent GSM Package" << endl;
    buffer.setGsmPackage(gsmPackageToSend_);
}

/* --- authentication --- */
/**
 * @brief checkAuthenticationOfRequest
 * @return
 */
bool checkAuthenticationOfRequest() {
return true;
}

