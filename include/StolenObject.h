#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class StolenObject {

		private:
			//Box2D Stuff
			b2Body* Body;
			b2World* World;



		public:
      StolenObject();
			StolenObject(float x, float y, int radius);

			float xCoord;
			float yCoord;

			int radius;//TODO: make this pertain to other shapes

			float rotation;

			float health;

			sf::Color color;
			sf::Texture objTexture;

			void setWorld(b2World* World);
			void updatePosition();
			int checkAlive();
	};
}
#endif
