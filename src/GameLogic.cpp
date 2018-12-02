#include "GameLogic.h"

using namespace escape;

/*
* GameLogic Constructor
*/
GameLogic::GameLogic(){
	//Game State
	this -> state.setState(GameState::State::TITLE);

	//Initializes world.
	//Takes in Gravity (change second param to change gravity)
	b2Vec2 Gravity(0.f, 15.f);
	this -> World = new b2World(Gravity);
}

/*
* Polls game events, to be replaced by EventHandler
* @param *App: pointer to current window
*/
void GameLogic::pollEvent(sf::RenderWindow *App, sf::Clock gameTime, double targetMs){//TODO: put clock in main loop
	// process events
	sf::Event event;
	sf::Vector2i mousePosition;
	while(App -> pollEvent(event)) {
		gameTime.restart();
		switch (event.type) {

			case sf::Event::Closed:
				delete this -> World;
				App -> close();// TODO: move in GameView?
				break;

			case sf::Event::KeyPressed:
				if(this -> state.getState() == GameState::State::STORY){
					this -> state.setState(GameState::State::LOADING);
				}
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

						case GameState::State::STORY:
							mousePosition = sf::Mouse::getPosition(*App);
							if (mousePosition.x >= 0 && mousePosition.x <= 800 && mousePosition.y >= 0 && mousePosition.y <= 600){
								this -> state.setState(GameState::State::LOADING);
							}
							break;
						case GameState::State::SUCCESS:
							mousePosition = sf::Mouse::getPosition(*App);
							if (mousePosition.x >= 0 && mousePosition.x <= 800 && mousePosition.y >= 0 && mousePosition.y <= 600){
								this -> state.setState(GameState::State::LEVELSELECT);
							}
							break;
						case GameState::State::FAIL:
							mousePosition = sf::Mouse::getPosition(*App);
							if (mousePosition.x >= 0 && mousePosition.x <= 800 && mousePosition.y >= 0 && mousePosition.y <= 600){
								this -> state.setState(GameState::State::LEVELSELECT);
							}
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
* Adds the next glowing orb that represents the next level available
* Only adds one at a time because only one new level can be unlocked at a time
*/
void GameLogic::makeNextLevelDot(){
  if (this -> state.getUnlockedLevels() > this -> levelSelect.levels.size()){
		this -> levelSelect.appendDot(this -> factory.makeOrbs(this -> state.getUnlockedLevels()));
  }
}

/*
* Loads level using level factory
* @param level: int representation of current level to load
*/
void GameLogic::loadLevel(int level){
	//Clear all bodies in the world, then delete & make a new world
	b2Body* bodyList = this -> World -> GetBodyList();
	int i = 0;
	for (bodyList; bodyList; bodyList = bodyList -> GetNext()){
		this -> World -> DestroyBody(bodyList);
 	}
	delete this -> World;

	//Make a new level
	this -> level = this -> factory.makeLevel(level);

	b2Vec2 Gravity(0.f, 15.f);
	this -> World = new b2World(Gravity);

	this -> level.setWorld(World);
}

/*
* Progresses the simluation in the Box2D world
*/
void GameLogic::progressSimluation(){
	this -> level.stolenObject.updatePosition();
	this -> World -> Step(1.f/1000.f, 5, 8);
}
