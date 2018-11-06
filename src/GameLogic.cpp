#include "../include/GameLogic.h"

using namespace escape;

GameLogic::GameLogic(sf::RenderWindow *App){
	this -> App = App;
	this -> mainView = GameView(App);

	this -> platform = Platform(50, 50, 20, 100);
	this -> stolenObject = StolenObject(100, 100, 25);
	this -> menu = PlatformMenu(App);
	
}

int GameLogic::gameLoop(sf::Clock gameTime, double targetMs){
  // start main loop
	while(this -> App -> isOpen()) {
		//Restart the game clock
        gameTime.restart();

    // process events
		sf::Event event;
		while(this -> App -> pollEvent(event)) {

			switch (event.type) {
				case sf::Event::Closed:
					this -> App -> close();
					break;
				case sf::Event::MouseButtonPressed:
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						this -> checkMouseOverPlatform();
					}
					break;
				case sf::Event::MouseButtonReleased:
					this -> releaseAllPlatforms();
					break;
				default:
					break;
			}
		}

		//Get the elapsed time since the loop started
		double deltaMs = gameTime.getElapsedTime().asMilliseconds();

		//Adjust game timing by sleeping
		if(deltaMs < targetMs){
            sf::sleep(sf::milliseconds(targetMs-deltaMs));
        }

		this -> updateGame();

		this -> mainView.update(&this -> platform, &this -> stolenObject, NULL);
	}
}

bool GameLogic::checkMouseOverPlatform(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	float mouseX = mousePosition.x;
	float mouseY = mousePosition.y;

	float platformXStart = this -> platform.xCoord;
	float platformYStart = this -> platform.yCoord;

	float platformXEnd = platformXStart + this -> platform.width;
	float platformYEnd = platformYStart + this -> platform.height;

	bool hitsX = (platformXStart <= mouseX && mouseX <= platformXEnd);
	bool hitsY = (platformYStart <= mouseY && mouseY <= platformYEnd);

	if (hitsX && hitsY) {
		this -> platform.isBeingDragged = true;

		this -> platform.mouseDragOffsetX = mouseX - platformXStart;
		this -> platform.mouseDragOffsetY = mouseY - platformYStart;

		return true;
	}
	return false;
}

void GameLogic::releaseAllPlatforms(){
	this -> platform.isBeingDragged = false;
}

void GameLogic::updateGame(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	this -> platform.updateDragPosition(mousePosition.x, mousePosition.y);
}
