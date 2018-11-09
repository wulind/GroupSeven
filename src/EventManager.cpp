#include "EventManager.h"


using namespace escape;

/*
 * EventManager Constructor
 * @param *App: current window
 * @param *platform: platform
 * @param *state: current game state
 */
EventManager::EventManager(sf::RenderWindow *App, Platform *platform, GameState *state){
	this -> App = App;
	this -> platform = platform;
    	this -> state = state;
}

/*
 * Method handles clicking a mouse button
 * Handles if the mouse is clicked on the finish button
 * @param *state: pointer to current game state
 * @param finishButton: button pressed to finish set up state
 */
void EventManager::clickButton(GameState *state, sf::Sprite finishButton){
	//Finish button is pressed
    	//Gamestate is now play
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        
		//Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
		relativeX = .8 * this -> App->getSize().x;
		relativeY = .85 * this -> App->getSize().y;

		size = finishButton.getLocalBounds();

		//If left mouse click, get mouse
		int clickX = sf::Mouse::getPosition(*this -> App).x;
		int clickY = sf::Mouse::getPosition(*this -> App).y;

		if(clickX >= relativeX && clickX <= relativeX+size.width && clickY >= relativeY && clickY <= relativeY+size.height){
			//If the mouse clicks on the finish button then set the state to play
			state->setState(state->PLAY);
		}
      }
}

/*
 *  Method handles the mouse position updating the mouse position when dragging platforms. 
 */
void EventManager::updateMouse(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);
	this -> platform -> updateDragPosition(mousePosition.x, mousePosition.y);
}

/*
 * Boolean method that checks if the mouse is over a platform object in the game screen 
 * @param *platform: pointer to platform to be checked
 */
bool EventManager::checkMouseOverPlatform(Platform *platform){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	float mouseX = mousePosition.x;
	float mouseY = mousePosition.y;

	float platformXStart = this -> platform->xCoord;
	float platformYStart = this -> platform->yCoord;

	float platformXEnd = platformXStart + this -> platform -> width;
	float platformYEnd = platformYStart + this -> platform -> height;

	bool hitsX = (platformXStart <= mouseX && mouseX <= platformXEnd);
	bool hitsY = (platformYStart <= mouseY && mouseY <= platformYEnd);

	if (hitsX && hitsY) {
		this -> platform -> isBeingDragged = true;

		this -> platform -> mouseDragOffsetX = mouseX - platformXStart;
		this -> platform -> mouseDragOffsetY = mouseY - platformYStart;

		return true;
	}
	return false;
}

/*
 * Releases all platforms. Sets the platform to not being dragged.
 * @param *platform: pointer to platform that needs to be released.
 */
void EventManager::releaseAllPlatforms(Platform *platform){
	this -> platform -> isBeingDragged = false;
}
