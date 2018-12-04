#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>

namespace escape{
	class LevelSelect{

		private:
	  	sf::Sprite sprite;

	  	sf::RenderWindow *App;
	  	GameState *state;

	  	float screenX = 800;
	  	float screenY = 600;

	  	float imageX = 1114;
	  	float imageY = 590;

		public:
			LevelSelect();

			typedef struct {
        int xCoord;
        int yCoord;
				sf::CircleShape circle;
      } SelectOrb;

			std::vector<SelectOrb> levels;

        void appendDot(SelectOrb orb);

        void levelClick(sf::Vector2i mousePosition, GameState &state);



	};
}
#endif
