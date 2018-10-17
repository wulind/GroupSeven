#include <SFML/Graphics.hpp>
#include "finishbutton.hpp"
#include "menu.hpp"
#include "gameState.hpp"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "The Great Escape");
    FinishButton finishButton;
    Menu menu;
    GameState gs;
    gs.init();
  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    // clear screen and fill with blue
    App.clear(sf::Color::White);
    menu.update(&App, &gs);
    finishButton.update(&App, &gs);
      
      
    // display
    App.display();
  }

  // Done.
  return 0;
}
