#ifndef TITLEPAGE_H
#define TITLEPAGE_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
	class TitlePage{

		public:
			TitlePage();

			sf::Text title;
    	sf::Text play;
			sf::Text options;

      void changeToLevelSelect(sf::Vector2i mousePosition, GameState &state);

	};
}
#endif
