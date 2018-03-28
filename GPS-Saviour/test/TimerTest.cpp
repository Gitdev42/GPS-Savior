/**
* NeedyClientTest.cpp
* Purpose: implements unit-tests for analysing functions of the NeedyClient-class
*
* @author Wall.Of.Death
* @version 1.0
*/

// !!!! TEST_CASE IN COMBINITION WITH REQUIRE IS LIKE A LOOP STRUCTURE !!!!
// !!!! THE TEST_CASE IS EXECUTED FOR EVERY SECTION !!!!

#include "catch.hpp"
#include "Timer.h"
#include "Types.h"

using namespace  std;


TEST_CASE("Test Timer class initialization") {
    SECTION("constructor without parameter") {
        Timer timer1;
        REQUIRE(timer1.getCountDownTime() == DEFAULT_COUNTDOWN_TIMER_INTERVAL);
        REQUIRE(timer1.getCurrentTime() > 0);
        REQUIRE(timer1.getStartTime() == 0);
        REQUIRE(timer1.getStopTime() == 0);
    }

    SECTION("constructor with parameter") {
        Timer timer1(5000);
        REQUIRE(timer1.getCountDownTime() == 5000);
        REQUIRE(timer1.getCurrentTime() > 0);
        REQUIRE(timer1.getStartTime() == 0);
        REQUIRE(timer1.getStopTime() == 0);
    }

    SECTION("constructor without parameter, and init") {
        Timer timer1;
        timer1.init(6000);
        REQUIRE(timer1.getCountDownTime() == 6000);
        REQUIRE(timer1.getCurrentTime() > 0);
        REQUIRE(timer1.getStartTime() == 0);
        REQUIRE(timer1.getStopTime() == 0);
    }
}

TEST_CASE("test Timer.start()") {
    Timer timer1;
    SECTION("interval < 10 not possible") {

        SECTION("interval = 0 not possible") {
            timer1.init(9);
        }
        SECTION("interval = 0 not possible") {
            timer1.init(0);
        }
        SECTION("interval < 0 not possible") {
            timer1.init(-1);
        }
        SECTION("interval < 0 not possible") {
            timer1.init(-1000);
        }

        timer1.start();
        REQUIRE(timer1.getStatus() == TimerStatus::stopped);
        REQUIRE_FALSE(timer1.checkTimerIsStarted());
    }

    SECTION("interval > 0 possible") {

        SECTION("test interval = 1") {
            timer1.init(10);
        }
        SECTION("interval = 10") {
            timer1.init(10);
        }
        SECTION("interval = 100") {
            timer1.init(100);
        }
        SECTION("interval = 100") {
            timer1.init(1000);
        }
        SECTION("interval = 100") {
            timer1.init(10000);
        }
        SECTION("interval = 100") {
            timer1.init(100000);
        }

        timer1.start();
        REQUIRE(timer1.getStatus() == TimerStatus::started);
        REQUIRE(timer1.checkTimerIsStarted());
        while(! timer1.checkTimerIsUp()) {
            int timeDifference = timer1.getStopTime() - timer1.getCurrentTime();
            REQUIRE(timeDifference > 0);
        }
        int timeDifference = timer1.getStopTime() - timer1.getCurrentTime();
        REQUIRE(timeDifference <= 0);
   }

}

TEST_CASE("test Timer.pause()") {
    Timer timer1(1000);
    Timer timer2(100);
    timer1.start();
    timer2.start();
    while(!timer2.checkTimerIsUp()) {
        //wait
    }
    timer1.pause();
    int timeDifference = timer1.getStopTime() - timer1.getStartTime();
    REQUIRE(timeDifference >= 890);
    REQUIRE(timeDifference <= 910);

}
