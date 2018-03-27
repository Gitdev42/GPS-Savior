/**
 * Timer.cpp
 * Purpose: implements class Timer
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/Timer.h"

using namespace std;

/* --- constructors / destructors --- */
/**
 * Timer::Timer
 * @brief constructor of class Timer, calls function init
 * @param countDownTime_ time interval in milliseconds
 */
Timer::Timer(int countDownTime_) {
    init(countDownTime_);
}

/* --- initialization / main execution functions --- */
/**
 * Timer::init
 * @brief initializes the interval and status of this class
 * @param countDownTime_ time interval in milliseconds
 */
void Timer::init(int countDownTime_) {
    setCountDownTime(countDownTime_);
    stopAndReset();
}

/**
 * Timer::start
 * @brief set the status to started and calc stopTime
 *
 * if status is "stopped", stop time is current time + whole count down interval
 * if status is "paused", stop time is current time + remaining time of countdown interval
 * start is only possible, if interval > 0
 */
void Timer::start() {
    if (getCountDownTime() > 0) {
        int currentTime = getCurrentTime();
        if (getStatus() == TimerStatus::stopped) {
            setStartTime(currentTime);
            setStopTime(currentTime + getCountDownTime());
            setStatus(TimerStatus::started);
        } else if (getStatus() == TimerStatus::paused) {
            setStartTime(currentTime);
            setStopTime(currentTime + getRemainingTime());
            setStatus(TimerStatus::started);
        }
    }
}

/**
 * Timer::checkTimerIsStarted
 * @brief check if the current status is "started"
 * @return returns the information if current status is "started"
 */
bool Timer::checkTimerIsStarted() const {
    return (getStatus() == TimerStatus::started);
}

/**
 * Timer::pause
 * @brief sets the status to "paused" and saves the remaining time
 *
 * This function sets the status to "paused" and saves the remaining time.
 * If the remaining time <= 0 stopAndReset() is executed instead of pause().
 */
void Timer::pause() {
    if (getStatus() == TimerStatus::started) {
        int currentTime = getCurrentTime();
        if (getStopTime() - currentTime > 0) {
            setRemainingTime(getStopTime() - currentTime);
            setStatus(TimerStatus::paused);
        } else {
            stopAndReset();
        }
    }
}

/**
 * Timer::stopAndReset
 * @brief resets the startTime, stopTime and remainingTime and set status to "stopped"
 */
void Timer::stopAndReset() {
    setStartTime(0);
    setStopTime(0);
    setRemainingTime(0);
    setStatus(TimerStatus::stopped);
}

/**
 * Timer::checkTimerIsUp
 * @brief checks if count down timer is up
 * @return returns true if current time >= stopTime
 */
bool Timer::checkTimerIsUp() const {
    if (getStatus() == TimerStatus::started) {
        return ( getCurrentTime() >= getStopTime() );
    } else {
        return false;
    }
}


/* --- miscellaneous --- */
/**
 * Timer::getCurrentTime
 * @brief returns current unix-time
 * @return returns current unix-time (milliseconds since 1970)
 */
int Timer::getCurrentTime() const {
    return getTimeMs64();
}

/**
 * Timer::getTimeMs64
 * Returns the amount of milliseconds elapsed since the UNIX epoch.
 * Works on both windows and linux.
 * @source https://stackoverflow.com/questions/1861294/how-to-calculate-execution-time-of-a-code-snippet-in-c
 */
unsigned int Timer::getTimeMs64() const {
    #ifdef _WIN32
         /* Windows */
         FILETIME ft;
         LARGE_INTEGER li;

         /* Get the amount of 100 nano seconds intervals elapsed since January 1, 1601 (UTC) and copy it
          * to a LARGE_INTEGER structure. */
         GetSystemTimeAsFileTime(&ft);
         li.LowPart = ft.dwLowDateTime;
         li.HighPart = ft.dwHighDateTime;

         uint64 ret = li.QuadPart;
         ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
         ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */

         return ret;
    #else
         /* Linux */
         struct timeval tv;

         gettimeofday(&tv, NULL);

         unsigned int ret = tv.tv_usec;
         /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
         ret /= 1000;

         /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
         ret += (tv.tv_sec * 1000);

         return ret;
    #endif
}

/* --- getters / setters --- */
/**
 * Timer::getStatus
 * @brief getter function of member variable status
 * @return value of the member variable status
 */
TimerStatus Timer::getStatus() const {
    return status;
}

/**
 * Timer::setStatus
 * @brief setter function of member variable status
 * @param val_ new value for member variable status
 */
void Timer::setStatus(const TimerStatus &val_) {
    status = val_;
}

/**
 * Timer::getStartTime
 * @brief getter function of member variable startTime
 * @return value of the member variable startTime
 */
int Timer::getStartTime() const {
    return startTime;
}

/**
 * Timer::setStartTime
 * @brief setter function of member variable startTime
 * @param val_ new value for member variable startTime
 */
void Timer::setStartTime(int val_) {
    startTime = val_;
}

/**
 * Timer::getStopTime
 * @brief getter function of member variable stopTime
 * @return value of the member variable stopTime
 */
int Timer::getStopTime() const {
    return stopTime;
}

/**
 * Timer::setStopTime
 * @brief setter function of member variable stopTime
 * @param val_ new value for member variable stopTime
 */
void Timer::setStopTime(int val_) {
    stopTime = val_;
}

/**
 * Timer::getCountDownTime
 * @brief getter function of member variable countDownTime
 * @return value of the member variable countDownTime
 */
int Timer::getCountDownTime() const {
    return countDownTime;
}

/**
 * Timer::setCountDownTime
 * @brief setter function of member variable countDownTime
 * @param val_ new value for member variable countDownTime
 */
void Timer::setCountDownTime(int val_) {
    countDownTime = val_;
}

/**
 * Timer::getRemainingTime
 * @brief getter function of member variable remainingTime
 * @return value of the member variable remainingTime
 */
int Timer::getRemainingTime() const {
    return remainingTime;
}

/**
 * Timer::setRemainingTime
 * @brief setter function of member variable remainingTime
 * @param val_ new value for member variable remainingTime
 */
void Timer::setRemainingTime(int val_) {
    remainingTime = val_;
}
