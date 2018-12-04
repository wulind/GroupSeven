#include "ContactListener.h"

using namespace escape;

/*
* Called when objects in b2World collide
*/
void ContactListener::BeginContact(b2Contact* contact){
  //check if fixture A was a ball
  void* bodyUserData = contact -> GetFixtureA() -> GetBody() -> GetUserData();
  if ( bodyUserData ){
    static_cast<StolenObject*> ( bodyUserData ) -> startContact();
  }

  bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
  if ( bodyUserData ){
    static_cast<StolenObject*> ( bodyUserData ) -> startContact();
  }
}

/*
* Reserved for future use
*/
void ContactListener::EndContact(b2Contact* contact){

}
