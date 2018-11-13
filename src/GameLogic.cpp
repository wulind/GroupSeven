#include "GameLogic.h"

static const float SCALE = 30.f;

using namespace escape;

/*
* GameLogic Constructor
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

						case GameState::State::LEVELSELECT:
							this -> changeToLoading();
							break;
					}
				}
				break;

			default:
				break;
		}
	}
}

/*
* Sets the state to loading when the user clicks the mouse anywhere on the level select screen
* Temporary solution
* TODO: Move into levelSelect class
*/
void GameLogic::changeToLoading(){
	state.setState(GameState::State::LOADING);
}

/*
* Loads level using level factory
* @param level: int representation of current level to load
*/
void GameLogic::loadLevel(int level){
	this -> factory.readXML();
}
