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
#include "time.h"
#include "sys/time.h"

using namespace std;

/**
 * The Timer class
 * @brief The timer class is a very simple count-down timer implementation
 *
 * The timer class is a very simple count-down timer implementation.
 * It provides methods to set a timer interval and start, pause and stop the timer.
 * The timer class is not really a unit which is continously counting down a time
 * it is just a helper class which provides methods to save start and stop time
 * and to check if the current time is alreay later than the stop time.
 *
 * PLEASE NOTE : This countdown timer implementation uses the unix time in milliseconds
 *               (--> unix time = amount of milliseconds elapsed since the UNIX epoch (=1970))
 *
 * Example 1:
 * Timer timer1;      // this creates an instance of the class timer
 * timer1.init(1000); // this sets the interval length to 1 second
 * timer1.start;      // this starts the timer
 * if (timer1.checkTimerIsUp()) {...} // this checks if the stopTime is reached
 *
 * Example 2:
 * Timer timer2(1500);  // this creates an instance of the class timer and sets the interval length to 1.5 seconds
 * timer2.start;        // this starts the timer
 * timer2.stopAndReset; // this stops the timer and resets startTime and stopTime, the interval still is 1.5 seconds
 * timer2.start;        // this again starts the timer
 * timer2.pause;        // this pauses the timer
 * timer1.start;        // this again starts the timer
 * if (timer1.checkTimerIsUp()) {...} // this checks if the stopTime is reached
 */
class Timer {
    public:
        /* --- constructors / destructors --- */
        Timer(int countDownTime_ = DEFAULT_COUNTDOWN_TIMER_INTERVAL);

        /* --- initialization / main execution functions --- */
        void init(int countDownTime_);
        void start();
        bool checkTimerIsStarted() const;
        void pause();
        void stopAndReset();
        bool checkTimerIsUp() const;

        /* --- miscellaneous --- */
        int getCurrentTime() const;

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

        /* --- miscellaneous --- */
        unsigned int getTimeMs64() const;

        /* --- getters / setters --- */
        int getRemainingTime() const;
        void setRemainingTime(int val_);



};

#endif // Timer_H
