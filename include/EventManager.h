#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H


#include "../include/GameState.h"
#include "../include/Platform.h"

namespace escape{
  class EventManager{
  public:
      //Constructor
      EventManager();
      //Handles clicking the mouse on the finish button
      void clickButton(GameState *state, sf::Sprite finishButton);
      //These methods handle platform moving
      void updateMouse();
      bool checkMouseOverPlatform(Platform *platform);
      void releaseAllPlatforms(Platform *platform);
	
  private:
      //The RenderWindow
      sf::RenderWindow *App;
      //The current game state
      GameState state;
      //The platform object
      Platform platform;
      //The relative positions are used with window resizing.
      int relativeX;
      int relativeY;
      //The size of the sprite
      sf::FloatRect size;
    };
    }

#endif
