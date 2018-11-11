#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "TitlePage.h"

namespace escape{
	class MenuView{

		private:
			float screenX = 800;
			float screenY = 600;
			float imageX = 1114;
			float imageY = 590;

			//Window
			sf::RenderWindow *App;

			sf::Font *font;

			void drawText(sf::Text &text);

		public:
			MenuView();
			MenuView(sf::RenderWindow *_App, sf::Font *_font);

			void loadTitleScreen(TitlePage &titlePage);
      			void loadLevelSelect();

	    		void update(GameState &state);

	};
}
#endif
