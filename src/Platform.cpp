#include "../include/Platform.h"

using namespace escape;

Platform::Platform(){
	this -> xCoord = 50;
	this -> yCoord = 50;
  this -> mouseDragOffsetX = 0;
	this -> mouseDragOffsetY = 0;

	this -> height = 20;
	this -> width = 100;

	this -> isBeingDragged = false;

	this -> color = sf::Color::White;

}

void Platform::updateDragPosition(float mouseX, float mouseY) {
	if (!this -> isBeingDragged)
		return;

	this -> xCoord = mouseX - mouseDragOffsetX;
	this -> yCoord = mouseY - mouseDragOffsetY;
}
