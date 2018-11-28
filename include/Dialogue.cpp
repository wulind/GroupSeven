#include "Dialogue.h"

using namespace escape;

Dialogue::Dialogue(){

}

void Dialogue::playStory(sf::RenderWindow *App, GameState *state){

	if (!font.loadFromFile("../Data/aliensCows.ttf"))
	{
    // error...
	}

	sf::Text text;

	text.setFont(font);
	text.setCharacterSize(24); 
	text.setFillColor(sf::Color::White);
	
	//Set text to xml story dialogue
	
	App -> draw(text);


}
