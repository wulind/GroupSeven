#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>

namespace escape{
	class LevelSelect{

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
