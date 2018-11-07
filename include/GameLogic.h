#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>

#include "GameState.h"

#include "TitlePage.h"

#include "Platform.h"
#include "StolenObject.h"
#include "PlatformMenu.h"
#include "FinishButton.h"

#include "GameView.h"

namespace escape {
	class GameLogic {

		private:
		  //Window
		  sf::RenderWindow *App;

			//gameState
			GameState state;

			//Title Page
			TitlePage titlePage;

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

			//void updateMouse();
			//bool checkMouseOverPlatform();
			//void releaseAllPlatforms();
	};
}
#endif
