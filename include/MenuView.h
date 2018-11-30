#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "TitlePage.h"
#include "LevelSelect.h"
#include <vector>

namespace escape{
	class MenuView{

		private:

			float screenX = 800;
			float screenY = 600;


			//Window
			sf::RenderWindow *App;

			sf::Font *font;

			void drawText(sf::Text &text);

		public:
			MenuView();
			MenuView(sf::RenderWindow *_App, sf::Font *_font);

			void loadTitleScreen(TitlePage &titlePage);
      		void loadLevelSelect(LevelSelect &levelSelect);
      		void drawLevelDots(sf::RenderWindow *App, LevelSelect &levelSelect);

	    void update(GameState &state);

	};
}
#endif
