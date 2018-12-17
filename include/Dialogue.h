#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include "GameView.h"

namespace escape{
	class Dialogue{

		public:
			Dialogue();

			sf::Text text; //SFML text that contains storyline
			sf::Text funFact; //SFML text that contains fun fact of the level

			void setStory(const char* text, const char* funFact);
			void loseLevel();
			void winLevel();
			void winGame();
			void drawBackground(sf::RenderWindow *App);
	};
}
#endif
