#include "../include/TitlePage.h"

using namespace escape;

TitlePage::TitlePage(){}

/*
* Constructor
* @param *App: Render Window
* @param &_state: Current Game State
*/
TitlePage::TitlePage(sf::RenderWindow *App){
  this -> App = App;

	this -> title.setString("The Great Escape");
  this -> title.setCharacterSize(75);
	this -> title.setFillColor(sf::Color::White);


	this -> play.setString("play");
	this -> play.setCharacterSize(50);
	this -> play.setFillColor(sf::Color::White);

}

/*
* Checks if mouse cliked "play" button, and if it has, changes game state to level select
* @param state: current game state
*/
void TitlePage::changeToLevelSelect(GameState &state){
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*this -> App);
  sf::FloatRect playBoundingRectangle = this -> play.getGlobalBounds();

  if(playBoundingRectangle.contains(mousePosition.x, mousePosition.y)){
      state.setState(GameState::State::LEVELSELECT);
  }

}
