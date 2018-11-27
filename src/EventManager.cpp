#include "EventManager.h"
#include <math.h>
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
void EventManager::updateMouse(sf::Vector2i mousePosition, std::vector<Platform> &platforms){
	int i = 0;
	for (i; i < platforms.size(); ++i){
		platforms[i].updateDragPosition(mousePosition.x, mousePosition.y);
	}
}

/*
 * Boolean method that checks if the mouse is over a platform object in the game screen
 * @param mousePosition: current position of the mouse
 * @param &platforms: platforms to be checked
 */
void EventManager::checkMouseOverPlatform(sf::Vector2i mousePosition, std::vector<Platform> &platforms){
	int i = 0;
	for (i; i < platforms.size(); ++i){
		double s = sin(-1 * platforms[i].rotation * b2_pi / 180);
		double c = cos(-1 * platforms[i].rotation * b2_pi / 180);

		double localXMouse = -1 * ((c * (mousePosition.x - platforms[i].origin.x)) - (s * (mousePosition.y - platforms[i].origin.y) + platforms[i].origin.x));
		double localYMouse = (s * (mousePosition.x - platforms[i].origin.x)) + (c * (mousePosition.y - platforms[i].origin.y) + platforms[i].origin.y);

		if(platforms[i].bounds.contains(localXMouse, localYMouse)){
			platforms[i].isBeingDragged = true;

			platforms[i].mouseDragOffsetX = mousePosition.x - platforms[i].xCoord;
			platforms[i].mouseDragOffsetY = mousePosition.y - platforms[i].yCoord;
	  }
	}
}

/*
 * Releases all platforms. Sets the platform to not being dragged.
 * @param &platform: platform that needs to be released.
 */
void EventManager::releaseAllPlatforms(std::vector<Platform> &platforms){
	int i = 0;
	for (i; i < platforms.size(); ++i){
		platforms[i].isBeingDragged = false;
	}
}
