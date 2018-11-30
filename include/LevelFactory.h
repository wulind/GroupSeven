#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <cstdlib>
#include "tinyxml2.h"
#include "Level.h"
#include <string>
#include <cstdio>

namespace escape{
  class LevelFactory{

    private:
      void readXML(int levelToLoad);
      void makePlatforms(tinyxml2::XMLElement *root);

    public:
      LevelFactory();
      LevelFactory(Level &_level);

      Level* makeLevel(int levelToLoad);

      Level level;
  };
}
#endif
