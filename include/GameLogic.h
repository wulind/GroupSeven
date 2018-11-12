#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "GameState.h"
#include "TitlePage.h"
#include "ResourceManager.h"
#include "LevelFactory.h"

namespace escape {
	class GameLogic {

		private:
			b2World* World;
			b2Body** Body;

			void changeToLoading();

		public:
			GameLogic();

			GameState state;

			TitlePage titlePage;

			//Resources (fonts, sprites)
			ResourceManager resources;

			LevelFactory factory;

			void pollEvent(sf::RenderWindow *App);
			void loadLevel(int level);
	};
}
#endif
