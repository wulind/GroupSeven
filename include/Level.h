#ifndef LEVEL_H
#define LEVEL_H

#include <Box2D/Box2D.h>
#include <vector>
#include "Platform.h"
#include "StolenObject.h"
#include "FinishButton.h"
#include "Goal.h"
#include "PlatformMenu.h"
#include "ContactListener.h"

namespace escape{
  class Level{

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
      Goal goal;

      ContactListener contactListener;

      float gravity;

      void setWorld(b2World* World);
      void setStolenObjectFile(const char *_objStartX, const char *_objStartY);
      void makePlatform(int rotation, int xPos, int yPos, int width, int height, int* color, bool draggable);
      void setBackgroundFile(const char *_startX, const char *_startY);
      void setGravity(float g);
      void setStolenObject(int x, int y, int radius, float restitution);
      void setGoal(int xCoord, int yCoord);

      void clearLevel();
  };
}
#endif
