#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "GameState.h"
#include "TitlePage.h"
#include "LevelSelect.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "LevelFactory.h"
#include "Level.h"

namespace escape {
	class GameLogic {

		private:
			b2World* World;
			b2Body** Body;

			void changeToLoading();

		public:
			GameLogic();

			GameState state;

			Level level;
			LevelFactory factory;

			TitlePage titlePage;
			LevelSelect levelSelect;

			//Resources (fonts, sprites)
			ResourceManager resources;

			EventManager eventManager;

			void pollEvent(sf::RenderWindow *App, sf::Clock gameTime, double targetMs);
			void loadLevel(int level);
			void progressSimluation(sf::RenderWindow *App);
	};
}
#endif
