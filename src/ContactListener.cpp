#include "ContactListener.h"

using namespace escape;

/*
* Called when objects in b2World collide
*/
void ContactListener::BeginContact(b2Contact* contact){
  //check if fixture A was a ball
  void* bodyUserData = contact -> GetFixtureA() -> GetBody() -> GetUserData();
  if ( bodyUserData ){
    double yVel = static_cast<StolenObject*> ( bodyUserData ) -> Body -> GetLinearVelocity().y;
    static_cast<StolenObject*> ( bodyUserData ) -> startContact(yVel);

  }

  bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
  if ( bodyUserData ){
    double yVel = static_cast<StolenObject*> ( bodyUserData ) -> Body -> GetLinearVelocity().y;
    static_cast<StolenObject*> ( bodyUserData ) -> startContact(yVel);
  }
}

/*
* Reserved for future use
*/
void ContactListener::EndContact(b2Contact* contact){

}
