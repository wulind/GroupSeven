#ifndef TITLEPAGE_H
#define TITLEPAGE_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
	class TitlePage{

		private:
			float screenX = 800;
			float screenY = 600;

		public:
			TitlePage();

			sf::Text title;
    	sf::Text play;

      void changeToLevelSelect(sf::RenderWindow &App, GameState &state);

	};
}
#endif
