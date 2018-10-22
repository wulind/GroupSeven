#pragma once
#include <SFML/Graphics.hpp>

#include "Platform.h"
#include "GameView.h"

namespace controller {
	class GameController {

	private:
		bool isPlaying;
		sf::RenderWindow* window;
		gameObject::Platform platform;
		view::GameView mainView;

	public:
		GameController(sf::RenderWindow* newWindow);
		void updateGame();
		void updateView();
	};
}