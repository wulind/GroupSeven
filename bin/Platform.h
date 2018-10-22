#pragma once
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
		sf::Color color;
	};
}