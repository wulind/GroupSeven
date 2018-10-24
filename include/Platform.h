#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

namespace escape {
	class Platform {

		public:
			Platform();

			float xCoord;
			float yCoord;
	    float mouseDragOffsetX;
			float mouseDragOffsetY;

			int height;
			int width;

			bool isBeingDragged;

			sf::Color color;

			void updateDragPosition(float mouseX, float mouseY);
	};
}
#endif
