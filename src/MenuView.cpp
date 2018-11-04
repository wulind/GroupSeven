#include "../include/MenuView.h"

using namespace escape;

MenuView::MenuView(){}

/*
* @param *App: pointer to game window
*/
MenuView::MenuView(sf::RenderWindow *App){
	this -> App = App;
}

/*
* updates the screen to whichever menu (title, level selection) is required
* @param state: current game state
*/
MenuView::update(GameState state){
  if(state == GameState::title){
    this -> loadTitleScreen();
  } else if (state == GameState::levelSelect){
    this -> loadLevelSelect();
  }
}

/*
* Loads title screen
*/
MenuView::loadTitleScreen(){

}

/*
* Loads level selection screen
*/
MenuView::loadLevelSelect(){

}
