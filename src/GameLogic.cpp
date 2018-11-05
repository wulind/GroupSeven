#include "../include/GameLogic.h"

using namespace escape;

/*
* @param *App: pointer to game window
*/
GameLogic::GameLogic(sf::RenderWindow *App){
	this -> App = App;
	this -> mainView = GameView(App);

	this -> platform = Platform(50, 50, 20, 100);
	this -> stolenObject = StolenObject(100, 100, 25);
	this -> menu = PlatformMenu(App);
}

/*
* Main loop
*/
int GameLogic::gameLoop(){
  // start main loop
	while(this -> App -> isOpen()) {

    // process events
		sf::Event event;
		while(this -> App -> pollEvent(event)) {

			switch (event.type) {
				case sf::Event::Closed:
					this -> App -> close();
					break;
				case sf::Event::MouseButtonPressed:
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						this -> checkMouseOverPlatform();
					}
					break;
				case sf::Event::MouseButtonReleased:
					this -> releaseAllPlatforms();
					break;
				default:
					break;
			}
		}

		this -> updateMouse();

		this -> mainView.update(&this -> platform, &this -> stolenObject, &this -> menu);
	}
}

/*
* Checks game state and updates screen based on that
*/
void updateGame();


