#include "../include/Platform.h"

using namespace escape;

Platform::Platform(){}

/*
* Constructor
* @param x: x coordinate of platform
* @param y: y coordinate of platform
* @param height: height of platform
* @param width: width of platform
*/
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


/*
* Updates position of platform when it's being dragged across the screen
* @param mouseX: x coordinate of mouse Position
* @param mouseY: y coordinate of mouse Position
*/
void Platform::updateDragPosition(float mouseX, float mouseY) {
	if (!this -> isBeingDragged)
		return;

	this -> xCoord = mouseX - mouseDragOffsetX;
	this -> yCoord = mouseY - mouseDragOffsetY;
}
