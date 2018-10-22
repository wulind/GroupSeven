#include "GameView.h"

using namespace view;
using namespace sf;

GameView::GameView(RenderWindow* newWindow) :
	window(newWindow) {
}

void GameView::setPlatform(Platform* newDraggablePlatform) {
	this->draggablePlatform = newDraggablePlatform;
}