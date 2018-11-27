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
		// float localXMouse = mousePosition.x*cos((platforms[i].rotation)*b2_pi/180) - (-1 * mousePosition.y*sin((platforms[i].rotation)*b2_pi/180));
		// float localYMouse = (-1 * mousePosition.x*sin((platforms[i].rotation)*b2_pi/180)) + mousePosition.y*cos((platforms[i].rotation)*b2_pi/180);
		float localXMouse = -1 * ((cos(-1 * platforms[i].rotation) * (mousePosition.x - platforms[i].origin.x)) - (sin (-1 * platforms[i].rotation) * (mousePosition.y - platforms[i].origin.y) + platforms[i].origin.x));
		float localYMouse = (sin(-1 * platforms[i].rotation) * (mousePosition.x - platforms[i].origin.x)) + (cos (-1 * platforms[i].rotation) * (mousePosition.y - platforms[i].origin.y) + platforms[i].origin.y);

		//float localXMouse = mousePosition.x;
		//float localYMouse = mousePosition.y;

		std::cout << "Mouse position: " << localXMouse << ", " << localYMouse << std::endl;
		std::cout << "Mouse position: " << mousePosition.x << ", " << mousePosition.y << std::endl;
		std::cout << "Originx : " << platforms[i].origin.x << " ";
		std::cout << "Originy : " << platforms[i].origin.y << std::endl;

		// std::cout << "Platform: " << platforms[i].top << std::endl;

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
