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
	text.setFont(*this -> font);
	text.setFillColor(sf::Color::White);
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
void GameView::update(Level &level){
	this -> App.clear(sf::Color::Black);

	//Platforms
	int i = 0;
	for (i; i < level.platforms.size(); ++i){
		sf::RectangleShape platform = this -> makeRectangle(level.platforms[i].width, level.platforms[i].height, level.platforms[i].xCoord, level.platforms[i].yCoord, level.platforms[i].color);

		level.platforms[i].bounds = platform.getGlobalBounds();
		level.platforms[i].origin = platform.getPosition();

		level.platforms[i].setRotation(45);
		platform.setRotation(level.platforms[i].rotation);

		this -> drawRectangle(platform);
	}

	//=Base
	sf::RectangleShape base = this -> makeRectangle(level.base.width, level.base.height, level.base.xCoord, level.base.yCoord, level.base.color);
	level.base.bounds = base.getGlobalBounds();
	level.base.origin = base.getPosition();
	this -> drawRectangle(base);

	//Goal
	sf::RectangleShape goal = this -> makeRectangle(level.goal.width, level.goal.height, level.goal.xCoord, level.goal.yCoord, sf::Color(111, 82, 194));
	level.goal.bounds = goal.getGlobalBounds();
	this -> drawRectangle (goal);

	//StolenObject
	//TODO: Smooth it out when we pick a texture
	sf::CircleShape circle = this -> makeStolenObject(level.stolenObject);
	this -> drawCircle(circle);

	if(level.finishButton.show){
		this -> drawText(level.finishButton.button);
	}
	this -> App.display();
}

sf::RectangleShape GameView::makeRectangle(int width, int height, int xCoord, int yCoord, sf::Color color){
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setOrigin(width/2, height/2);
	rectangle.setPosition(xCoord, yCoord);
	rectangle.setFillColor(color);

	return rectangle;
}

sf::CircleShape GameView::makeStolenObject(StolenObject &stolenObject){
	sf::CircleShape circle(stolenObject.radius); //TODO: fix
	circle.setOrigin(stolenObject.radius, stolenObject.radius);
	circle.setPosition(stolenObject.xCoord, stolenObject.yCoord);
	circle.setFillColor(stolenObject.color);

	stolenObject.bounds = circle.getGlobalBounds();

	return circle;
}
