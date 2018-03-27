/**
 * Timer.h
 * Purpose: defines class Timer
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef Timer_H
#define Timer_H

#include "Types.h"

using namespace std;

/**
 * @brief TODO
 */
class Timer {
    public:
        /* --- constructors / destructors --- */
        Timer(int countDownTime_ = DEFAULT_COUNTDOWN_TIMER_INTERVAL);

        /* --- initialization / main execution functions --- */
        void init(int countDownTime_);
        void start();
        bool checkTimerIsStarted();
        void pause();
        void stopAndReset();
        bool checkTimerIsUp();

        /* --- miscellaneous --- */
        int  getCurrentTime();

        /* --- getters / setters --- */
        TimerStatus getStatus() const;
        void setStatus(const TimerStatus &val_);

        int getStartTime() const;
        void setStartTime(int val_);

        int getStopTime() const;
        void setStopTime(int val_);

        int getCountDownTime() const;
        void setCountDownTime(int val_);

private:
        TimerStatus status;
        int startTime;
        int stopTime;
        int countDownTime;
        int remainingTime;

        int getRemainingTime() const;
        void setRemainingTime(int val_);



};

#endif // Timer_H
