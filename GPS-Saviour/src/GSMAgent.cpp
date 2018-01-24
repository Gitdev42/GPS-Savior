/**
 * GSMAgent.cpp
 * Purpose: implements class GSMAgent
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/GSMAgent.h"


/* --- getters / setters --- */





void GSMAgent::init() {
    cout << "initialized GSMAgent" << endl;
}

bool GSMAgent::checkRequestForAuthentication()
{
    return true;
}

void GSMAgent::requestData() {
    cout << "GSM Data requested" << endl;
}

void GSMAgent::sendData() {
    cout << "GSM Data send" << endl;
}
