/**
 * Timer.h
 * Purpose: defines class Timer
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef Timer_H
#define Timer_H

using namespace std;

/**
 * @brief TODO
 */
class Timer {
    public:
        /* --- constructors / destructors --- */
        Timer() {};

        void init(int countDownTimeInMilliSeconds_);
        void start();
        //void pause();
        void stopAndReset();
        bool checkTimerIsUp();

    private:




};

#endif // Timer_H