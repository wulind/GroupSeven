#include "GameLogic.h"

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
