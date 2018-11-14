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
* Gets current position of mouse in relation to the current render window
*/
sf::Vector2i GameView::getMousePosition(){
	return sf::Mouse::getPosition(this -> App);
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
* TODO: get rid of these
*/
void GameView::drawRectangle(sf::RectangleShape &rect) {
	this -> App.draw(rect);
}
void GameView::drawCircle(sf::CircleShape &circle) {
	this -> App.draw(circle);
}

/*
* Creates all of the SFML-related objects that need to be drawn
* @param platform: platform needed for the level
* @param stolenObject: objects that need to be stolen
* @param menu: menu that contains platforms
*/
void GameView::update(Level &level){//Platform *platform, StolenObject *stolenObject, PlatformMenu *menu, Platform *base) { //TODO: Fix
	this -> App.clear(sf::Color::Black);

	// if (menu){
	// 	this -> drawSprite(menu -> menu);
	// 	this -> drawText(menu -> title);
	// }
	sf::RectangleShape platform(sf::Vector2f(level.platform.width, level.platform.height)); //TODO: fix
	platform.setOrigin(level.platform.width/2, level.platform.height/2);
	//shape.setSize(sf::Vector2f(platform->width, platform->height));
	platform.setPosition(level.platform.xCoord, level.platform.yCoord);
	platform.setFillColor(level.platform.color);
	this -> drawRectangle(platform);


	sf::RectangleShape rectangle(sf::Vector2f(level.base.width, level.base.height)); //TODO: fix
	rectangle.setOrigin(level.base.width/2, level.base.height/2);
	//shape.setSize(sf::Vector2f(platform->width, platform->height));
	rectangle.setPosition(level.base.xCoord, level.base.yCoord);
	rectangle.setFillColor(level.base.color);
	this -> drawRectangle(rectangle);

	sf::CircleShape circle(level.stolenObject.radius); //TODO: fix
	circle.setOrigin(level.stolenObject.radius, level.stolenObject.radius);
	circle.setPosition(level.stolenObject.xCoord, level.stolenObject.yCoord);
	circle.setFillColor(level.stolenObject.color);
	//TODO: Smooth it out when we pick a texture
  this -> drawCircle(circle);

	this -> App.display();
}
