#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

namespace escape{
  class EventManger{
   public:
   	EventManager();
   	void clickButton(GameState *state);

   	void updateMouse();
   	void checkMouseOverPlatform(Platform *platform);
   	void releaseAllPlatforms(Platform *platform);


	};

#endif