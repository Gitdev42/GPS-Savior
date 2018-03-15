/**
 * NeedyClient.cpp
 * Purpose: implements class NeedyClient
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/NeedyClient.h"

void NeedyClient::init() {

}

void NeedyClient::execute() {
    while(true) {


        // check if initialization package is received, if so initialize client
        checkReveivedInitialization();

        if (checkReceivedRequesForStatusChange()) {
            // process storing and sending tasks
            processTasks();
        } else {
            if (getAuthIsRequired()) {
                sendRequestForAuth();

                // wait until either auth package is received or timeout is up
                while ( (! checkTimeoutIsUp() ) && (!checkReceivedAuthPackage())) {
                    // wait
                }

                if (! checkAuthCompleted()) {
                    sendErrorPackage();
                } else {
                    saveRequestedStatus();
                }
            } else {
                saveRequestedStatus();
            }
        }
    }
}


/* --- getters / setters --- */

bool NeedyClient::getAuthIsRequired() const {
    return authIsRequired;
}

void NeedyClient::setAuthIsRequired(bool value) {
    authIsRequired = value;
}

void NeedyClient::checkReveivedInitialization()
{

}

bool NeedyClient::checkReceivedRequesForStatusChange()
{

}

void NeedyClient::processTasks()
{

}

void NeedyClient::sendRequestForAuth()
{

}

bool NeedyClient::checkReceivedAuthPackage()
{

}

bool NeedyClient::checkTimeoutIsUp()
{

}

bool NeedyClient::checkAuthCompleted()
{

}

void NeedyClient::sendErrorPackage()
{

}

void NeedyClient::saveRequestedStatus()
{

}
