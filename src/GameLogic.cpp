#include "GameLogic.h"

using namespace escape;

/*
* GameLogic Constructor
*/
GameLogic::GameLogic(){
	//Game State
	this -> state.setState(GameState::State::TITLE);

	this -> World = NULL;
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
				delete this -> World;
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

							case GameState::State::STORY:
								this -> state.setState(GameState::State::LOADING);
								break;

							case GameState::State::SETUP:
								this -> eventManager.checkMouseOverPlatform(sf::Mouse::getPosition(*App), this -> level.platforms);
								this -> level.finishButton.changeToPlay(sf::Mouse::getPosition(*App), this -> state);

								if(this -> state.getState() == GameState::State::PLAY){

									for (int i = 0; i < this -> level.platforms.size(); i++){
										if(!this -> level.platforms[i].show){
											this -> World -> DestroyBody(this -> level.platforms[i].Body);
										}
									}
								}
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
							sf::Vector2i mousePosition = sf::Mouse::getPosition(*App);
							if (mousePosition.x >= 0 && mousePosition.x <= 800 && mousePosition.y >= 0 && mousePosition.y <= 600){
								this -> state.setState(GameState::State::LOADING);
							}
							break;
					}
				break;
			}

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
	//Delete World Bodies
	if (this -> World != NULL){
		for (b2Body* BodyIterator = this -> World -> GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext()){
			BodyIterator -> GetWorld() -> DestroyBody( BodyIterator );
		}
	}
	delete this -> World;
	this -> level = this -> factory.makeLevel(level);

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
