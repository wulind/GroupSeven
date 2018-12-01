#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class StolenObject {

		private:
			//Box2D Stuff
			b2World* World;

		public:
      StolenObject();
			StolenObject(float x, float y, int radius);

			b2Body* Body;

			float xCoord;
			float yCoord;

			int radius;

			float rotation;

			sf::FloatRect bounds;

			sf::Color color;
			sf::Texture objTexture;

			void setWorld(b2World* World);
			void updatePosition();
	};
}
#endif
