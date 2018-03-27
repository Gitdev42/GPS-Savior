/**
 * Types.h
 * Purpose: defines structs, constants and enums
 *
 * @author gitdev42
 * @version 1.0
 */

#ifndef TYPES_H
#define TYPES_H

#include <string>

using namespace std;

/* --- structs --- */

/* --- constants --- */

// timer intervals in milli seconds
const int WAIT_FOR_AUTH_PACKAGE_TIMEOUT = 5000;
const int DEFAULT_STORING_TIMER_INTERVAL = 1000;
const int DEFAULT_SENDING_TIMER_INTERVAL = 1000;
const int DEFAULT_COUNTDOWN_TIMER_INTERVAL = 1000;
const int MINIMUM_COUNTDOWN_TIMER_INTERVAL = 10;

// error messages
const string AUTH_TIMEOUT_ERROR = "Authentication failed due to a timeout!";
const string AUTH_INVALID_ERROR = "Authentication failed because of invalid auth-package!";

/* --- enumerations --- */
enum PackageType {requestForAuth, requestSingleData, requestSingeDataArray, requestStartContiniouslyData, requestStopContiniouslyData, requestStartLogging, requestStopLogging, sendData, sendAuth, authDenied};

enum StoringStatus {storingDisabled,storeSingleData,storeContinuously};

enum SendingStatus {sendingDisabled,sendSingleData,sendSingleDataArray,sendContinuously};

enum TimerStatus {stopped,started,paused};


#endif // TYPES_H
