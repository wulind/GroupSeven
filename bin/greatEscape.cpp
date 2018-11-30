#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "GameView.h"
#include "MenuView.h"
#include "Level.h"
#include "Dialogue.h"
#include <iostream>

using namespace escape;

void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView);
void drawLevel(Level &level, GameView &gameView);

int main(int argc, char** argv){

	//Game Logic
	GameLogic gameLogic = GameLogic();

	//Game Time for fps
	sf::Clock gameTime;

	//Views
	GameView mainView(gameLogic.resources.getFont());
	MenuView menuView(mainView.getApp(), gameLogic.resources.getFont());


	//Target 60 fps
  double targetMs = 1000/1000;

	// start main loop
	while(mainView.getApp() -> isOpen()) {

    gameLogic.pollEvent(mainView.getApp(), gameTime, targetMs);
		if (gameLogic.state.getState() == GameState::State::PLAY){
			gameLogic.progressSimluation();
		}


		updateGame(gameLogic, menuView, mainView);

		//Get the elapsed time since the loop started
		double deltaMs = gameTime.getElapsedTime().asMilliseconds();
		std::cout << deltaMs << "\n";

		//Adjust game timing by sleeping
		if(deltaMs < targetMs){
			std::cout << "Ahead, sleeping";
			sf::sleep(sf::milliseconds(targetMs-deltaMs));
		}
		//If behind skip frames
		else{

			if (gameLogic.state.getState() == GameState::State::PLAY){
				std::cout << "Skipping Frames..." << "\n";
				int change = deltaMs - targetMs;
				for (int x; x < change; x++){
					gameLogic.progressSimluation();
				}
			}
		}

		gameTime.restart();
	}

	// Done.
	return 0;
}

/*
* Checks game state and updates screen based on that
*/
void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView){
	Dialogue dialogue = Dialogue();
	switch(gameLogic.state.getState()){
		case GameState::State::TITLE:
			menuView.loadTitleScreen(gameLogic.titlePage);
			break;

		case GameState::State::LEVELSELECT:
			menuView.loadLevelSelect(gameLogic.levelSelect);
			break;

		case GameState::State::LOADING:
			gameLogic.loadLevel(gameLogic.state.getCurrentLevel());
			drawLevel(gameLogic.level, gameView);
			gameLogic.state.setState(GameState::State::SETUP);
			break;

		case GameState::State::SETUP:
			gameLogic.eventManager.updateMouse(sf::Mouse::getPosition(*gameView.getApp()), gameLogic.level.platforms);
			gameView.setGraphics(gameLogic.level);
			drawLevel(gameLogic.level, gameView);
			break;

		case GameState::State::STORY:
			dialogue.playStory(gameView.getApp(), &gameLogic.state, gameLogic.state.getCurrentLevel());
			break;

		case GameState::State::PLAY:
			drawLevel(gameLogic.level, gameView);
			break;

		case GameState::State::SUCCESS:
			gameLogic.state.incrementCurrentLevel();
			break;

		case GameState::State::FAIL:
			break;
	}
}

/*
* Uses game view to draw level
* @param level: level object that holds everything needed to draw
* @param gameView: gameView object
*/
void drawLevel(Level &level, GameView &gameView){
	gameView.update(level);
}
