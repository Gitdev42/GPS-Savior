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
    setStatus(TimerStatus::stopped);
}

/**
 * Timer::start
 * @brief set the status to started and calc stopTime
 *
 * if status is "stopped", stop time is current time + whole count down interval
 * if status is "paused", stop time is current time + remaining time of countdown interval
 */
void Timer::start() {
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

/**
 * Timer::checkTimerIsStarted
 * @brief check if the current status is "started"
 * @return returns the information if current status is "started"
 */
bool Timer::checkTimerIsStarted() {
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
bool Timer::checkTimerIsUp() {
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
int Timer::getCurrentTime() {

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
