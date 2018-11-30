#include "MenuView.h"

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
* @param &levelSelect: Level Selection object
*/
void MenuView::loadLevelSelect(LevelSelect &levelSelect){
    //Creates a Level Select object which handles drawing the background art for the level select screen and the available level dots on the screen that can be clicked
		levelSelect.drawBackground(App);
 		
 		sf::Text titleText;
 		titleText.setFont(*font);
 		titleText.setCharacterSize(74); 
    	titleText.setString("Select A Level");
    	titleText.setPosition(380,520);
    	titleText.setFillColor(sf::Color::White);
		drawText(titleText);
		drawLevelDots(App, levelSelect);


    	// levelSelect.drawLevelDots(App);
		this -> App -> display();
}


/* Draws the individual level dots that represent unlocked levels to select a level
 * @param *App: pointer to game window
 */

void MenuView::drawLevelDots(sf::RenderWindow *App, LevelSelect &levelSelect){

	  sf::Texture levelDot;
    if (!levelDot.loadFromFile("../data/LevelDot.png")) {

    }

    levelSelect.levels.resize(10);
    levelSelect.levels[0].setRadius(25);
    levelSelect.levels[0].setTexture(&levelDot);
    levelSelect.levels[0].setPosition(190, 243);
    
    levelSelect.levels[1].setRadius(25);
    levelSelect.levels[1].setTexture(&levelDot);
    levelSelect.levels[1].setPosition(90, 173);



    for(int i = 0; i < 2; i++){
        App -> draw(levelSelect.levels[i]);
    }
}



/*
* Draws text onto screen
*/
void MenuView::drawText(sf::Text &text){
	this -> App -> draw(text);
}
