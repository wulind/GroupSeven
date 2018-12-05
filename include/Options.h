#ifndef OPTIONS_H
#define OPTIONS_H
#include <SFML/Graphics.hpp>
#include <string>


namespace escape{
  class Options{

    public:
      Options();
      void adjustVolume();
      char* getVolume();


    private:
      int masterVolume = 1;
  };
}
#endif
