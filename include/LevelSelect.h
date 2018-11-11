#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
	class LevelSelect{

		private:
			int levelUnlocked = 1;

			sf::RenderWindow *App;
			GameState *state;
			float screenX = 800;
			float screenY = 600;


			float imageX = 1114;
			float imageY = 590;

		public:
			LevelSelect(sf::RenderWindow *App);
			void drawBackground();
			void drawLevelDots();
			void availableLevels();
	};
}
#endif
