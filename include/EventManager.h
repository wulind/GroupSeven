#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>

namespace escape{
  class EventManger{
  private:
  	sf::RenderWindow *App;
  	Platform platform;

   public:
   	EventManager();
   	void clickButton(GameState *state);

    //Platform moving
   	void updateMouse();
   	bool checkMouseOverPlatform(Platform *platform);
   	void releaseAllPlatforms(Platform *platform);
	};

#endif