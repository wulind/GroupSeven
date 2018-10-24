#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include "../include/Platform.h"
#include "../include/GameView.h"

namespace escape {
	class GameLogic {

		private:
		  //Window
			sf::RenderWindow* App;
			b2World* World;

			//gameState

		  //Objects
			Platform platform;

		  //Views
			GameView mainView;

		public:
			GameLogic(sf::RenderWindow *App);

	  	int gameLoop();

			void updateGame();

			bool checkMouseOverPlatform();
			void releaseAllPlatforms();
	};
}
#endif
