#include "../include/GameLogic.h"
//#include "../Box2D/Box2D.h"
//#include "Box2D-master/Box2D/Dynamics/b2World.h"

static const float SCALE = 30.f;

using namespace escape;


GameLogic::GameLogic(sf::RenderWindow *App){
	this -> App = App;
	this -> mainView = GameView(App);

	//Initializes world
	b2Vec2 Gravity(0.f, 0.1f);
	this -> World = new b2World(Gravity);
	this -> platform = Platform(this -> World);

	//Defines a Box. Could move this into class. Would need to pass a reference to World.
/*
	b2BodyDef BodyDef;
    	BodyDef.position = b2Vec2(platform.xCoord/SCALE, platform.yCoord/SCALE);
   	BodyDef.type = b2_dynamicBody;
    	b2Body* Body = this->World->CreateBody(&BodyDef);
	
	b2PolygonShape Shape;
	Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	this -> Body = &Body;
	//End Box Def
*/

/* Not functioning bottom platform
	//Bottom platform
	b2BodyDef BodyDef2;
	BodyDef2.position = b2Vec2(400.f/SCALE, 500.f/SCALE);
	BodyDef2.type = b2_staticBody;
	b2Body* Body2 = this->World->CreateBody(&BodyDef2);

	b2PolygonShape Shape2;
	Shape2.SetAsBox((800.f/2)/SCALE, (16.f/2)/SCALE);
	b2FixtureDef FixtureDef2;
	FixtureDef2.density = 0.f;
	FixtureDef2.shape = &Shape2;
	Body2->CreateFixture(&FixtureDef2);
*/
}

int GameLogic::gameLoop(){
  // start main loop
	while(this -> App -> isOpen()) {

    // process events
		sf::Event Event;
		while(this -> App -> pollEvent(Event)) {

			switch (Event.type) {
				case sf::Event::Closed:
					this -> App -> close();
					break;
				case sf::Event::MouseButtonPressed:
					this -> checkMouseOverPlatform();
					break;
				case sf::Event::MouseButtonReleased:
					this -> releaseAllPlatforms();
					break;
				default:
					break;
			}
		}

		this -> updateGame();

		Platform* p = &this -> platform;
		this -> mainView.update(p);
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
	this->World->Step(1/2000.f, 8, 3);
	//b2Body* BodyIterator = this->World->GetBodyList();
	//BodyIterator = BodyIterator->GetNext();


	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->App);

	this -> platform.updateDragPosition(mousePosition.x, mousePosition.y);
	/*
	if (this -> platform.isBeingDragged){
		this -> platform.updateDragPosition(mousePosition.x, mousePosition.y);
		/BodyIterator->SetTransform(b2Vec2(platform.xCoord, platform.yCoord),BodyIterator->GetAngle());
	}
	else{
		this -> platform.xCoord = BodyIterator->GetPosition().x;
		this -> platform.yCoord = BodyIterator->GetPosition().y;
	}
	*/
}
