#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "GameView.h"
#include "MenuView.h"
#include "Options.h"

using namespace escape;

void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView, Options &options);
void drawLevel(Level &level, GameView &gameView, bool play);
void writeDialogue(GameLogic &gameLogic, GameView &gameView);
void drawOptionsMenu(MenuView &menuView, Options &options, GameState &state);

int main(int argc, char** argv){

	//Game Logic
	GameLogic gameLogic = GameLogic();

	//Game Time for fps
	sf::Clock gameTime;

	//Options
	Options options = Options();

	//Views
	GameView mainView(gameLogic.resources.getFont(), gameLogic.resources.getBackgroundTexture(), gameLogic.resources.getObjectTexture());
	MenuView menuView(mainView.getApp(), gameLogic.resources.getFont(), gameLogic.resources.getBackgroundTexture(), gameLogic.resources.getObjectTexture());

	//Target 1000 fps
  double targetMs = 1000/480;

	// start main loop
	while(mainView.getApp() -> isOpen()) {

    gameLogic.pollEvent(mainView.getApp(), gameTime, targetMs);
		if (gameLogic.state.getState() == GameState::State::PLAY){
			gameLogic.progressSimluation();
		}

		updateGame(gameLogic, menuView, mainView, options);

		//Get the elapsed time since the loop started
		double deltaMs = gameTime.getElapsedTime().asMilliseconds();

		//Adjust game timing by sleeping
		if(deltaMs < targetMs){
			sf::sleep(sf::milliseconds(targetMs-deltaMs));
		}
		//If behind skip frames
		else{
			if (gameLogic.state.getState() == GameState::State::PLAY){
				gameLogic.partialProgressSimluation(deltaMs - targetMs);
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
void updateGame(GameLogic &gameLogic, MenuView &menuView, GameView &gameView, Options &options){
	switch(gameLogic.state.getState()){
		case GameState::State::TITLE:
			if (gameView.musicPlaying){
				gameView.pauseMusic();
				gameView.musicPlaying = false;
			}
			if (!menuView.musicPlaying){
				menuView.playMusic(options.volumeOn());
				menuView.musicPlaying = true;
			}
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
			if (menuView.musicPlaying){
				menuView.pauseMusic();
				menuView.musicPlaying = false;
			}
			if (!gameView.musicPlaying){
				gameView.playMusic(options.volumeOn());
				gameView.musicPlaying = true;
			}
			gameLogic.loadLevel(gameLogic.state.getCurrentLevel());
			drawLevel(gameLogic.level, gameView, false);
			gameLogic.state.setState(GameState::State::SETUP);
			break;

		case GameState::State::SETUP:
			gameLogic.eventManager.updateMouse(sf::Mouse::getPosition(*gameView.getApp()), gameLogic.level.platforms);
			drawLevel(gameLogic.level, gameView, false);
			break;

		case GameState::State::PLAY:
			drawLevel(gameLogic.level, gameView, true);

			//If stolen object breaks, failure
			if (gameLogic.level.stolenObject.health == 0){
				gameLogic.level.stolenObject.killSpeed();
			}

			if (gameLogic.level.goal.detectWin(gameLogic.level.stolenObject) > 0){
					gameLogic.state.setState(GameState::State::SUCCESS);
			}else if (!gameLogic.level.goal.detectWin(gameLogic.level.stolenObject)){
					gameLogic.state.setState(GameState::State::FAIL);
			}
			break;
		case GameState::State::OPTIONS:
			drawOptionsMenu(menuView, options, gameLogic.state);
			break;

		case GameState::State::SUCCESS:

			gameLogic.dialogue.winLevel();
			writeDialogue(gameLogic, gameView);

			if (gameLogic.state.getCurrentLevel() == gameLogic.state.getUnlockedLevels()){
			  if(gameLogic.state.getUnlockedLevels() == 10 && gameLogic.state.getCurrentLevel() == 12){
			    gameLogic.state.setState(GameState::State::FINISHGAME);
			  }else{
			    gameLogic.state.incrementUnlockedLevels();
			  }
			}
			break;

		case GameState::State::FAIL:
			gameLogic.dialogue.loseLevel();
			writeDialogue(gameLogic, gameView);
			break;

		case GameState::State::FINISHGAME:
			gameLogic.dialogue.winGame();
			writeDialogue(gameLogic, gameView);
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

void drawOptionsMenu(MenuView &menuView, Options &options, GameState &state){
	options.adjustVolume(state);
	menuView.drawOptionsMenu(options);
}
