#include "../include/EventManager.h"

EventManager::EventManager(){

}

void EventManager::clickButton(GameState *state){

//Finish button is pressed
    //Gamestate is now play
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //If left mouse click, get mouse
        int clickX = sf::Mouse::getPosition(*this -> App).x;
        int clickY = sf::Mouse::getPosition(*this -> App).y;

        if(clickX >= relativeX && clickX <= relativeX+size.width && clickY >= relativeY && clickY <= relativeY+size.height){
          //If the mouse clicks on the finish button then call clickButton()
          // clickButton(state);
          state->play = 1;
        }
      }
}