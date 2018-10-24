#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){}

GameView::GameView(sf::RenderWindow *App){
	this -> App = App;
}

void GameView::drawPlatform(sf::RectangleShape platform) {//TODO:Replace this eventually with sprite
	this -> App -> draw(platform);
}

void GameView::drawStolenObject(sf::CircleShape circle) {//TODO:Replace this eventually with sprite
	this -> App -> draw(circle);
}

void GameView::drawText(sf::Text text) {
	this -> App -> draw(text);
}

void GameView::drawSprite(sf::Sprite sprite) {
	this -> App -> draw(sprite);
}

void GameView::update(Platform *platform, StolenObject *stolenObject, PlatformMenu *menu) { //TODO: Fix
	this -> App -> clear(sf::Color::Black);

	if (platform){
		sf::RectangleShape rectangle(sf::Vector2f(platform->width, platform->height)); //TODO: fix
		//shape.setSize(sf::Vector2f(platform->width, platform->height));
		rectangle.setPosition(platform->xCoord, platform->yCoord);
		rectangle.setFillColor(platform->color);

		this -> drawPlatform(rectangle);
	}

	if (stolenObject){
		sf::CircleShape circle(stolenObject -> radius); //TODO: fix
		circle.setPosition(stolenObject->xCoord, stolenObject->yCoord);
		circle.setFillColor(stolenObject->color);
		//TODO: Smooth it out when we pick a texture
		this -> drawStolenObject(circle);
	}
	if (menu){
		//TODO: finish
	}




	this -> App -> display();
}
