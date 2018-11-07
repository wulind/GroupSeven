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



void MenuView::drawText(sf::Text &text){
	this -> App -> draw(text);
}
