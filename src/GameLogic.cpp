#include "GameLogic.h"

static const float SCALE = 30.f;

using namespace escape;

/*
* GameLogic Constructor
* @param *App: pointer to game window
*/
GameLogic::GameLogic(){
	//Game State
	this -> state.setState(GameState::State::TITLE);

	//Initializes world.
	//Takes in Gravity (change second param to change gravity)
	b2Vec2 Gravity(0.f, 1.0f);
	this -> World = new b2World(Gravity);

	//TitlePage
	this -> titlePage = TitlePage();

	//Resources
	this -> resources = ResourceManager();
}

/*
* Polls game events, to be replaced by EventHandler
* @param *App: pointer to current window
*/
void GameLogic::pollEvent(sf::RenderWindow *App, sf::Clock gameTime, double targetMs){
	// process events
	sf::Event event;
	while(App -> pollEvent(event)) {
		gameTime.restart();
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
	//Get the elapsed time since the loop started
	double deltaMs = gameTime.getElapsedTime().asMilliseconds();

	//Adjust game timing by sleeping
	if(deltaMs < targetMs){
		sf::sleep(sf::milliseconds(targetMs-deltaMs));
	}

}
