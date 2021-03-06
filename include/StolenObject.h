#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class StolenObject {

		public:
			StolenObject();
			StolenObject(float x, float y, int radius, float restitution);

			b2Body* Body; //Box2D body
			float restitution; //bounciness of stolen object

			float xCoord;
			float yCoord;

			int spriteSheetStartX;
      			int spriteSheetStartY;

			int radius;

			int health;
			double timeSinceLastDamage;
			sf::Clock timer;
			bool playSound;//true if sound is played

			float rotation;

			sf::FloatRect bounds;

			sf::Color color;
			sf::Texture objTexture;

			void setWorld(b2World* World);

			void updatePosition();
			void startContact(float yVel);
			void endContact();

			void killSpeed();
	};
}
#endif
