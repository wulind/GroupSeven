#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace escape {
	class Platform {
		private:
			b2Body* Body;
			b2World* World;

		public:
			Platform();
			Platform(float x, float y, int height, int width);

			float xCoord;
			float yCoord;
	    float mouseDragOffsetX;
			float mouseDragOffsetY;

			sf::Color color;

			int height;
			int width;

			bool isBeingDragged;

			void setWorld(b2World* World);
			void updateDragPosition(float mouseX, float mouseY);


	};
}
#endif
