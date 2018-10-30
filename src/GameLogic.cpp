#include "../include/GameLogic.h"

using namespace escape;
using namespace factory;

/*
* @param *App: pointer to game window
*/
GameLogic::GameLogic(sf::RenderWindow *App){

	this -> App = App;
	this -> mainView = GameView(App);

	this -> levelFactory = LevelFactory();
	this -> platforms = this->levelFactory.getPlatforms(1);
	this -> stolenObject = StolenObject(100, 100, 25);
	this -> menu = PlatformMenu(App);
	this -> finishButton = FinishButton(App);
}

/*
* Main loop
*/
int GameLogic::gameLoop(){
  // start main loop
	while(this -> App -> isOpen()) {

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
						this -> updateMouse();
					}
					break;
				case sf::Event::MouseButtonReleased:
					this -> releaseAllPlatforms();
					break;
				default:
					break;
			}
		}

		this -> mainView.update(&this -> platforms, &this -> stolenObject, &this -> menu);
	}

	return 1;
}

/*
* Checks game state and updates screen based on that
*/
void updateGame();

bool GameLogic::checkMouseOverPlatform(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	float mouseX = mousePosition.x;
	float mouseY = mousePosition.y;

	for (Platform curPlatform : platforms) {
		float platformXStart = curPlatform.xCoord;
		float platformYStart = curPlatform.yCoord;

		float platformXEnd = platformXStart + curPlatform.width;
		float platformYEnd = platformYStart + curPlatform.height;

		bool hitsX = (platformXStart <= mouseX && mouseX <= platformXEnd);
		bool hitsY = (platformYStart <= mouseY && mouseY <= platformYEnd);

		if (hitsX && hitsY) {
			curPlatform.startDrag();

			printf("Is being dragged: %d\n", curPlatform.isBeingDragged);

			curPlatform.mouseDragOffsetX = mouseX - platformXStart;
			curPlatform.mouseDragOffsetY = mouseY - platformYStart;

			return true;
		}
	}

	return false;
}

void GameLogic::releaseAllPlatforms(){
	for (Platform curPlatform : platforms) {
		printf("sweet release");
		curPlatform.endDrag();
	}
}

void GameLogic::updateMouse(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	for (Platform curPlatform : platforms) {
		if(curPlatform.isBeingDragged)
			curPlatform.updateDragPosition(mousePosition.x, mousePosition.y);
	}
	
}
