#ifndef OPTIONS_H
#define OPTIONS_H
#include <SFML/Graphics.hpp>
#include "GameState.h"


namespace escape{
  class Options{

    public:
      Options();
      void adjustVolume(GameState &state);
      char* getVolume();
      bool volumeOn();


    private:
      int masterVolume = 1;
  };
}
#endif
