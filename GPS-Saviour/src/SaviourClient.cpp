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

}

/* --- main execution function --- */
/**
 * @brief SaviourClient::execute
 */
void SaviourClient::execute() {
    do {
        checkButtonsAndSendRequests();
    } while (! checkReceivedPackage());
    if(checkPackageType(receivedGSMPackage) == PackageType::requestForAuth) {
        sendAnswerForAuthRequest(receivedGSMPackage);
    } else if(checkPackageType(receivedGSMPackage) == PackageType::sendData) {
        saveData(receivedGSMPackage);
    } else {
        /* EROR*/
    }

}

/**
 * @brief SaviourClient::checkButtonsAndSendRequests
 * @return
 */
bool SaviourClient::checkButtonsAndSendRequests() {
    if(checkSendSingleDataPressed()) {
        sendRequest(requestSingleData);
        return true;
    } else if(! checkSendSingleDataPressed()) {
        if(checkSendSingleDataArrayPressed()) {
            sendRequest(requestSingeDataArray);
            return true;
        } else if(! checkSendSingleDataArrayPressed()) {
            if(checkSendStartContiniouslyDataPressed()) {
                sendRequest(requestStartContiniouslyData);
                return true;
            } else if(! checkSendStartContiniouslyDataPressed()) {
                if(checkSendStopContiniouslyDataPressed()) {

                } else if(!checkSendStopContiniouslyDataPressed()) {
                    if(checkStartLogging()) {
                        sendRequest(requestStartLogging);
                        return true;
                    } else if(!checkStartLogging()) {
                        if(checkStopLogging()) {
                            sendRequest(requestStopLogging);
                            return true;
                        } else if(! checkStopLogging()){
                            return false;
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief SaviourClient::checkSendSingleDataPressed
 * @return
 */
bool SaviourClient::checkSendSingleDataPressed()
{

}

/**
 * @brief SaviourClient::checkSendSingleDataArrayPressed
 * @return
 */
bool SaviourClient::checkSendSingleDataArrayPressed()
{

}

/**
 * @brief SaviourClient::checkSendStartContiniouslyDataPressed
 * @return
 */
bool SaviourClient::checkSendStartContiniouslyDataPressed()
{

}

/**
 * @brief SaviourClient::checkSendStopContiniouslyDataPressed
 * @return
 */
bool SaviourClient::checkSendStopContiniouslyDataPressed()
{

}

/**
 * @brief SaviourClient::checkStartLogging
 * @return
 */
bool SaviourClient::checkStartLogging()
{

}

/**
 * @brief SaviourClient::checkStopLogging
 * @return
 */
bool SaviourClient::checkStopLogging()
{

}


/**
 * SaviourClient::checkReceivedPackage
 * @brief checks if an GSMPackage is received
 * @param none
 * @return true if an GSMPackage is received
 *
 * stores the received SMS in receivedGSMPackage
 */
bool SaviourClient::checkReceivedPackage()
{

}


/**
 * @brief SaviourClient::checkPackageType
 * @param receivedGSMPackage_
 * @return Type of the received Package, used to coordinate the next steps
 */
PackageType SaviourClient::checkPackageType(GSMPackage receivedGSMPackage_)
{
    return receivedGSMPackage_.getPackageType();
}


/**
 * @brief SaviourClient::saveData
 */
void SaviourClient::saveData(GSMPackage receivedGSMPackage_)
{

}


/**
 * @brief SaviourClient::sendAnswerForAuthRequest
 */
void SaviourClient::sendAnswerForAuthRequest(GSMPackage receivedGSMPackage_)
{

}

/**
 * @brief SaviourClient::sendRequest
 */
void SaviourClient::sendRequest(PackageType requestType_)
{

}


/**
 * @brief SaviourClient::error
 */
void SaviourClient::error()
{

}
