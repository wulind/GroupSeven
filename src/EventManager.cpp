#include "EventManager.h"
#include <iostream>

using namespace escape;

/*
 * EventManager Constructor
 */
EventManager::EventManager(){}

/*
 * Method handles the mouse position updating the mouse position when dragging platforms
 * @param mousePosition: current position of the mouse
 * @param &platform: platform to be checked
 */
void EventManager::updateMouse(sf::Vector2i mousePosition, Platform &platform){
	std::cout << "x: " << mousePosition.x << "\ty: " << mousePosition.y << std::endl;
	platform.updateDragPosition(mousePosition.x, mousePosition.y);
}

/*
 * Boolean method that checks if the mouse is over a platform object in the game screen
 * @param mousePosition: current position of the mouse
 * @param &platform: platform to be checked
 */
bool EventManager::checkMouseOverPlatform(sf::Vector2i mousePosition, Platform &platform){
	float platformXStart = platform.xCoord;
	float platformYStart = platform.yCoord;

	float platformXEnd = platformXStart + platform.width;
	float platformYEnd = platformYStart + platform.height;

	bool hitsX = (platformXStart <= mousePosition.x && mousePosition.x <= platformXEnd);
	bool hitsY = (platformYStart <= mousePosition.y && mousePosition.y <= platformYEnd);

	if (hitsX && hitsY) {
		platform.isBeingDragged = true;

		platform.mouseDragOffsetX = mousePosition.x - platformXStart;
		platform.mouseDragOffsetY = mousePosition.y - platformYStart;

		return true;
	}
	return false;
}

/*
 * Releases all platforms. Sets the platform to not being dragged.
 * @param &platform: platform that needs to be released.
 */
void EventManager::releaseAllPlatforms(Platform &platform){
	platform.isBeingDragged = false;
}
