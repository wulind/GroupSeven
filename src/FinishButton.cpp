#include "FinishButton.h"

using namespace escape;

/*
* FinishButton Constructor
*/
FinishButton::FinishButton(){
  this -> scale = .2f;

  //Setup finish button
  this -> button.setString("finish");
  this -> button.setCharacterSize(50);
  this -> button.setPosition(640, 510);

  this -> show = true;
}


/*
* Updates the finish button based off the game state
* If the player is in design mode & clicks button, switch mode to play mode and get rid of the button
* @param mousePosition: current position of the mouse
* @param &state: current state of the game
*/
void FinishButton::changeToPlay(sf::Vector2i mousePosition, GameState &state){
  //Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
  sf::FloatRect boundingRectangle = button.getGlobalBounds();

  //If the mouse clicks on the finish button then set state to play
  if(boundingRectangle.contains(mousePosition.x, mousePosition.y)){
          state.setState(GameState::State::PLAY);
          this -> show = false;
  }
}
