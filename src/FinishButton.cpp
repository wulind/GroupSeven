#include "../include/FinishButton.h"

using namespace escape;

/*
* FinishButton Constructor
* @param *App: pointer to game window
*/
FinishButton::FinishButton(){
  this -> scale = .2f;

  //Setup finish button
  this -> button.setString("finish");
  this -> button.setCharacterSize(50);
  this -> button.setFillColor(sf::Color::White);
  this -> button.setPosition(640, 510);
}


/*
* Updates the finish button based off the game state
* If the player is in design mode & clicks button, switch mode to play mode and get rid of the button
* @param &state: current state of the game
*/
void FinishButton::changeToPlay(sf::Vector2i mousePosition, GameState &state){
  //Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
  int relativeX = 640;
  int relativeY = 510;

  sf::FloatRect size = button.getGlobalBounds();

  //If the mouse clicks on the finish button then set state to play
  if(mousePosition.x >= relativeX && mousePosition.x <= relativeX+size.width && mousePosition.y >= relativeY && mousePosition.y <= relativeY+size.height){
          state.setState(GameState::State::PLAY);
  }
}
