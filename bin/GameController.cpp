#include "GameController.h"

using namespace std;

using namespace controller;
using namespace view;
using namespace sf;

GameController::GameController(sf::RenderWindow* newWindow) :
	window(newWindow),
	mainView(GameView(newWindow)) {

	this->platform = gameObject::Platform();
	this->mainView.setPlatform(&this->platform);

}

bool GameController::checkMouseOverPlatform() {
	Vector2i mousePosition = Mouse::getPosition(*this->window);

	float mouseX = mousePosition.x;
	float mouseY = mousePosition.y;

	float platformXStart = this->platform.xCoord;
	float platformYStart = this->platform.yCoord;

	float platformXEnd = platformXStart + this->platform.width;
	float platformYEnd = platformYStart + this->platform.height;

	bool hitsX = (platformXStart <= mouseX && mouseX <= platformXEnd);
	bool hitsY = (platformYStart <= mouseY && mouseY <= platformYEnd);

	if (hitsX && hitsY) {
		this->platform.isBeingDragged = true;

		this->platform.mouseDragOffsetX = mouseX - platformXStart;
		this->platform.mouseDragOffsetY = mouseY - platformYStart;

		return true;
	}
	return false;
}

void GameController::releaseAllPlatforms() {

	this->platform.isBeingDragged = false;
}

void GameController::updateGame() {
	Vector2i mousePosition = Mouse::getPosition(*this->window);

	this->platform.updateDragPosition(mousePosition.x, mousePosition.y);
}

void GameController::updateView() {
	mainView.update();
}