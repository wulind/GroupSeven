#ifndef LEVEL_H
#define LEVEL_H

#include <Box2D/Box2D.h>
#include <vector>
#include "Platform.h"
#include "StolenObject.h"
#include "FinishButton.h"
#include "PlatformMenu.h"

namespace escape{
  class Level{//TODO: make this class a struct instead?

    private:
    public:
      Level();

      int backgroundStartX;
      int backgroundStartY;


    public:
      Level();
      int startX;
      int startY;
      int objectStartX;
      int objectStartY;
      
      std::vector<Platform> platforms;//TODO: store multiple platforms
      Platform base;
      StolenObject stolenObject;

      FinishButton finishButton;
      PlatformMenu platformMenu;
      float gravity;

      void setWorld(b2World* World);
      void setStolenObjectFile(const char *_objStartX, const char *_objStartY);
      void makePlatform(int rotation, int xPos, int yPos, int width, int height, bool draggable);
      void setBackgroundFile(const char *_startX, const char *_startY);
      void setGravity(float g);
      void setStolenObject(int x, int y, int radius);
  };
}
#endif
