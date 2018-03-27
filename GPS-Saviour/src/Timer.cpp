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
 * @brief Timer::Timer
 * @param countDownTime_
 */
Timer::Timer(int countDownTime_) {
    init(countDownTime_);
}

/* --- initialization / main execution functions --- */
/**
 * @brief Timer::init
 * @param countDownTime_
 */
void Timer::init(int countDownTime_) {
    setCountDownTime(countDownTime_);
    setStatus(TimerStatus::stopped);
}

/**
 * @brief Timer::start
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
 * @brief Timer::checkTimerIsStarted
 * @return
 */
bool Timer::checkTimerIsStarted() {
    return (getStatus() == TimerStatus::started);
}

/**
 * @brief Timer::pause
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
 * @brief Timer::stopAndReset
 */
void Timer::stopAndReset() {
    setStartTime(0);
    setStopTime(0);
    setRemainingTime(0);
    setStatus(TimerStatus::stopped);
}

/**
 * @brief Timer::checkTimerIsUp
 * @return
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
 * @brief Timer::getCurrentTime
 * @return
 */
int Timer::getCurrentTime() {

}

/* --- getters / setters --- */
/**
 * @brief Timer::getStatus
 * @return
 */
TimerStatus Timer::getStatus() const {
    return status;
}

/**
 * @brief Timer::setStatus
 * @param val_
 */
void Timer::setStatus(const TimerStatus &val_) {
    status = val_;
}

/**
 * @brief Timer::getStartTime
 * @return
 */
int Timer::getStartTime() const {
    return startTime;
}

/**
 * @brief Timer::setStartTime
 * @param val_
 */
void Timer::setStartTime(int val_) {
    startTime = val_;
}

/**
 * @brief Timer::getStopTime
 * @return
 */
int Timer::getStopTime() const {
    return stopTime;
}

/**
 * @brief Timer::setStopTime
 * @param val_
 */
void Timer::setStopTime(int val_) {
    stopTime = val_;
}

/**
 * @brief Timer::getCountDownTime
 * @return
 */
int Timer::getCountDownTime() const {
    return countDownTime;
}

/**
 * @brief Timer::setCountDownTime
 * @param val_
 */
void Timer::setCountDownTime(int val_) {
    countDownTime = val_;
}

/**
 * @brief Timer::getRemainingTime
 * @return
 */
int Timer::getRemainingTime() const {
    return remainingTime;
}

/**
 * @brief Timer::setRemainingTime
 * @param val_
 */
void Timer::setRemainingTime(int val_) {
    remainingTime = val_;
}
