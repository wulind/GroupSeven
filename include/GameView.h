#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>

#include "TitlePage.h"

#include "Platform.h"
#include "StolenObject.h"
#include "PlatformMenu.h"
#include "Level.h"

namespace escape{
	class GameView{

		private:

	    //Window
			sf::RenderWindow App;

			float screenX = 800;
			float screenY = 600;

			sf::Font *font;

			void drawText(sf::Text &text);
			void drawSprite(sf::Sprite &sprite);
			void drawRectangle(sf::RectangleShape &rect);
			void drawCircle(sf::CircleShape &circle);

		public:
    	GameView();
      GameView(sf::Font *_font);

			void update(Level &level);//Platform *platform, StolenObject *stolenObject, PlatformMenu *menu, Platform *base);

      sf::RenderWindow* getApp();

	};
}
#endif
