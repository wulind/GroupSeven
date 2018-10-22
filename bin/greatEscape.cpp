#include "GameController.h"


int main(int argc, char** argv)
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(800,600,32), "The Great Escape");

	controller::GameController gameController(&App);

	// start main loop
	while(App.isOpen()) {
		// process events
		sf::Event Event;
		while(App.pollEvent(Event)) {

			switch (Event.type) {
				case sf::Event::Closed:
					App.close();
				case sf::Event::MouseButtonPressed:
					gameController.checkMouseOverPlatform();
				case sf::Event::MouseButtonReleased:
					gameController.releaseAllPlatforms();
			}
		}

		gameController.updateView();
	}

	// Done.
	return 0;
}
