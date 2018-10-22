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

void GameController::updateGame() {

}

void GameController::updateView() {
	mainView.update();
}