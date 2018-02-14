/**
 * SaviourClient.cpp
 * Purpose: implements class SaviourClient
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/SaviourClient.h"


/* --- constructors / destructors --- */
void SaviourClient::init() {
    vector<int> temp;
    gsmAgent.init(temp,0);
}

/* --- main execution function --- */
void SaviourClient::execute() {

}

/* --- send requests --- */
void SaviourClient::sendRequestForData() {
    gsmAgent.sendRequestForData();
}

void SaviourClient::sendRequestForLogging() {
    gsmAgent.sendRequestForLogging();
}

/* --- getters / setters --- */
void SaviourClient::setPartnerTelephoneNumbers(vector<int> val_) {
    gsmAgent.setPartnerTelephoneNumbers(val_);
}

vector<int> SaviourClient::getPartnerTelephoneNumbers() const {
    return gsmAgent.getPartnerTelephoneNumbers();
}

void SaviourClient::setTelephoneNumber(int val_) {
    gsmAgent.setTelephoneNumber(val_);
}

int SaviourClient::getTelephoneNumber() const {
    return gsmAgent.getTelephoneNumber();
}
