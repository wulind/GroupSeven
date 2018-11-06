#include "../include/GameState.h"

using namespace escape;

GameState::GameState(){
  this -> state = TITLE;
}

void GameState::setState(GameState::State _state){
  this -> state = _state;
}

GameState::State GameState::getState(){
  return this -> state;
}
