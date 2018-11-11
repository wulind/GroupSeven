#include "LevelSelect.h"

using namespace escape;

/*
* Constructor
* @param *App: Render Window
*/
LevelSelect::LevelSelect(sf::RenderWindow *App){
  this -> App = App;

}

/*
* Checks if mouse cliked on a dot in the level map and plays that level
* @param &App: Reference to current window
* @param state: current game state
*/
void LevelSelect::selectLevel(sf::RenderWindow &App, GameState &state){
  sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
  sf::FloatRect playBoundingRectangle = this -> play.getGlobalBounds();

  if(playBoundingRectangle.contains(mousePosition.x, mousePosition.y)){
      state.setState(GameState::State::SETUP);
  }

}
