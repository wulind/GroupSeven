//Timer Class by Zachary Greenfield
//NOTE: Use std::cout << std::fixed  when printing time elapsed

#include "Timer.hpp"
Timer::Timer(){
	t = clock();
}

double Timer::getTime(){
	return (((double) (clock() - t))/CLOCKS_PER_SEC);
}

void Timer::resetTimer(){
	t = clock();
}