#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "TitlePage.h"
#include "ResourceManager.h"

namespace escape {
	class GameLogic {

		public:
			GameLogic();

			//gameState
			GameState state;

			//Title Page
			TitlePage titlePage;

			//Resources (fonts, sprites)
			ResourceManager resources;

			void pollEvent(sf::RenderWindow *App);
	};
}
#endif
