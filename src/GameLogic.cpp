#include "GameLogic.h"
#include <iostream>

static const float SCALE = 30.f;

using namespace escape;

/*
* GameLogic Constructor
*/
GameLogic::GameLogic(){
	//Game State
	this -> state.setState(GameState::State::TITLE);

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
								std::cout << "Mouse x: " << sf::Mouse::getPosition(*App).x << "  Mouse y: " << sf::Mouse::getPosition(*App).y << "\n";
								break;

							case GameState::State::STORY:
								this -> state.setState(GameState::State::LOADING);
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
					break;

				case sf::Event::KeyPressed:
					switch(this -> state.getState()){
						case GameState::State::STORY:
							this -> state.setState(GameState::State::LOADING);
							break;
					}
				break;
			}

		}
}

/*
* Loads level using level factory
* @param level: int representation of current level to load
*/
void GameLogic::loadLevel(int level){
	delete this -> World;
	this -> level = *this -> factory.makeLevel(level);

	b2Vec2 Gravity(0.f, this -> level.gravity);
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
