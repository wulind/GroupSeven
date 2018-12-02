#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class Platform {
		private:
			b2Body* Body;//TODO: do we need these?
			b2World* World;

		public:
			Platform();
			Platform(float x, float y, int height, int width);

			float xCoord;
			float yCoord;
	    float mouseDragOffsetX;
			float mouseDragOffsetY;

			int height;
			int width;

			//The absolute rotation of an object from base
			int rotation;

			sf::Color color;
			sf::FloatRect bounds;
			sf::Vector2f origin;

			bool isBeingDragged;

			void setWorld(b2World* World);
			void updateDragPosition(float mouseX, float mouseY);

			void setRotation(int rotation);


	};
}
#endif
