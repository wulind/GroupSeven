#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include "StolenObject.h"
#include "Platform.h"

namespace escape{
  class ContactListener : public b2ContactListener{
    public:
      void BeginContact(b2Contact* contact);
      void EndContact(b2Contact* contact);
  };
}
#endif
