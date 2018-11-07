#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>
#include "../include/GameState.h"

namespace escape{
	class MenuView{

		private:
			float screenX = 800;
			float screenY = 600;

			//Window
			sf::RenderWindow *App;



			void drawText(sf::Text &text);

		public:
			MenuView();
			MenuView(sf::RenderWindow *App);

	    void update(GameState &state);

	};
}
#endif
