#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "GameView.h"
#include "MenuView.h"

using namespace escape;

void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView);
void drawLevel(Level &level, GameView &gameView, bool play);
void writeDialogue(GameLogic &gameLogic, GameView &gameView);

//Game timer for scoring
Timer timer = Timer();

int main(int argc, char** argv){

	//Game Logic
	GameLogic gameLogic = GameLogic();

	//Game Time for fps
	sf::Clock gameTime;

	//Views
	GameView mainView(gameLogic.resources.getFont(), gameLogic.resources.getNumFont(), gameLogic.resources.getBackgroundTexture(), gameLogic.resources.getObjectTexture(), &timer);
	MenuView menuView(mainView.getApp(), gameLogic.resources.getFont(), gameLogic.resources.getMapTexture(), gameLogic.resources.getLevelDot());


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

		//Adjust game timing by sleeping
		if(deltaMs < targetMs){
			sf::sleep(sf::milliseconds(targetMs-deltaMs));
		}
		//If behind skip frames
		else{
			if (gameLogic.state.getState() == GameState::State::PLAY){
				int change = deltaMs - targetMs;
				for (int x = 0; x < change; x++){
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
	switch(gameLogic.state.getState()){
		//Title Screen
		case GameState::State::TITLE:
			gameView.pauseMusic();
			menuView.playMusic();
			menuView.loadTitleScreen(gameLogic.titlePage);
			break;

		//Level Selection page
		case GameState::State::LEVELSELECT:
			menuView.loadLevelSelect(gameLogic.levelSelect);
			gameLogic.makeNextLevelDot();
			break;

		case GameState::State::STORY:
			gameLogic.dialogue.playStory(gameLogic.state.getCurrentLevel());
			writeDialogue(gameLogic, gameView);
			break;

		case GameState::State::LOADING:
			menuView.pauseMusic();
			gameView.playMusic();
			gameLogic.loadLevel(gameLogic.state.getCurrentLevel());
			drawLevel(gameLogic.level, gameView, false);
			gameLogic.state.setState(GameState::State::SETUP);
			break;

		case GameState::State::SETUP:
			gameLogic.eventManager.updateMouse(sf::Mouse::getPosition(*gameView.getApp()), gameLogic.level.platforms);
			drawLevel(gameLogic.level, gameView, false);
			break;

		case GameState::State::PLAY:

			timer.tickClock();

			drawLevel(gameLogic.level, gameView, true);

			if (gameLogic.level.goal.detectWin(gameLogic.level.stolenObject) > 0){
					gameLogic.state.setState(GameState::State::SUCCESS);
			}else if (!gameLogic.level.goal.detectWin(gameLogic.level.stolenObject)){
					gameLogic.state.setState(GameState::State::FAIL);
			}
			break;

		case GameState::State::SUCCESS:
			if (gameLogic.state.getCurrentLevel() == gameLogic.state.getUnlockedLevels()){
				gameLogic.state.incrementUnlockedLevels();
			}
			gameLogic.state.setState(GameState::State::LEVELSELECT);
			break;

		case GameState::State::FAIL:
			gameLogic.state.setState(GameState::State::LEVELSELECT);
			break;
	}
}

/*
* Uses game view to draw level
* @param level: level object that holds everything needed to draw
* @param gameView: gameView object
* @param play: true if game state is State::PLAY
*/
void drawLevel(Level &level, GameView &gameView, bool play){
	gameView.update(level, play);
}

/*
* Calls on game view to write dialogue pages
*/
void writeDialogue(GameLogic &gameLogic, GameView &gameView){
	gameView.displayLevelStory(gameLogic.dialogue.text);
}
