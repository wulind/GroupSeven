#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <cstdlib>
#include "tinyxml2.h"
#include "Level.h"

namespace escape{
  class LevelFactory{

    public:
      LevelFactory();
      LevelFactory(Level &_level);

      void readXML(int levelToLoad);

      Level level;
  };
}
#endif
