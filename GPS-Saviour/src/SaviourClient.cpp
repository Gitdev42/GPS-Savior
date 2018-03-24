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
void SaviourClient::execute() {
    do (

    ) while (! checkReceivedPackage());

}


/**
 * SaviourClient::checkReceivedPackage
 * @brief checks if an GSMPackage is received
 * @param none
 * @return true if an GSMPackage is received
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
void SaviourClient::saveData(GSMPackage)
{

}


/**
 * @brief SaviourClient::SendAnswerForAuthRequest
 */
void SaviourClient::SendAnswerForAuthRequest(GSMPackage)
{

}


/**
 * @brief SaviourClient::error
 */
void SaviourClient::error()
{

}
