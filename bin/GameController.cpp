#include "GameController.h"

using namespace std;

using namespace controller;
using namespace view;
using namespace sf;

GameController::GameController(sf::RenderWindow* newWindow) :
	window(newWindow),
	platform(gameObject::Platform()),
	mainView(GameView(newWindow)) {

}

void GameController::updateGame() {

}

void GameController::updateView() {
	mainView.update();
}