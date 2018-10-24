#include "../include/GameView.h"

using namespace view;
using namespace sf;

GameView::GameView(RenderWindow* newWindow) :
	window(newWindow) {
}

void GameView::setPlatform(Platform* newDraggablePlatform) {
	this->draggablePlatform = newDraggablePlatform;
}

void GameView::drawPlatform() {

	RectangleShape platformRectangle;

	platformRectangle.setSize(Vector2f(draggablePlatform->width, draggablePlatform->height));
	platformRectangle.setPosition(draggablePlatform->xCoord, draggablePlatform->yCoord);
	platformRectangle.setFillColor(draggablePlatform->color);

	window->draw(platformRectangle);
}

void GameView::update() {
	window->clear(sf::Color::Black);

	drawPlatform();

	window->display();
}
