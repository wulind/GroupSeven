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

			sf::Texture backgroundTexture;
			sf::Sprite sprite;
	    //Window
			sf::RenderWindow App;

			float screenX = 800;
			float screenY = 600;

			sf::Font *font;

			
			void drawRectangle(sf::RectangleShape &rect);
			void drawCircle(sf::CircleShape &circle);

		public:
    		GameView();
      		GameView(sf::Font *_font);
      		void setGraphics(Level &level);
			void update(Level &level);
			void drawText(sf::Text &text);
      		sf::RenderWindow* getApp();
			sf::Vector2i getMousePosition();




	};
}
#endif
