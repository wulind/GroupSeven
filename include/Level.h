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
      const char *backgroundFile = "";
      const char *stolenObjectFile = "";

    public:
      Level();

      std::vector<Platform> platforms;//TODO: store multiple platforms
      Platform base;
      StolenObject stolenObject;
      FinishButton finishButton;
      PlatformMenu platformMenu;

      void setWorld(b2World* World);
      void setBackgroundFile(const char *_backgroundFile);
      void setStolenObjectFile(const char *_stolenObjectFile);
      void makePlatform(int rotation, int yPos);

  };
}
#endif
