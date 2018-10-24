#ifndef GAMEVIEW_H
#define GAMEVIEW_H

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

		void drawPlatform();

	public:
		GameView(sf::RenderWindow* newWindow);
		void update();
		void setPlatform(Platform* draggablePlatform);
	};
}
#endif
