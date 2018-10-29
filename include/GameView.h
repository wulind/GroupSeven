#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "../include/Platform.h"

namespace escape{
	class GameView{

		private:
	    //Window
			sf::RenderWindow *App;

			sf::Font font;

			void drawPlatform(sf::RectangleShape platform);

		public:
			GameView();
			GameView(sf::RenderWindow *App);

	    void update(Platform* platform);

	};
}
#endif
