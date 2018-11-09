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
void GameView::update(Platform *platform, StolenObject *stolenObject, PlatformMenu *menu, Platform *base, GameState *state) { //TODO: Fix
	this -> App.clear(sf::Color(103, 164, 207));

	if (menu){
		menu -> update(state);
		this -> drawSprite(menu -> menu);
		this -> drawText(menu -> title);
	}

	if (platform){
		sf::RectangleShape rectangle(sf::Vector2f(platform -> width, platform -> height)); //TODO: fix
		rectangle.setOrigin(platform -> width/2, platform -> height/2);
		//shape.setSize(sf::Vector2f(platform->width, platform->height));
		rectangle.setPosition(platform -> xCoord, platform -> yCoord);
		rectangle.setFillColor(platform -> color);

		//this -> drawPlatform(rectangle);
	}

	if (base){
		sf::RectangleShape rectangle(sf::Vector2f(base -> width, base -> height)); //TODO: fix
		rectangle.setOrigin(base -> width/2, base -> height/2);
		//shape.setSize(sf::Vector2f(platform->width, platform->height));
		rectangle.setPosition(base -> xCoord, base -> yCoord);
		rectangle.setFillColor(base -> color);

		//this -> drawPlatform(rectangle);
	}

	if (stolenObject){
		sf::CircleShape circle(stolenObject -> radius); //TODO: fix
		circle.setOrigin(stolenObject -> radius,stolenObject -> radius);
		circle.setPosition(stolenObject -> xCoord, stolenObject -> yCoord);
		circle.setFillColor(stolenObject -> color);
		//TODO: Smooth it out when we pick a texture
		//this -> drawStolenObject(circle);
	}

	this -> App.display();
}
