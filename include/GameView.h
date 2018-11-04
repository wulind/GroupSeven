#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "../include/Platform.h"
#include "../include/StolenObject.h"
#include "../include/PlatformMenu.h"

namespace escape{
	class GameView{

		private:
	    		//Window
			sf::RenderWindow *App;

			sf::Font font; //TODO: get rid

			void drawPlatform(sf::RectangleShape platform);
			void drawStolenObject(sf::CircleShape circle);
			void drawText(sf::Text text);
			void drawSprite(sf::Sprite sprite);

		public:
			GameView();
			GameView(sf::RenderWindow *App);

	    		void update(Platform *platform, StolenObject *stolenObject, PlatformMenu *menu);

	};
}
#endif
