#include "EventManager.h"

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
		float platformXStart = platforms[i].xCoord - platforms[i].width/2;
		float platformYStart = platforms[i].yCoord - platforms[i].height/2;
		float platformXEnd = platforms[i].xCoord + platforms[i].width/2;
		float platformYEnd = platforms[i].yCoord + platforms[i].height/2;

		bool hitsX = (platformXStart <= mousePosition.x && mousePosition.x <= platformXEnd);
		bool hitsY = (platformYStart <= mousePosition.y && mousePosition.y <= platformYEnd);

		if (hitsX && hitsY) {
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
