#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <cstdlib>
#include "tinyxml2.h"
#include "Level.h"
#include "LevelSelect.h"

namespace escape{
  class LevelFactory{

    private:
      void makePlatforms(Level &level, tinyxml2::XMLElement *levelRoot);

    public:
      LevelFactory();

      Level makeLevel(int levelToLoad);
      LevelSelect::SelectOrb makeOrbs(int level);
  };
}
#endif
