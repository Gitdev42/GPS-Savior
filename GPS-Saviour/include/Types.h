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

/* --- enumerations --- */
<<<<<<< HEAD
enum PackageType {requestForAuth, requestData, requestLogging, sendData, sendAuth, authDenied};

enum StoringStatus {storeSingleData,storeContinuously};

enum SendingStatus {sendSingleData,sendSingleDataArray,sendContinuously};


=======
enum PackageType {requestForAuth, requestSingleData, requestSingeDataArray, requestStartContiniouslyData, requestStopContiniouslyData, requestStartLogging, requestStopLogging, sendData, sendAuth, authDenied};
>>>>>>> fd7a63a70e0f75986af6789f5ec9bff10a23ab09


#endif // TYPES_H
