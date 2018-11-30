#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include "GameView.h"

namespace escape{
	class Dialogue{
	private:
		sf::Sprite sprite;
		sf::RenderWindow *App;

	
	public:
		Dialogue();
		void playStory(sf::RenderWindow *App, GameState *state, int levelSelected, GameView *gameView);
		void drawBackground(sf::RenderWindow *App);	
	};
}
#endif
