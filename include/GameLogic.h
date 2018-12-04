#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "GameState.h"
#include "ResourceManager.h"
#include "TitlePage.h"
#include "LevelSelect.h"
#include "FinishButton.h"
#include "EventManager.h"
#include "LevelFactory.h"
#include "Level.h"
#include "Dialogue.h"

namespace escape {
	class GameLogic {

		private:
			b2World* World;
			b2Body** Body;

			LevelFactory factory;

			void changeToLoading();

		public:
			GameLogic();
			GameState state;

			Level level;
			TitlePage titlePage;
			LevelSelect levelSelect;
			Dialogue dialogue;

			//Resources (fonts, sprites)
			ResourceManager resources;

			EventManager eventManager;

			void pollEvent(sf::RenderWindow *App, sf::Clock gameTime, double targetMs);

			void makeNextLevelDot();
			void loadLevel(int level);

			void progressSimluation();
			void partialProgressSimluation(float portion);
	};
}
#endif
