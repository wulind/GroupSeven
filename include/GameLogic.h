#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "GameState.h"
#include "TitlePage.h"
#include "ResourceManager.h"

namespace escape {
	class GameLogic {

		private:
			b2World* World;
			b2Body** Body;
			
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
