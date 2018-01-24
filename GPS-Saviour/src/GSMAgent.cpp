/**
 * GSMAgent.cpp
 * Purpose: implements class GSMAgent
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/GSMAgent.h"

/* --- constructors / destructors --- */

/* --- miscellaneous --- */
/**
 * @brief GSMAgent::init
 * @param partnerTelephoneNumbers_
 * @param telephoneNumber_
 */
void GSMAgent::init(vector<int> partnerTelephoneNumbers_, int telephoneNumber_) {
    cout << "initialized GSMAgent" << endl;
    setPartnerTelephoneNumbers(partnerTelephoneNumbers_);
    setTelephoneNumber(telephoneNumber_);
}

/* --- request and receive data --- */
/**
 * @brief GSMAgent::sendRequestForLogging
 */
void GSMAgent::sendRequestForLogging() {

}

/**
 * @brief GSMAgent::sendRequesForData
 */
void GSMAgent::sendRequesForData() {

}

/**
 * @brief GSMAgent::sendData
 */
void GSMAgent::sendData() {

}

/**
 * @brief receiveData
 */
void GSMAgent::receiveData() {

}

/**
 * @brief receiveRequest
 */
void GSMAgent::receiveRequest() {

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
void GSMAgent::receiveGSMPackage() {

}

/**
 * @brief sendGSMPackage
 */
void GSMAgent::sendGSMPackage() {

}

/* --- authentication --- */
/**
 * @brief checkAuthenticationOfRequest
 * @return
 */
bool checkAuthenticationOfRequest() {

}

