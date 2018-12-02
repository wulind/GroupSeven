#include "../include/StolenObjectContactListener.h"
#include <iostream>

using namespace escape;


void StolenObjectContactListener::BeginContact(b2Contact* contact){
  //check if fixture A was a ball
  //std::cout << "Contact!\n";
  void* bodyUserData = contact -> GetFixtureA() -> GetBody() -> GetUserData();
  if ( bodyUserData ){
    static_cast<StolenObject*> ( bodyUserData ) -> startContact();
  }

  bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
  if ( bodyUserData ){
    static_cast<StolenObject*> ( bodyUserData ) -> startContact();
  }
}

void StolenObjectContactListener::EndContact(b2Contact* contact){
  //check if fixture A was a ball
  void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
  if ( bodyUserData ){
    static_cast<StolenObject*> ( bodyUserData ) -> endContact();
  }

  bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
  if ( bodyUserData ){
    static_cast<StolenObject*> ( bodyUserData ) -> endContact();
  }
}
