#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

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
			b2World* World;
			b2Body** Body;
			//gameState
			//GameState state;

		  	//Objects
			Platform platform;
			StolenObject stolenObject;
			PlatformMenu menu;
			FinishButton finishButton;

		  	//Views
			GameView mainView;
