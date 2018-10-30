#include "../include/Platform.h"

using namespace escape;

Platform::Platform(){}

Platform::Platform(float x, float y, int height, int width){
	printf("rectangle initialized");
	//TODO: Update this to be in the menu
	this -> xCoord = x;
	this -> yCoord = y;
    this -> mouseDragOffsetX = 0;
	this -> mouseDragOffsetY = 0;

	this -> height = height;
	this -> width = width;

	this -> isBeingDragged = false;

	this -> color = sf::Color::Black;

}

void Platform::updateDragPosition(float mouseX, float mouseY) {
	//printf("hello: %d\n", this->isBeingDragged);
	//if (!this -> isBeingDragged)
	//	return;

	printf("moving rect");
	this -> xCoord = mouseX - mouseDragOffsetX;
	this -> yCoord = mouseY - mouseDragOffsetY;
}

void Platform::startDrag() {
	printf("starting drag");
	this->isBeingDragged = true;
}

void Platform::endDrag() {
	this->isBeingDragged = false;
}