#include "GameLogic.h"

using namespace escape;

/*
* GameLogic Constructor
* @param *App: pointer to game window
*/
GameLogic::GameLogic(){
	//Game State
	this -> state.setState(GameState::State::TITLE);

	//TitlePage
	this -> titlePage = TitlePage();

	//Resources
	this -> resources = ResourceManager();
}

/*
* Polls game events, to be replaced by EventHandler
* @param *App: pointer to current window
*/
void GameLogic::pollEvent(sf::RenderWindow *App){
	// process events
	sf::Event event;
	while(App -> pollEvent(event)) {

		switch (event.type) {

			case sf::Event::Closed:
				App -> close();// TODO: move in GameView?
				break;

			case sf::Event::MouseButtonPressed:

				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

					switch(this -> state.getState()){//TODO: put in event handler

						case GameState::State::TITLE:
							this -> titlePage.changeToLevelSelect(*App, this -> state);
							break;
					}
				}
				break;

			default:
				break;
		}
	}
}
