#ifndef GOAL_H
#define GOAL_H

#include <SFML/Graphics.hpp>
#include "StolenObject.h"

namespace escape{
  class Goal{
    private:
      b2Body* Body;

    public:
      Goal();
      Goal(int xCoord, int yCoord);

      int width;
      int height;

      int xCoord;
      int yCoord;

      sf::FloatRect bounds;

      void setWorld(b2World* World);

      int detectWin(StolenObject &stolenObject);
  };
}
#endif
