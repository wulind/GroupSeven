#include "../include/GameState.h"

using namespace escape;

/*
* GameState Constructor
*/
GameState::GameState(){
  this -> state = GameState::State::TITLE;
  this -> currentLevel = 1;
}

/*
* Sets current game state
* @param _state: Next game state
* TODO: place checks so that you can't jump from not logical game state to game state
*/
void GameState::setState(GameState::State _state){
  this -> state = _state;
}

/*
* Increases highest level available to play
*/
void GameState::incrementCurrentLevel(){
  ++this -> currentLevel;
}

/*
* Gets current game state
*/
GameState::State GameState::getState(){
  return this -> state;
}

/*
* Gets current level
*/
int GameState::getCurrentLevel(){
  return this -> currentLevel;
}

void GameState::setCurrentLevel(int level){
	this -> currentLevel = level;
}