#include "../include/Timer.h"

using namespace escape;
using namespace std;

/*
* Constructor
*/
Timer::Timer() {

	this->color		= sf::Color::White;

	this->minutes	= 0;
	this->seconds	= 0;
	this->frames	= 0;
}

/*
 * Add 1 frame to the timer during "play" state
 */
void Timer::tickClock() {
	
	this->frames += 1;

	if (this->frames >= 60) {
		this->frames = 0;
		this->seconds += 1;

		string curTime = this->getFormattedTime();
	}
	if (this->seconds >= 60) {
		
		this->seconds = 0;
		this->minutes += 1;
	}
}

string Timer::getFormattedTime() {

	string secondsFormatted;
	string minutesFormatted;

	if (this->seconds < 10)
		secondsFormatted = "0" + to_string(this->seconds);
	else
		secondsFormatted = to_string(this->seconds);

	if (this->minutes < 10)
		minutesFormatted = "0" + to_string(this->minutes);
	else
		minutesFormatted = to_string(this->minutes);

	return minutesFormatted + secondsFormatted;
}