#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "GameView.h"
#include "MenuView.h"
#include "Level.h"

using namespace escape;

void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView);
void drawLevel(Level &level, GameView &gameView);
void writeDialogue(GameLogic &gameLogic, GameView &gameView);

int main(int argc, char** argv){

	//Game Logic
	GameLogic gameLogic = GameLogic();

	//Game Time for fps
	sf::Clock gameTime;

	//Views
	GameView mainView(gameLogic.resources.getFont(), gameLogic.resources.getBackgroundTexture(), gameLogic.resources.getObjectTexture());
	MenuView menuView(mainView.getApp(), gameLogic.resources.getFont(), gameLogic.resources.getMapTexture(), gameLogic.resources.getLevelDot());

	//Target 60 fps
  double targetMs = 1000/240;

	// start main loop
	while(mainView.getApp() -> isOpen()) {

    gameLogic.pollEvent(mainView.getApp(), gameTime, targetMs);
		if (gameLogic.state.getState() == GameState::State::PLAY){
			gameLogic.progressSimluation();
		}
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
			gameView.pauseMusic();
			menuView.playMusic();
			menuView.loadTitleScreen(gameLogic.titlePage);
			break;

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
			drawLevel(gameLogic.level, gameView);
			gameLogic.state.setState(GameState::State::SETUP);
			break;

		case GameState::State::SETUP:
			gameLogic.eventManager.updateMouse(sf::Mouse::getPosition(*gameView.getApp()), gameLogic.level.platforms);
			drawLevel(gameLogic.level, gameView);
			break;

		case GameState::State::PLAY:
			drawLevel(gameLogic.level, gameView);
			break;

		case GameState::State::SUCCESS:
			gameLogic.state.incrementUnlockedLevels();
			gameLogic.state.setState(GameState::State::LEVELSELECT);
			break;

		case GameState::State::FAIL:
			gameLogic.dialogue.loseLevel();
			writeDialogue(gameLogic, gameView);
			gameLogic.state.setState(GameState::State::LEVELSELECT);
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

/*
* Calls on game view to write dialogue pages
*/
void writeDialogue(GameLogic &gameLogic, GameView &gameView){
	gameView.displayLevelStory(gameLogic.dialogue.text);
}
