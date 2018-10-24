#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>

#include "../include/Platform.h"
#include "../include/GameView.h"

namespace escape {
	class GameLogic {

		private:
		  //Window
		  sf::RenderWindow* App;

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
