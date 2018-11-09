#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class Platform {

		public:
			Platform();
			Platform(float x, float y, int height, int width, b2World* World);

			float xCoord;
			float yCoord;
	    		float mouseDragOffsetX;
			float mouseDragOffsetY;

			int height;
			int width;

			bool isBeingDragged;

			sf::Color color;

			void updateDragPosition(float mouseX, float mouseY);

			b2Body* Body;
			b2World* World;
	};
}
#endif
