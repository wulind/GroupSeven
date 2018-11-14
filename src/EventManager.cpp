#include "EventManager.h"
#include <iostream>

using namespace escape;

/*
 * EventManager Constructor
 */
EventManager::EventManager(){}

/*
 * Method handles clicking a mouse button
 * Handles if the mouse is clicked on the finish button
 * @param &state: current game state
 * @param finishButton: button pressed to finish set up state
 */
void EventManager::clickButton(sf::RenderWindow &App, GameState &state, sf::Sprite finishButton){
	//Finish button is pressed
  //Gamestate is now play
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

		//Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
		relativeX = .8 * 800;
		relativeY = .85 * 600;

		size = finishButton.getLocalBounds();

		//If left mouse click, get mouse
		int clickX = sf::Mouse::getPosition(App).x;
		int clickY = sf::Mouse::getPosition(App).y;

		if(clickX >= relativeX && clickX <= relativeX + size.width && clickY >= relativeY && clickY <= relativeY + size.height){
			//If the mouse clicks on the finish button then set the state to play
			state.setState(GameState::State::PLAY);
		}
  }
}

/*
 * Method handles the mouse position updating the mouse position when dragging platforms
 * @param mousePosition: current position of the mouse
 * @param &platform: platform to be checked
 */
void EventManager::updateMouse(sf::Vector2i mousePosition, Platform &platform){
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
