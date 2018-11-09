#include "../include/Goal.h"

static const float SCALE = 30.f;

using namespace escape;

Goal::Goal(){}

/*
* Constructor
* @param x: x coordinate of stolen object (Bottom Left)
* @param y: y coordinate of stolen object (Bottom Left)
* @param World: Box2D Object where the object will be placed
*/
Goal::Goal(float x, float y, b2World* World){
	this -> xCoord = x;
	this -> yCoord = y;

	this -> color = sf::Color::White;

	//Box2D Information
	this -> World = World;

	//Box2D body with a static body so it does not move on its own.
	//Maybe change to add motion to it? Getaway animation?
	b2BodyDef BodyDef;
    	BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
   	BodyDef.type = b2_staticBody;
    	b2Body* Body = this -> World -> CreateBody(&BodyDef);
	
	//Designed with length 8
	//6 Shapes associated with this body.
	//Top left corner (placed at center - 3.5, center + 2.5)
	//Underbody
	//Forward Upward
	//Front
	//2 Wheels

}


/*
* Update the Position of a Stolen Object based on Box2D Physics.
*/
void Goal::UpdatePosition(){
	//Set body to awake in case of it being 0 velocity in both x and y direction to prevent
	//Freezing
	this -> Body -> SetAwake(1);

	this -> xCoord = this -> Body -> GetPosition().x * SCALE;
	this -> yCoord = this -> Body -> GetPosition().y * SCALE;
}
