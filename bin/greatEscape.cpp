#include <SFML/Graphics.hpp>
#include "../include/GameLogic.h"

int main(int argc, char** argv)
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(800,600,32), "The Great Escape");

	escape::GameLogic *gameLogic = new escape::GameLogic(&App);

	gameLogic -> gameLoop();

	// Done.
	return 0;
}
