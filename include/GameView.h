#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TitlePage.h"

#include "Platform.h"
#include "StolenObject.h"
#include "PlatformMenu.h"
#include "Level.h"
#include "Timer.h"

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
			sf::Font *numFont;
			sf::Music music;

			void drawRectangle(sf::RectangleShape &rect);
			void drawCircle(sf::CircleShape &circle);
			void drawText(sf::Text &text);
			void drawNumText(sf::Text &text);
      void drawBackground(Level &level);

			sf::RectangleShape makeRectangle(int width, int height, float xCoord, float yCoord, int rotation);
			sf::CircleShape makeStolenObject(int radius, float xCoord, float yCoord, float rotation);

			Timer *timer;

		public:
      GameView();
      GameView(sf::Font* font, sf::Font* numFont, sf::Texture* backgroundSpriteSheet, sf::Texture* objectSpriteSheet, Timer* timer);

			void update(Level &level, bool play);
			void displayLevelStory(sf::Text &text);
			void pauseMusic();
			void playMusic();

			sf::RenderWindow* getApp();
			sf::Vector2i getMousePosition();
	};
}
#endif
