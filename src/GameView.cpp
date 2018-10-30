#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){}

/*
* @param *App: pointer to game window
*/
GameView::GameView(sf::RenderWindow *App){
	this -> App = App;
}

/*
* Draws any platforms needed for the level
* @param platform: rectangle shape to draw
*/
void GameView::drawPlatform(sf::RectangleShape platform) {//TODO:Replace this eventually with sprite & take in a bunch of platforms
	this -> App -> draw(platform);
}

/*
* Draws any circles needed for the level
* @param circle: circle shape to draw
*/
void GameView::drawStolenObject(sf::CircleShape circle) {//TODO:Replace this eventually with sprite
	this -> App -> draw(circle);
}

/*
* Draws any text needed for the level
* @param text: text to draw
*/
void GameView::drawText(sf::Text text) {
	this -> App -> draw(text);
}

/*
* Draws any sprite needed for the level
* @param sprite: sprite to draw
*/
void GameView::drawSprite(sf::Sprite sprite) {
	this -> App -> draw(sprite);
}

/*
* Creates all of the SFML-related objects that need to be drawn
* @param platform: platform needed for the level
* @param stolenObject: objects that need to be stolen
* @param menu: menu that contains platforms
*/
void GameView::update(std::vector<Platform> *platforms, StolenObject *stolenObject, PlatformMenu *menu) { //TODO: Fix
	this -> App -> clear(sf::Color(103, 164, 207));

	if (menu){
		menu -> update();
		this -> drawSprite(menu -> menu);
		this -> drawText(menu -> title);
	}

	if (platforms){


		for (Platform curPlatform: *platforms) {

			sf::RectangleShape rectangle(sf::Vector2f(curPlatform.width, curPlatform.height)); //TODO: fix
			//shape.setSize(sf::Vector2f(platform->width, platform->height));
			rectangle.setPosition(curPlatform.xCoord, curPlatform.yCoord);
			rectangle.setFillColor(curPlatform.color);

			this->drawPlatform(rectangle);
		}
			
	}

	if (stolenObject){
		sf::CircleShape circle(stolenObject -> radius); //TODO: fix
		circle.setPosition(stolenObject -> xCoord, stolenObject -> yCoord);
		circle.setFillColor(stolenObject -> color);
		//TODO: Smooth it out when we pick a texture
		this -> drawStolenObject(circle);
	}

	this -> App -> display();
}
