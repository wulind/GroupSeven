#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "GameState.h"
#include "TitlePage.h"
#include "LevelSelect.h"
#include "ResourceManager.h"
#include "Options.h"

namespace escape{
	class MenuView{

		private:
			float screenX = 800;
			float screenY = 600;

      float mapImageFullX = 1114;
      float mapImageFullY= 590;

			//Window
			sf::RenderWindow *App;
			sf::Font *font;
      sf::Texture *mapTexture;
      sf::Texture *levelDot;
			sf::Music music;
			void drawText(sf::Text &text);

		public:
			MenuView();
			MenuView(sf::RenderWindow *_App, sf::Font *_font, sf::Texture* _mapTexture, sf::Texture *_levelDot);

			void setScreenSize(int x, int y);

			void loadTitleScreen(TitlePage &titlePage);
			void loadLevelSelect(LevelSelect &levelSelect);
			void drawLevelDots(LevelSelect &levelSelect);
			void drawOptionsMenu(Options &options);

			void update(GameState &state);
			void drawBackground();
			void pauseMusic();
			void playMusic(bool volume);

			bool musicPlaying;
	};
}
#endif
