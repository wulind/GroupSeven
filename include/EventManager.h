#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Platform.h"

namespace escape{
  class EventManager{
	  public:
	      EventManager();

	      void clickButton(sf::RenderWindow &App, GameState *state, sf::Sprite finishButton);

	      //platform moving
	      void updateMouse(sf::RenderWindow *App, Platform &platform);
	      bool checkMouseOverPlatform(sf::RenderWindow *App, Platform &platform);
	      void releaseAllPlatforms(Platform &platform);

	  private:
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
