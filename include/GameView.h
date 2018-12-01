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
			sf::Sprite sprite; // should not be a this- >sprite
            sf::Texture *backgroundSpriteSheet;
            sf::Texture *objectSpriteSheet;

            //Window
			sf::RenderWindow App;

			float screenX = 800;
			float screenY = 600;

			sf::Font *font;


			void drawRectangle(sf::RectangleShape &rect);
			void drawCircle(sf::CircleShape &circle);
			void drawText(sf::Text &text);
      void drawBackground(Level &level);

			sf::RectangleShape makeRectangle(int width, int height, int xCoord, int yCoord, sf::Color color);
			sf::CircleShape makeStolenObject(StolenObject &stolenObject);

		public:
            GameView();
            GameView(sf::Font* font, sf::Texture* backgroundSpriteSheet, sf::Texture* objectSpriteSheet);

			void update(Level &level);
			void displayLevelStory(sf::Text &text);

			sf::RenderWindow* getApp();
			sf::Vector2i getMousePosition();
	};
}
#endif
