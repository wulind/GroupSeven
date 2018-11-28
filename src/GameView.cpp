#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){

}

/*
* @param *App: pointer to game window
* @param &font: reference to Cows & Aliens font used throughout the game
*/
GameView::GameView(sf::Font *_font){
	this -> App.create(sf::VideoMode(800, 600, 32), "The Great Escape", sf::Style::Titlebar|sf::Style::Close);
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
* @param level: Level object representing current level
*/
void GameView::update(Level &level){
	this -> App.clear(sf::Color::Blue);

	if(level.finishButton.show){//if GameState setup
		sf::RectangleShape menu(sf::Vector2f(180, screenY));
		menu.setPosition(sf::Vector2f(620, 0)); // absolute position do not change
		menu.setFillColor(sf::Color(0, 0, 0, 100));
		this -> drawRectangle(menu);

		this -> drawText(level.finishButton.button);
		this -> drawText(level.platformMenu.title);
	}

	int i = 0;
	for (i; i < level.platforms.size(); ++i){

		sf::RectangleShape platform(sf::Vector2f(level.platforms[i].width, level.platforms[i].height));
		platform.setOrigin(level.platforms[i].width/2, level.platforms[i].height/2);
		platform.setPosition(level.platforms[i].xCoord, level.platforms[i].yCoord);
		platform.setFillColor(level.platforms[i].color);

		level.platforms[i].bounds = platform.getGlobalBounds();
		level.platforms[i].origin = platform.getPosition();

		platform.setRotation(level.platforms[i].rotation);
		this -> drawRectangle(platform);
	}

	sf::RectangleShape base(sf::Vector2f(level.base.width, level.base.height));
	base.setOrigin(level.base.width/2, level.base.height/2);
	base.setPosition(level.base.xCoord, level.base.yCoord);
	base.setFillColor(level.base.color);

	sf::CircleShape circle(level.stolenObject.radius);
	circle.setOrigin(level.stolenObject.radius, level.stolenObject.radius);
	circle.setPosition(level.stolenObject.xCoord, level.stolenObject.yCoord);
	circle.setTexture(&level.stolenObject.objTexture);
	// circle.setFillColor(level.stolenObject.color);
	//TODO: Smooth it out when we pick a texture

	this -> drawRectangle(base);
	this -> drawCircle(circle);

	this -> App.display();
}
