/**
 * Types.h
 * Purpose: defines structs, constants and enums
 *
 * @author gitdev42
 * @version 1.0
 */

#ifndef TYPES_H
#define TYPES_H

/* --- structs --- */

/* --- constants --- */

int WAIT_FOR_AUTH_PACKAGE_TIMEOUT = 5000; // in milli seconds;

/* --- enumerations --- */
enum PackageType {requestForAuth, requestSingleData, requestSingeDataArray, requestStartContiniouslyData, requestStopContiniouslyData, requestStartLogging, requestStopLogging, sendData, sendAuth, authDenied};

enum StoringStatus {storeSingleData,storeContinuously};

enum SendingStatus {sendSingleData,sendSingleDataArray,sendContinuously};


#endif // TYPES_H
