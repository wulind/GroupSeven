#include <SFML/Graphics.hpp>
#include "GameLogic.h"

using namespace escape;


int main(int argc, char** argv)
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(800,600,32), "The Great Escape");

	escape::GameLogic gameLogic = escape::GameLogic(&App);

	// start main loop
	while(App.isOpen()) {

    // process events
		sf::Event event;
		while(App.pollEvent(event)) {

			switch (event.type) {

				case sf::Event::Closed:
					App.close();
					break;

				case sf::Event::MouseButtonPressed:

					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

						switch(gameLogic.state.getState()){//TODO: put in event handler

							case GameState::State::TITLE:
								gameLogic.titlePage.changeToLevelSelect(gameLogic.state);
								break;
						}
						//this -> checkMouseOverPlatform
					}
					break;

				case sf::Event::MouseButtonReleased:
					//this -> releaseAllPlatforms();
					break;

				default:
					break;
			}
		}

		gameLogic.updateGame();
	}

	// Done.
	return 0;
}
