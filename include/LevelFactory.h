#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <string>
#include <cstdlib>
#include <cstdio>
#include "tinyxml2.h"
#include "Level.h"
#include "Dialogue.h"
#include "LevelSelect.h"

namespace escape{
  class LevelFactory{

    private:
      void makePlatforms(Level &level, tinyxml2::XMLElement *levelRoot);

    public:
      LevelFactory();

      Level makeLevel(int levelToLoad);
      LevelSelect::SelectOrb makeOrbs(int level);
      Dialogue loadDialogue(int level);
  };
}
#endif
