#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
	class LevelSelect{

		private:
			int levelUnlocked = 5;
			sf::Text titleText;
			sf::Font font;

		  sf::Sprite sprite;

		  sf::CircleShape level1;
		  sf::CircleShape level2;
		  sf::CircleShape level3;
		  sf::CircleShape level4;
		  sf::CircleShape level5;

			sf::RenderWindow *App;
			GameState *state;

			float screenX = 800;
			float screenY = 600;


			float imageX = 1114;
			float imageY = 590;

		public:
			LevelSelect();
			void drawBackground(sf::RenderWindow *App);
			void drawLevelDots(sf::RenderWindow *App);
			void availableLevels();
			void drawText();
      		void levelClick(sf::Vector2i mousePosition, GameState &state);
	};
}
#endif
