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
		//Get mouse coordinates transformed around origin of platform -rotation in radians
		float s = sin(-1 * platforms[i].rotation * M_PI/180);
		float c = cos(-1 * platforms[i].rotation * M_PI/180);

		int localXMouse = -1 * ((c * (mousePosition.x - platforms[i].origin.x)) - (s * (mousePosition.y - platforms[i].origin.y) + platforms[i].origin.x));
		int localYMouse = (s * (mousePosition.x - platforms[i].origin.x)) + (c * (mousePosition.y - platforms[i].origin.y) + platforms[i].origin.y);

		//Checks if in transformed box
		if(localXMouse < (platforms[i].xCoord + (platforms[i].width/2)) && localXMouse > (platforms[i].xCoord - (platforms[i].width/2)) && localYMouse > (platforms[i].yCoord - (platforms[i].height/2)) && localYMouse < (platforms[i].yCoord + (platforms[i].height/2))){
			platforms[i].isBeingDragged = true;
			platforms[i].show = true;

			platforms[i].mouseDragOffsetX = mousePosition.x - platforms[i].xCoord;
			platforms[i].mouseDragOffsetY = mousePosition.y - platforms[i].yCoord;
			break;
		}
	}
}

/*
 * Releases all platforms. Sets the platform to not being dragged.
 * @param &platforms: platforms that need to be released.
 */
void EventManager::releaseAllPlatforms(std::vector<Platform> &platforms){
	int i = 0;
	for (i; i < platforms.size(); ++i){
		platforms[i].isBeingDragged = false;
	}
}
