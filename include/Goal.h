#ifndef GOAL_H
#define GOAL_H

#include <SFML/Graphics.hpp>
#include "StolenObject.h"

namespace escape{
  class Goal{//TODO: make this class a struct instead?

    private:
      b2Body* Body;
			b2World* World;

    public:
      Goal();

      int width;
      int height;

      int xCoord;
      int yCoord;

      sf::FloatRect bounds;

      void setWorld(b2World* World);

      bool detectWin(StolenObject &stolenObject);

  };
}
#endif
