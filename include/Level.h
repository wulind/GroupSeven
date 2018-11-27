#ifndef LEVEL_H
#define LEVEL_H

#include <Box2D/Box2D.h>
#include <vector>
#include "Platform.h"
#include "StolenObject.h"
#include "FinishButton.h"

namespace escape{
  class Level{//TODO: make this class a struct instead?
  public:

    // private:
      const char *backgroundFile = "";
      const char *stolenObjectFile = "";
      int startX;
      int startY;

    // public:
      Level();

      std::vector<Platform> platforms;//TODO: store multiple platforms
      Platform base;
      StolenObject stolenObject;
      FinishButton finishButton;

      void setWorld(b2World* World);
      void setStolenObjectFile(const char *_stolenObjectFile);
      void setBackgroundFile(const char *_backgroundFile, const char *_startX, const char *_startY);
      void makePlatform(int count);

  };
}
#endif
