#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
			sf::Music music;
			sf::SoundBuffer buffer;
			sf::Sound thump;

			void drawRectangle(sf::RectangleShape &rect);
			void drawCircle(sf::CircleShape &circle);
			void drawText(sf::Text &text);
      void drawBackground(Level &level);

			sf::RectangleShape makeRectangle(int width, int height, float xCoord, float yCoord, int rotation);
			sf::CircleShape makeStolenObject(int radius, float xCoord, float yCoord, float rotation);

		public:
      GameView();
      GameView(sf::Font* font, sf::Texture* backgroundSpriteSheet, sf::Texture* objectSpriteSheet);

			void update(Level &level, bool play);
			void displayLevelStory(sf::Text &text, sf::Text &funFact);
			void pauseMusic();
			void playMusic();

			bool musicPlaying;

			sf::RenderWindow* getApp();
			sf::Vector2i getMousePosition();
	};
}
#endif
