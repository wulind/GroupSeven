#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include "../include/GameState.h"
#include "../include/Platform.h"
#include "../include/StolenObject.h"
#include "../include/PlatformMenu.h"
#include "../include/GameView.h"

namespace escape {
	class GameLogic {

		private:
		  //Window
		  sf::RenderWindow* App;

		  //Objects
			Platform platform;
			StolenObject stolenObject;
			PlatformMenu menu;
		  //Views
			GameView mainView;

		public:
			GameLogic(sf::RenderWindow *App);
            int gameLoop(sf::Clock gameTime, double targetMs);
			void updateGame();
			bool checkMouseOverPlatform();
			void releaseAllPlatforms();
	};
}
#endif
