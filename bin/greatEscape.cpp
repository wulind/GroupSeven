#include <SFML/Graphics.hpp>
#include "../include/GameLogic.h"

int main(int argc, char** argv)
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(800,600,32), "The Great Escape");
	sf::Clock gameTime;

	escape::GameLogic *gameLogic = new escape::GameLogic(&App);
    
    //Target 60 fps
    double targetMs = 1000/60;	
	gameLogic -> gameLoop(gameTime, targetMs);

	return 0;
}
