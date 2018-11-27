#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){

}

/*
* @param *App: pointer to game window
* @param &font: reference to Cows & Aliens font used throughout the game
*/
GameView::GameView(sf::Font *_font){
	this -> App.create(sf::VideoMode(800, 600, 32), "The Great Escape");
	this -> font = _font;

	// if (!backgroundTexture.loadFromFile("../data/BackgroundsSpriteSheet.png", sf::IntRect(800, 600, 800, 600)))
	// 	{	
	// 		//Error
	// 	}
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




void GameView::setGraphics(Level &level){
		//Uses xml stored values of spirte sheet startX and startX for level specific backgrounds
		if (!backgroundTexture.loadFromFile("../data/BackgroundsSpriteSheet.png", sf::IntRect(level.startX, level.startY, 800, 600)))
		{	
			//Error
		}
		sprite.setTexture(backgroundTexture);

}

/*
* Creates all of the SFML-related objects that need to be drawn
* @param platform: platform needed for the level
* @param stolenObject: objects that need to be stolen
* @param menu: menu that contains platforms
*/
void GameView::update(Level &level){
	//Clear the screen so objects don't redraw as they  move
	// this -> App.clear(sf::Color::Black);
	this -> App.draw(sprite);

	int i = 0;
	for (i; i < level.platforms.size(); ++i){

		sf::RectangleShape platform(sf::Vector2f(level.platforms[i].width, level.platforms[i].height)); //TODO: fix
		platform.setOrigin(level.platforms[i].width/2, level.platforms[i].height/2);
		platform.setPosition(level.platforms[i].xCoord, level.platforms[i].yCoord);
		platform.setFillColor(level.platforms[i].color);
		this -> drawRectangle(platform);
	}

	sf::RectangleShape base(sf::Vector2f(level.base.width, level.base.height)); //TODO: fix
	base.setOrigin(level.base.width/2, level.base.height/2);
	base.setPosition(level.base.xCoord, level.base.yCoord);
	base.setFillColor(level.base.color);
	this -> drawRectangle(base);

	sf::CircleShape circle(level.stolenObject.radius); //TODO: fix
	circle.setOrigin(level.stolenObject.radius, level.stolenObject.radius);
	circle.setPosition(level.stolenObject.xCoord, level.stolenObject.yCoord);
	circle.setTexture(&level.stolenObject.objTexture);
	// circle.setFillColor(level.stolenObject.color);
	//TODO: Smooth it out when we pick a texture
  this -> drawCircle(circle);

	if(level.finishButton.show){
		this -> drawText(level.finishButton.button);
	}
	this -> App.display();
}
