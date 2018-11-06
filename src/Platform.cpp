#include "../include/Platform.h"

using namespace escape;

Platform::Platform(){}

Platform::Platform(float x, float y, int height, int width){
	//TODO: Update this to be in the menu
	this -> xCoord = x;
	this -> yCoord = y;
    this -> mouseDragOffsetX = 0;
	this -> mouseDragOffsetY = 0;

	this -> height = height;
	this -> width = width;

	this -> isBeingDragged = false;

	this -> color = sf::Color::White;

}

void Platform::updateDragPosition(float mouseX, float mouseY) {
	if (!this -> isBeingDragged)
		return;

	this -> xCoord = mouseX - mouseDragOffsetX;
	this -> yCoord = mouseY - mouseDragOffsetY;
}
