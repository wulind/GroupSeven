#include "../include/GameState.h"

using namespace escape;

/*
* GameState Constructor
*/
GameState::GameState(){
  this -> state = GameState::State::TITLE;
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
* Gets current game state
*/
GameState::State GameState::getState(){
  return this -> state;
}
