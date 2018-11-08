#include "GameLogic.h"
#include <iostream>
using namespace escape;

/*
* GameLogic Constructor
* @param *App: pointer to game window
*/
GameLogic::GameLogic(sf::RenderWindow *App){
	this -> App = App;

	//Views
	sf::Font font;
	if (!font.loadFromFile("../data/aliensCows.ttf")){
		// TODO:error...
	}

	this -> mainView = GameView(this -> App, font);
	this -> menuView = MenuView(this -> App, font);

	//Game State
	this -> state.setState(GameState::State::TITLE);

	//TitlePage
	this -> titlePage = TitlePage(this -> App);

	//Test platforms & stolen objects
	//TODO: get rid of them
	//this -> platform = Platform(50, 50, 20, 100);
	//this -> stolenObject = StolenObject(100, 100, 25);

	//this -> menu = PlatformMenu(App);
	//this -> finishButton = FinishButton(App);
}

/*
* Main loop
* TODO: where does loop go?
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

						switch(this -> state.getState()){//TODO: put in event handler
							case GameState::State::TITLE:
								this -> titlePage.changeToLevelSelect(this -> state);
								break;
						}
						//this -> checkMouseOverPlatform();
					}
					break;

				case sf::Event::MouseButtonReleased:
					//this -> releaseAllPlatforms();
					break;

				default:
					break;
			}
		}

		this -> updateGame();
		//this -> updateMouse();
		//this -> mainView.update(&this -> platform, &this -> stolenObject, &this -> menu);
	}
}

/*
* Checks game state and updates screen based on that
*/
void GameLogic::updateGame(){
	switch(this -> state.getState()){
		case GameState::State::TITLE:
			this -> menuView.loadTitleScreen(this -> titlePage);
			break;

		case GameState::State::LEVELSELECT:
			this -> menuView.loadLevelSelect();
			break;

		case GameState::State::LOADING:
			break;

		case GameState::State::SETUP:
			break;

		case GameState::State::PLAY:
			break;

		case GameState::State::SUCCESS:
			break;

		case GameState::State::FAIL:
			break;
	}
}

/*bool GameLogic::checkMouseOverPlatform(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	float mouseX = mousePosition.x;
	float mouseY = mousePosition.y;

	float platformXStart = this -> platform.xCoord;
	float platformYStart = this -> platform.yCoord;

	float platformXEnd = platformXStart + this -> platform.width;
	float platformYEnd = platformYStart + this -> platform.height;

	bool hitsX = (platformXStart <= mouseX && mouseX <= platformXEnd);
	bool hitsY = (platformYStart <= mouseY && mouseY <= platformYEnd);

	if (hitsX && hitsY) {
		this -> platform.isBeingDragged = true;

		this -> platform.mouseDragOffsetX = mouseX - platformXStart;
		this -> platform.mouseDragOffsetY = mouseY - platformYStart;

		return true;
	}
	return false;
}

void GameLogic::releaseAllPlatforms(){
	this -> platform.isBeingDragged = false;
}

void GameLogic::updateMouse(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	this -> platform.updateDragPosition(mousePosition.x, mousePosition.y);
}*/
