#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <cstdlib>
#include "tinyxml2.h"
#include "Level.h"
#include "LevelSelect.h"

namespace escape{
  class LevelFactory{

    private:
      void makePlatforms(tinyxml2::XMLElement *levelRoot);

    public:
      LevelFactory();

      Level* makeLevel(int levelToLoad, b2World* World);
      LevelSelect::SelectOrb makeOrbs(int level);

      Level level;
  };
}
#endif
