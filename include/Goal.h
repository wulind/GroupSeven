#ifndef GOAL_H
#define GOAL_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class Goal {

		public:
      			Goal();
			//x,y coordinates for location on screen (Bottom Left Coordinate)
			Goal(float x, float y, b2World* World);

			void UpdatePosition();

			float xCoord;
			float yCoord;


			sf::Color color;

			//Box2D Stuff
			b2Body* Body;
			b2World* World;
	};
}
#endif
