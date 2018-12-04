#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

namespace escape {
	class Timer {

	public:
		Timer();

		int minutes;
		int seconds;
		int frames;

		sf::Color color;

		void tickClock();
		std::string getFormattedTime();
	};
}
#endif