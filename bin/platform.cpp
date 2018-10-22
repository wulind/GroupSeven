#include "Platform.h"

using namespace gameObject;

Platform::Platform() :
	xCoord(50),
	yCoord(50),
	height(20),
	width(100),
	isBeingDragged(false),
	mouseDragOffsetX(0),
	mouseDragOffsetY(0),
	color(sf::Color::White) {

}

void Platform::updateDragPosition(float mouseX, float mouseY) {
	if (!isBeingDragged)
		return;

	this->xCoord = mouseX - mouseDragOffsetX;
	this->yCoord = mouseY - mouseDragOffsetY;
}