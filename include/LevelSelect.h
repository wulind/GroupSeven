#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
// #include "MenuView.h"
#include <vector>

namespace escape{
	class LevelSelect{

		private:
			int levelUnlocked = 2;

			
		  	sf::Sprite sprite;
		  	std::vector<sf::CircleShape> levels;


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
      		void levelClick(sf::Vector2i mousePosition, GameState &state);
	};
}
#endif
