#include "../include/MenuView.h"

using namespace escape;

MenuView::MenuView(){}

/*
* MenuView Constructor
* @param *App: pointer to game window
*/
MenuView::MenuView(sf::RenderWindow *_App, sf::Font *_font){
	this -> App = _App;
	this -> font = _font;
}

/*
* Loads title screen
* @param titlePage: title page object that holds all text
*/
void MenuView::loadTitleScreen(TitlePage &titlePage){
	titlePage.title.setFont(*this -> font);
	titlePage.play.setFont(*this -> font);

	titlePage.title.setPosition((this -> screenX/2.0f) - (titlePage.title.getLocalBounds().width/2.0f), 50);
	titlePage.play.setPosition((this -> screenX/2.0f) - (titlePage.play.getLocalBounds().width/2.0f), 500);
	//Draw to screen
	this -> App -> clear(sf::Color::Black);

	this -> drawText(titlePage.title);
	this -> drawText(titlePage.play);

	this -> App -> display();
}

/*
* Loads level selection screen
*/
void MenuView::loadLevelSelect(){


    // Load a sprite to display
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile(resourcePath() + "../data/LevelSelectionBlank.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite mapSprite(mapTexture);
    mapSprite.setScale(this -> screenX / this -> imageX, this -> screenY / this -> imageY);


	this -> draw(mapSprite);
	this -> App -> display();
}

void MenuView::drawText(sf::Text &text){
	this -> App -> draw(text);
}
