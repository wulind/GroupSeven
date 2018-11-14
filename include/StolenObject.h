#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class StolenObject {

		public:
      StolenObject();
			StolenObject(float x, float y, int radius, b2World* World);

			float xCoord;
			float yCoord;

			int radius;//TODO: make this pertain to other shapes

			sf::Color color;

			//Box2D Stuff
			b2Body* Body;
			b2World* World;

			void UpdatePosition();
	};
}
#endif
