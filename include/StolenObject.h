#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class StolenObject {

		public:
      StolenObject();
			StolenObject(float x, float y, int radius);

			b2Body* Body;

			float xCoord;
			float yCoord;

			int spriteSheetStartX;
      int spriteSheetStartY;

			int radius;

			double timeSinceLastDamage;
			sf::Clock timer;
			bool playSound;

			float rotation;

			sf::FloatRect bounds;

			sf::Color color;
			sf::Texture objTexture;

			void setWorld(b2World* World);
			void updatePosition();
			void startContact();
			void endContact();
	};
}
#endif
