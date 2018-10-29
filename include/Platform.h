#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

namespace escape {
	class Platform {

		public:
			Platform();
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
	};
}
#endif
