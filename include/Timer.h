#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

namespace escape {
	class Timer {

	public:
		Timer();

		int minutes;
		int seconds;
		int milliseconds;

		bool isPlaying;

		sf::Clock clock;

		sf::Color color;

		void tickClock();
		void stopClock();

		std::string getFormattedTime();
	};
}
#endif