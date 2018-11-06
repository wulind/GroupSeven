#include "../include/GameState.h"

using namespace escape;
/*
 * GameState constructor 
 */
GameState::GameState(){
    //Default is in design mode
  this -> play = 0;
}
/*
 * Sets the game state, represented by an integer value
 */
void GameState::setState(int state){
  this -> play = state;
}
