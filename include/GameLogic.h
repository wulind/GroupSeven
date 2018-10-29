#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>

#include "../include/GameState.h"

#include "../include/Platform.h"
#include "../include/StolenObject.h"
#include "../include/PlatformMenu.h"
#include "../include/FinishButton.h"

#include "../include/GameView.h"

namespace escape {
	class GameLogic {

		private:
			//Window
			sf::RenderWindow* App;

			//gameState
			//GameState state;

		  	//Objects
			Platform platform;
			StolenObject stolenObject;
			PlatformMenu menu;
			FinishButton finishButton;

		  	//Views
			GameView mainView;

		public:
			GameLogic(sf::RenderWindow *App);

	  		int gameLoop();

			void updateGame();

			void updateMouse();
			bool checkMouseOverPlatform();
			void releaseAllPlatforms();
	};
}
#endif
