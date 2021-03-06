#include "TitlePage.h"

using namespace escape;

/*
* Constructor
*/
TitlePage::TitlePage(){
	this -> title.setString("The Great Escape");
	this -> title.setCharacterSize(75);
	this -> title.setFillColor(sf::Color::White);

	this -> play.setString("play");
	this -> play.setCharacterSize(50);
	this -> play.setFillColor(sf::Color::White);
}

/*
* Checks if mouse cliked "play" button, and if it has, changes game state to level select
* @param mousePosition: current position of mouse as related to current window
* @param state: current game state
*/
void TitlePage::changeToLevelSelect(sf::Vector2i mousePosition, GameState &state){
  sf::FloatRect playBoundingRectangle = this -> play.getGlobalBounds();

  if(playBoundingRectangle.contains(mousePosition.x, mousePosition.y)){
      state.setState(GameState::State::LEVELSELECT);
  }
}
