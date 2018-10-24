#include "../include/GameState.h"

using namespace escape;

GameState::GameState(){
  this -> play = 0;
}

void GameState::setState(int state){
  this -> play = state;
}
