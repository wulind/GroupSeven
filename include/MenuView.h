#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>
#include "../include/GameState.h"

namespace escape{
	class MenuView{

		private:
	    //Window
			sf::RenderWindow *App;

			void loadTitleScreen();
      void loadLevelSelect();

		public:
			MenuView();
			MenuView(sf::RenderWindow *App);

	    void update(GameState &state);

	};
}
#endif
