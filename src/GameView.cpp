#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){}

/*
* @param *App: pointer to game window
* @param &font: reference to Cows & Aliens font used throughout the game
*/
GameView::GameView(sf::Font *_font){
	this -> App.create(sf::VideoMode(800, 600, 32), "The Great Escape");
	this -> font = _font;
}

/*
* Returns current window
*/
sf::RenderWindow* GameView::getApp(){
	return &this -> App;
}

/*
* Draws any text needed for the level
* @param text: text to draw
*/
void GameView::drawText(sf::Text &text) {
	this -> App.draw(text);
}

/*
* Draws any sprite needed for the level
* @param sprite: sprite to draw
*/
void GameView::drawSprite(sf::Sprite &sprite) {
	this -> App.draw(sprite);
}

/*
* Creates all of the SFML-related objects that need to be drawn
* @param platform: platform needed for the level
* @param stolenObject: objects that need to be stolen
* @param menu: menu that contains platforms
*/
void GameView::update(Platform *platform, StolenObject *stolenObject, PlatformMenu *menu) { //TODO: Fix
	this -> App.clear(sf::Color(103, 164, 207));

	if (menu){
		menu -> update();
		this -> drawSprite(menu -> menu);
		this -> drawText(menu -> title);
	}

	if (platform){
		//TODO: load platform sprites from resources
	}

	if (stolenObject){
		//TODO: load stolen object sprites from resources
	}

	this -> App.display();
}
