#include "../include/Timer.h"

using namespace escape;
using namespace std;

/*
* Constructor
*/
Timer::Timer() {

	this->color		= sf::Color::White;

	this->minutes		= 0;
	this->seconds		= 0;
	this->milliseconds	= 0;
}

/*
 * Add 1 frame to the timer during "play" state
 */
void Timer::tickClock() {

	if (!this->isPlaying) {
		this->isPlaying = true;
		clock.restart();
		return;
	}

	sf::Time elapsedTime = clock.getElapsedTime();

	
	this->milliseconds += elapsedTime.asMilliseconds();

	if (this->milliseconds >= 1000) {
		this->milliseconds = this->milliseconds - 1000;
		this->seconds += 1;

		string curTime = this->getFormattedTime();
	}
	if (this->seconds >= 60) {
		
		this->seconds = 0;
		this->minutes += 1;
	}

	clock.restart();
}

void Timer::stopClock() {
	this->isPlaying = false;

};

string intToLengthString(int number, int lengthOfString) {

	string formattedString = to_string(number);

	while (formattedString.length() < lengthOfString) {
		formattedString = "0" + formattedString;
	}

	return formattedString;
}

string Timer::getFormattedTime() {

	string millisecondsFormatted = intToLengthString(milliseconds, 3);
	string secondsFormatted = intToLengthString(seconds, 2);
	string minutesFormatted = intToLengthString(minutes, 2);

	return minutesFormatted + ":" + secondsFormatted + ":" + millisecondsFormatted;
}