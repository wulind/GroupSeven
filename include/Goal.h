#ifndef GOAL_H
#define GOAL_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <StolenObject.h>


namespace escape {
	class Goal {

		private:
			float xCoord;
			float yCoord;


		public:
      			Goal();
			//x,y coordinates for location on screen (Bottom Left Coordinate)
			Goal(float x, float y, b2World* World);

			void UpdatePosition();

			int checkGoalReached(StolenObject* obj);

			sf::Color color;

			//Box2D Stuff
			//Probably dont actually need. Might have a platform
			b2Body* Body;
			b2World* World;

			float width;
			float height;
	};
}
#endif
