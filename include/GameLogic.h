#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>

#include "../include/GameState.h"

#include "../include/Platform.h"
#include "../include/StolenObject.h"
#include "../include/PlatformMenu.h"
#include "../include/FinishButton.h"
#include "../include/LevelFactory.h"

#include "../include/GameView.h"

namespace escape {
	class GameLogic {

		private:
			//Window
			sf::RenderWindow* App;

			//gameState
			//GameState state;

		  	//Objects
			StolenObject stolenObject;
			PlatformMenu menu;
			FinishButton finishButton;

		  	//Views
			GameView mainView;

			// Level Factory
			factory::LevelFactory levelFactory;

			// Platforms
			std::vector <escape::Platform> platforms;
		
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
