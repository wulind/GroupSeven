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

string intToTwoLengthString(int number) {

	string formattedString;

	if (number < 10) {
		formattedString.append("0");
	}

	formattedString.append(to_string(number));

	return formattedString;
}

string Timer::getFormattedTime() {

	string secondsFormatted = intToTwoLengthString(seconds);
	string minutesFormatted = intToTwoLengthString(minutes);

	return minutesFormatted + ":" + secondsFormatted;
}