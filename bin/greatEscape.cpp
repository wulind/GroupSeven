#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "GameView.h"
#include "MenuView.h"

using namespace escape;

void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView);

int main(int argc, char** argv){

	//Game Logic
	GameLogic gameLogic = GameLogic();

	//Game Time for fps
	sf::Clock gameTime;

	//Views
	GameView mainView(gameLogic.resources.getFont());
	MenuView menuView(mainView.getApp(), gameLogic.resources.getFont());

	//Target 60 fps
    double targetMs = 1000/60;	

	// start main loop
	while(mainView.getApp() -> isOpen()) {

    gameLogic.pollEvent(mainView.getApp(), gameTime, targetMs);
		updateGame(gameLogic, menuView, mainView);
	}

	// Done.
	return 0;
}

/*
* Checks game state and updates screen based on that
*/
void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView){
	switch(gameLogic.state.getState()){
		case GameState::State::TITLE:
			menuView.loadTitleScreen(gameLogic.titlePage);
			break;

		case GameState::State::LEVELSELECT:
			menuView.loadLevelSelect(&gameLogic.state);
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
