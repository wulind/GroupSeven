#include "MenuView.h"

using namespace escape;

MenuView::MenuView(){}

/*
* MenuView Constructor
* @param *App: pointer to game window
*/
MenuView::MenuView(sf::RenderWindow *_App, sf::Font *_font, sf::Texture* _mapTexture, sf::Texture *_levelDot){
	this -> App = _App;
	this -> font = _font;

    this -> mapTexture = _mapTexture;
    this -> levelDot = _levelDot;

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
* @param &levelSelect: Level Selection object
*/
void MenuView::loadLevelSelect(LevelSelect &levelSelect){
    //Creates a Level Select object which handles drawing the background art for the level select screen and the available level dots on the screen that can be clicked
 		sf::Text titleText;
 		titleText.setFont(*this -> font);
 		titleText.setCharacterSize(74);
    titleText.setString("Select A Level");
    titleText.setPosition(380,520);
    titleText.setFillColor(sf::Color::White);

		this -> drawBackground(this -> App, this -> mapTexture);
    this -> drawText(titleText);
		this -> drawLevelDots(levelSelect, this -> levelDot);

		this -> App -> display();
}



void MenuView::drawBackground(sf::RenderWindow *App, sf::Texture* _mapTexture){
    //Use the texture as a sprite
    sf::Sprite mapSprite(*_mapTexture);
    mapSprite.setScale(this -> screenX / this -> imageX, this -> screenY / this -> imageY);
    App -> draw(mapSprite);

}


/* Draws the individual level dots that represent unlocked levels to select a level
 * @param LevelSelect &levelSelect: Holds the level dots information stored in LevelSelect
 */
void MenuView::drawLevelDots(LevelSelect &levelSelect, sf::Texture* _levelDot){
		int i = 0;
		for (i; i < levelSelect.levels.size(); ++i){
			levelSelect.levels[i].circle.setRadius(25);
			levelSelect.levels[i].circle.setTexture(_levelDot);
	    	levelSelect.levels[i].circle.setPosition(levelSelect.levels[i].xCoord, levelSelect.levels[i].yCoord);
			App -> draw(levelSelect.levels[i].circle);
		}
}



/*
* Draws text onto screen
* @param text: text to be drawn
*/
void MenuView::drawText(sf::Text &text){
	text.setFont(*font);
	text.setFillColor(sf::Color::White);
	this -> App -> draw(text);
}
