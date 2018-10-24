//Header file for Timer, got group 7 game

//By Zachary Greenfield
#ifndef TIMER_HPP
#define TIMER_HPP
#include <time.h>

//Timer class for game
class Timer{
    private:
		clock_t t;
		float begin;

    public: 
		Timer();
		double getTime();
		void resetTimer();
		
};

#endif

