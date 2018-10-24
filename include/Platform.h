#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

namespace gameObject {
	class Platform {

	private:

	public:
		Platform();
		float xCoord;
		float yCoord;
		int height;
		int width;
		bool isBeingDragged;
		float mouseDragOffsetX;
		float mouseDragOffsetY;
		sf::Color color;

		void updateDragPosition(float mouseX, float mouseY);
	};
}
#endif
