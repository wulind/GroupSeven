#include "../include/MenuView.h"

using namespace escape;

MenuView::MenuView(){}

/*
* MenuView Constructor
* @param *App: pointer to game window
*/
MenuView::MenuView(sf::RenderWindow *App){
	this -> App = App;
}

/*
* Updates the screen to whichever menu (title, level selection) is required
* @param state: current game state
*/
void MenuView::update(GameState &state){
  switch(state.getState()){
			case GameState::State::TITLE:
				this -> loadTitleScreen();
				break;

			case GameState::State::LEVELSELECT:
				this -> loadLevelSelect();
				break;
	}
}

/*
* Loads title screen
*/
void MenuView::loadTitleScreen(){
	this -> App -> clear(sf::Color::Black);

	sf::Text title;
	sf::Text play;
	sf::Font font;

	if (!font.loadFromFile("../data/aliensCows.ttf")){
    // TODO:error...
  }

  title.setFont(font);
  title.setString("The Great Escape");
  title.setCharacterSize(75);
	title.setPosition((this -> screenX/2.0f)-(title.getLocalBounds().width/2.0f), 50);
  title.setFillColor(sf::Color::White);

	play.setFont(font);
  play.setString("play");
  play.setCharacterSize(50);
	play.setPosition((this -> screenX/2.0f)-(play.getLocalBounds().width/2.0f), 500);
  play.setFillColor(sf::Color::White);

	this -> drawText(title);
	this -> drawText(play);

	this -> App -> display();
}

/*
* Loads level selection screen
*/
void MenuView::loadLevelSelect(){

}

void MenuView::drawText(sf::Text text) {
	this -> App -> draw(text);
}
