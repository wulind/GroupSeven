#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include "GameView.h"

namespace escape{
	class Dialogue{
		private:

		public:
			Dialogue();

			sf::Text text;
			
			void playStory(int levelSelected);
			void drawBackground(sf::RenderWindow *App);
	};
}
#endif
