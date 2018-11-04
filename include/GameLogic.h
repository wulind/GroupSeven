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

			//gameState
			//GameState state;

		  	//Objects
			Platform platform;
			StolenObject stolenObject;
			PlatformMenu menu;

		  	//Views
			GameView mainView;
		
			void updateGame();
			
			//Platform moving
			void updateMouse();
			bool checkMouseOverPlatform();
			void releaseAllPlatforms();

		public:
			GameLogic(sf::RenderWindow *App);

	  		int gameLoop();

			
	};
}
#endif
