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
enum PackageType {requestForAuth, requestData, requestLogging, sendData, sendAuth, authDenied};

enum StoringStatus {storeSingleData,storeContinuously};

enum SendingStatus {sendSingleData,sendSingleDataArray,sendContinuously};




#endif // TYPES_H
