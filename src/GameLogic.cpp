#include "../include/GameLogic.h"

static const float SCALE = 30.f;

using namespace escape;

/*
* @param *App: pointer to game window
*/
GameLogic::GameLogic(sf::RenderWindow *App){
	this -> App = App;
	this -> mainView = GameView(App);

	//Initializes world
	b2Vec2 Gravity(0.f, 0.1f);
	this -> World = new b2World(Gravity);
	this -> platform = Platform(50, 50, 20, 100, this -> World);

	//this -> platform = Platform(50, 50, 20, 100);
	this -> stolenObject = StolenObject(100, 100, 25, this -> World);
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
					}
					break;
				case sf::Event::MouseButtonReleased:
					this -> releaseAllPlatforms();
					break;
				default:
					break;
			}
		}

		this->World->Step(1/30.f, 8, 3);
		this -> stolenObject.UpdatePosition();
		

		this -> updateMouse();

		this -> mainView.update(&this -> platform, &this -> stolenObject, &this -> menu);
	}
}

/*
* Checks game state and updates screen based on that
*/
void updateGame();

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

void GameLogic::updateMouse(){
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	this -> platform.updateDragPosition(mousePosition.x, mousePosition.y);
}
