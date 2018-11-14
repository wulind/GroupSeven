#include "EventManager.h"

using namespace escape;

/*
 * EventManager Constructor
 */
EventManager::EventManager(){}

/*
 * Method handles clicking a mouse button
 * Handles if the mouse is clicked on the finish button
 * @param *state: pointer to current game state
 * @param finishButton: button pressed to finish set up state
 */
void EventManager::clickButton(sf::RenderWindow &App, GameState *state, sf::Sprite finishButton){
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
			state -> setState(GameState::State::PLAY);
		}
  }
}

/*
 *  Method handles the mouse position updating the mouse position when dragging platforms.
 * @param &App: current render window
 * @param &platform: platform to be checked
 */
void EventManager::updateMouse(sf::RenderWindow *App, Platform &platform){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*App);
	platform.updateDragPosition(mousePosition.x, mousePosition.y);
}

/*
 * Boolean method that checks if the mouse is over a platform object in the game screen
 * @param &App: current render window
 * @param &platform: platform to be checked
 */
bool EventManager::checkMouseOverPlatform(sf::RenderWindow *App, Platform &platform){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*App);

	float mouseX = mousePosition.x;
	float mouseY = mousePosition.y;

	float platformXStart = platform.xCoord;
	float platformYStart = platform.yCoord;

	float platformXEnd = platformXStart + platform.width;
	float platformYEnd = platformYStart + platform.height;

	bool hitsX = (platformXStart <= mouseX && mouseX <= platformXEnd);
	bool hitsY = (platformYStart <= mouseY && mouseY <= platformYEnd);

	if (hitsX && hitsY) {
		platform.isBeingDragged = true;

		platform.mouseDragOffsetX = mouseX - platformXStart;
		platform.mouseDragOffsetY = mouseY - platformYStart;

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
