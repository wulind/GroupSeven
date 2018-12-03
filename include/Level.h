#ifndef LEVEL_H
#define LEVEL_H

#include <Box2D/Box2D.h>
#include <vector>
#include "Platform.h"
#include "StolenObject.h"
#include "FinishButton.h"
#include "Goal.h"
#include "PlatformMenu.h"
#include "StolenObjectContactListener.h"

namespace escape{
  class Level{//TODO: make this class a struct instead?

    private:
    public:
      Level();

      int backgroundStartX;
      int backgroundStartY;

      int objectStartX;
      int objectStartY;

      std::vector<Platform> platforms;
      std::vector<Platform> obstacles;

      PlatformMenu platformMenu;
      StolenObject stolenObject;
      FinishButton finishButton;

      StolenObjectContactListener myContactListenerInstance;

      float gravity;
      Goal goal;

      void setWorld(b2World* World);
      void setStolenObjectFile(const char *_objStartX, const char *_objStartY);
      void makePlatform(int rotation, int xPos, int yPos, int width, int height, bool draggable);
      void setBackgroundFile(const char *_startX, const char *_startY);
      void setGravity(float g);
      void setStolenObject(int x, int y, int radius);
      void setGoal(int xCoord, int yCoord);

      void clearLevel();


  };
}
#endif
