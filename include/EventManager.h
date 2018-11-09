#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H


#include "GameState.h"
#include "Platform.h"

namespace escape{
  class EventManager{
	  public:
	      EventManager(sf::RenderWindow *App, Platform *platform);
	      
	      void clickButton(GameState *state, sf::Sprite finishButton);
	      
	      //platform moving
	      void updateMouse();
	      bool checkMouseOverPlatform(Platform *platform);
	      void releaseAllPlatforms(Platform *platform);

	  private:
	      //Winodw
	      sf::RenderWindow *App;

	      //The platform object
	      Platform *platform;

	      //The relative positions are used with window resizing.
	      int relativeX;
	      int relativeY;

	      //The size of the sprite
	      sf::FloatRect size;
    };
}

#endif
