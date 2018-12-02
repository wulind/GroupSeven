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
      
      int objectStartX;
      int objectStartY;

      int objectStartX;
      int objectStartY;
      
      std::vector<Platform> platforms;//TODO: store multiple platforms
      Platform base;
      StolenObject stolenObject;
      FinishButton finishButton;
<<<<<<< HEAD

      float gravity;
      Goal goal;
=======
      PlatformMenu platformMenu;
>>>>>>> parent of 5446823... Merge pull request #22 from wulind/LindaWu/goal

      void setWorld(b2World* World);
      void setStolenObjectFile(const char *_objStartX, const char *_objStartY);
      void makePlatform(int rotation, int xPos, int yPos, int width, int height, bool draggable);
      void setBackgroundFile(const char *_startX, const char *_startY);
<<<<<<< HEAD
      void setGravity(float g);
      void setStolenObject(int x, int y, int radius);

      void clearLevel();

=======
      
>>>>>>> parent of 5446823... Merge pull request #22 from wulind/LindaWu/goal

  };
}
#endif
