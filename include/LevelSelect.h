#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>


namespace escape{
	class LevelSelect{

		private:
			sf::RenderWindow *App;
			float screenX = 800;
			float screenY = 600;

		public:
			LevelSelect();
			selectLevel(sf::RenderWindow &App, GameState &state);
	};
}
#endif
