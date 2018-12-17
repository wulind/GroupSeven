#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class Platform {
		public:
			Platform();
			Platform(float x, float y, int height, int width);

			b2Body* Body;

			float xCoord;
			float yCoord;
			//offset needed so that the mouse can drag anywhere on platform and platform won't jump to that location
			float mouseDragOffsetX;
			float mouseDragOffsetY;

			int height;
			int width;

			//The absolute rotation of an object from base
			int rotation;

			sf::Color color;
			sf::FloatRect bounds;
			sf::Vector2f origin;

			bool isBeingDragged;//true if user is currently draggin platform
		
			//Boolean that determines whether or not platform should show incase
			//user doesn't drag a platform out of the menu, then it will not show
			bool show = false; //true when the platform has been dragged or is an obstacle.

			void setWorld(b2World* World);
			void updateDragPosition(float mouseX, float mouseY);

			void setRotation(int rotation);
	};
}
#endif
