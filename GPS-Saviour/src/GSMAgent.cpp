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
    setPartnerTelephoneNumbers(partnerTelephoneNumbers_);
    setTelephoneNumber(telephoneNumber_);
    if (! getGSMConnectionEstablished()) {
        setGSMConnectionEstablished(true);
        cout << "GSMConnectionEstablished" << endl;
    }
   cout << "initialized GSMAgent" << endl;
}

/* --- request and receive data --- */

/**
 * @brief GSMAgent::sendRequestForAuth
 *
 * send an request for authentification to all stored TelephoneNumbers
 * this is used every time an GSMPackage is recieved
 */
void GSMAgent::sendRequestForAuth() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestForAuth);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);

}


/**
 * @brief GSMAgent::sendRequestForStartLogging
 *
 * sends an logging request to all stored NeedyClients (number selection will be added)
 */
void GSMAgent::sendRequestForStartLogging() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestStartLogging);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendRequestForStopLogging
 *
 * sends an request to all stored NeedyClients to Stop logging
 */
void GSMAgent::sendRequestForStopLogging() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestStopLogging);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendRequesForSingleData
 *
 * sends an request for single data to all stored NeedyClienets (number selection will be added)
 */
void GSMAgent::sendRequestForSingleData() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestSingleData);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendRequestForSingleDataArray
 *
 * sends an request for an single data vector, which contains all data points between the timestemps set in
 * the given timestempsToSend, to all stored NeedyClienets (number selection will be added)
 */
void GSMAgent::sendRequestForSingleDataArray(const vector<GeoData> &timestempsToSend_) const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestSingeDataArray);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    gsmPackageToSend.setGeoDataToSend(timestempsToSend_);
    sendGSMPackage(gsmPackageToSend);

}

/**
 * @brief GSMAgent::sendRequestForContiniouslyData
 *
 * sends an request to start logging and continiously sending data
 */
void GSMAgent::sendRequestForStartContiniouslyData() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestStartContiniouslyData);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendRequestForStopContiniouslyData
 *
 * sends an request to stop logging and continiously sending data
 */
void GSMAgent::sendRequestForStopContiniouslyData() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::requestStopContiniouslyData);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief GSMAgent::sendData
 *
 * sends Data
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
 * @brief GSMAgent::sendAuth
 *
 * sends Authentification
 */
void GSMAgent::sendAuth() const {
    GSMPackage gsmPackageToSend;
    gsmPackageToSend.setPackageType(PackageType::sendAuth);
    gsmPackageToSend.setReceipientTelephoneNumbers(getPartnerTelephoneNumbers());
    gsmPackageToSend.setSenderTelephoneNumber(getTelephoneNumber());
    sendGSMPackage(gsmPackageToSend);
}

/**
 * @brief receiveData
 *
 * receive Data
 */
void GSMAgent::receiveData() {
    GSMPackage gsmPackageToReceive;
    gsmPackageToReceive = receiveGSMPackage();
    if (gsmPackageToReceive.getPackageType() == PackageType::sendData) {
        vector<GeoData> geoDataToSend = gsmPackageToReceive.getGeoDataToSend();
        receivedData.insert(receivedData.end(),geoDataToSend.begin(),geoDataToSend.end());
    }
}

/**
 * @brief receiveRequest
 *
 * check type of recieved GSMPackage, stores the type last of the last GSMPackage and answers the received Packages depending on the type
 */
GSMPackage GSMAgent::receiveRequest() {
    return receiveGSMPackage();
}


/* --- getters / setters --- */

/**
 * @brief GSMAgent::setGSMConnectionEstablished
 * @param val_
 */
void GSMAgent::setGSMConnectionEstablished(bool val_) {
    gsmConnetionEstablished = val_;
}

/**
 * @brief GSMAgent::getGSMConnectionEstablished
 * @return
 */
bool GSMAgent::getGSMConnectionEstablished() const {
    return gsmConnetionEstablished;
}

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

