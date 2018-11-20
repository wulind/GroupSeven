#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
	class Dialogue{
	private:
		GameState *state;
		sf::Sprite sprite;
		sf::RenderWindow *App;
		sf::Font font;


	
	public:
		Dialogue();
		void playStory(sf::RenderWindow *App, GameState *state);
		void drawBackground(sf::RenderWindow *App);	

	};
}
#endif
