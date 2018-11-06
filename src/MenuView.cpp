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
* updates the screen to whichever menu (title, level selection) is required
* @param state: current game state
*/
void MenuView::update(GameState &state){
  switch(state.getState()){
			case GameState::State::TITLE:
				break;

			case GameState::State::LEVELSELECT:
				break;
	}
}

/*
* Loads title screen
*/
void MenuView::loadTitleScreen(){

}

/*
* Loads level selection screen
*/
void MenuView::loadLevelSelect(){

}
