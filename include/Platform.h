#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class Platform {

		public:
			Platform();
			Platform(b2World* World);
			Platform(float x, float y, int height, int width);

			float xCoord;
			float yCoord;
	    		float mouseDragOffsetX;
			float mouseDragOffsetY;

			int height;
			int width;

			bool isBeingDragged;

			sf::Color color; //TODO: Remove, this is temporary until we add sprites

			void updateDragPosition(float mouseX, float mouseY);

			b2Body* Body;
			b2World* World;
	};
}
#endif
