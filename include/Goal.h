#ifndef GOAL_H
#define GOAL_H

#include <SFML/Graphics.hpp>
#include "StolenObject.h"

namespace escape{
  class Goal{//TODO: make this class a struct instead?

    private:

    public:
      Goal();

      int width;
      int height;

      int xCoord;
      int yCoord;

      sf::FloatRect bounds;

      bool detectWin(StolenObject &stolenObject);

  };
}
#endif
