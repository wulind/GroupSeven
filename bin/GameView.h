#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"

using namespace gameObject;

namespace view {
	class GameView
	{

	private:
		sf::RenderWindow* window;
		sf::Font font;

		Platform* draggablePlatform;

	public:
		GameView(sf::RenderWindow* newWindow);
		void Update();
		void setPlatform(Platform* draggablePlatform);
	};
}