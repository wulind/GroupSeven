#pragma once
#include <SFML/Graphics.hpp>

#include "Platform.h"

namespace controller {
	class GameController {

	private:
		bool isPlaying;

	public:
		GameController();
		void updateGame();
		void updateView();
	};
}