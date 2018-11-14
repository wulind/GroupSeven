#ifndef LEVEL_H
#define LEVEL_H

#include <Box2D/Box2D.h>
#include "Platform.h"
#include "StolenObject.h"

namespace escape{
  class Level{//TODO: make this class a struct instead?

    private:
      const char *backgroundFile = "";
      const char *stolenObjectFile = "";
    
    public:
      Level();
      Level(b2World* World);

      Platform platform;//TODO: store multiple platforms
      Platform base;
      StolenObject stolenObject;

      b2World* World;
      void setBackgroundFile(const char *_backgroundFile);
      void setStolenObjectFile(const char *_stolenObjectFile);
      void makePlatform(int platform);




  };
}
#endif
