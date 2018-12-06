#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include "GameView.h"

namespace escape{
	class Dialogue{

		public:
			Dialogue();

			sf::Text text;
			sf::Text funFact;

			void setStory(const char* text, const char* funFact);
			void loseLevel();
			void winLevel();
			void winGame();
			void drawBackground(sf::RenderWindow *App);
	};
}
#endif
