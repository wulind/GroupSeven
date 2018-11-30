#include "Dialogue.h"

using namespace escape;

Dialogue::Dialogue(){}

/*
* Draws dialogue depending on the level the player selected.
* Currently hardcoded, will use xml later
*/
void Dialogue::playStory(sf::RenderWindow *App, GameState *state, int levelSelected, GameView *gameView){
	App -> clear();
	sf::Text text;

	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);

//Hardcoded story text to draw on the screen depending on the level the player selected
	switch(levelSelected){
		case 1:
			text.setString("We’re looking to form a crew, and we heard you were pretty good once upon a time. \nAre you game? What’s your name?");
			text.setPosition(10,300);
			App -> draw(text);
			text.setString("Well Player, we’re going to have to test your skills first. \nTry stealing that bag of money from the Bank of McGlothlin. \nUse the platform to guide it into our truck. We’ll be waiting for you on the ground.");
			text.setPosition(10,340);
			gameView -> drawText(text);

		break;

		case 2:
			text.setCharacterSize(24);
			text.setString("Not bad, Player. Alright you’re in. First job’s easy: the Met.");
			text.setPosition(10,300);
			gameView -> drawText(text);

		break;

		case 3:
			text.setCharacterSize(24);
			text.setString("Good work Player. Next job’s easy: the Louvre.");
			text.setPosition(10,300);
			gameView -> drawText(text);

		break;

	}
	App -> display();

//Handle a key input. If any key is pressed advance to LOADING game state and then to playing the level
	sf::Event event;
	while (App -> pollEvent(event)) {
    switch (event.type) {
        // key pressed
        case sf::Event::KeyPressed:
           state -> setState(GameState::State::LOADING);
            break;
    }
	}
}
