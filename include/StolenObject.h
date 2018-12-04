#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <math.h>

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

			int spriteSheetStartX;
      int spriteSheetStartY;

			int radius;

			int health;
			double timeSinceLastDamage;
			sf::Clock timer;
			bool playSound;

			float rotation;

			sf::FloatRect bounds;

			sf::Color color;
			sf::Texture objTexture;

			void setWorld(b2World* World);
			void updatePosition();
			void startContact(float yVel);
			void endContact();
	};
}
#endif
