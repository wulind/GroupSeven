#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){
}

GameView::GameView(sf::RenderWindow *App){
	this -> App = App;
}

void GameView::drawPlatform(sf::RectangleShape platform) {
	this -> App -> draw(platform);
}

void GameView::update(Platform* platform) {
	this -> App -> clear(sf::Color::Black);

  sf::RectangleShape shape; //TODO: fix
	shape.setSize(sf::Vector2f(platform->width, platform->height));
	shape.setPosition(platform->xCoord, platform->yCoord);
	shape.setFillColor(platform->color);

	this -> drawPlatform(shape);

	this -> App -> display();
}
