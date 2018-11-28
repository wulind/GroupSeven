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
	b2Vec2 Gravity(0.f, 8.0f);
	this -> World = new b2World(Gravity);

	//LevelFactory & Level
	this -> factory = LevelFactory();

	//TitlePage
	this -> titlePage = TitlePage();

	//Resources
	this -> resources = ResourceManager();
}

/*
* Polls game events, to be replaced by EventHandler
* @param *App: pointer to current window
*/
void GameLogic::pollEvent(sf::RenderWindow *App, sf::Clock gameTime, double targetMs){//TODO: put clock in main loop
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
							this -> titlePage.changeToLevelSelect(sf::Mouse::getPosition(*App), this -> state);
							break;

						case GameState::State::LEVELSELECT:
							this -> levelSelect.levelClick(sf::Mouse::getPosition(*App), this -> state);
							break;

						case GameState::State::SETUP:
							this -> eventManager.checkMouseOverPlatform(sf::Mouse::getPosition(*App), this -> level.platforms);
							this -> level.finishButton.changeToPlay(sf::Mouse::getPosition(*App), this -> state);
							break;
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				if (this -> state.getState() == GameState::State::SETUP){
					this -> eventManager.releaseAllPlatforms(this -> level.platforms);
				}
			}
		}
	//Get the elapsed time since the loop started
	double deltaMs = gameTime.getElapsedTime().asMilliseconds();

	//Adjust game timing by sleeping
	if(deltaMs < targetMs){
		sf::sleep(sf::milliseconds(targetMs-deltaMs));
	}

}

/*
* Loads level using level factory
* @param level: int representation of current level to load
*/
void GameLogic::loadLevel(int level){
	this -> level = *this -> factory.makeLevel(level, this -> World);
}

/*
* Progresses the simluation in the Box2D world
*/
void GameLogic::progressSimluation(){
	this -> level.stolenObject.updatePosition();
	this -> World -> Step(1.f/1000.f, 5, 8);
}
