#include "GameView.h"

using namespace escape;

GameView::GameView(){}

/*
* Constructor
* @param *font: pointer to Cows & Aliens font used throughout the game
* @param *backgroundSprite: pointer to background sprite sheet
* @param *objectSprite: pointer to object sprite sheet
*/
GameView::GameView(sf::Font* font, sf::Texture* backgroundSprite, sf::Texture* objectSprite){
	this -> App.create(sf::VideoMode(800, 600, 32), "The Great Escape", sf::Style::Titlebar|sf::Style::Close);

	this -> font = font;
  this -> backgroundSpriteSheet = backgroundSprite;
  this -> objectSpriteSheet = objectSprite;

	if (music.openFromFile("../data/GreatEscapeTheiveryTheme.wav")){
		music.setLoop(true);
	}

	if (buffer.loadFromFile("../data/thump.wav")){
		thump.setBuffer(buffer);
	}

	this -> musicPlaying = false;
}

/*
* Returns current window
*/
sf::RenderWindow* GameView::getApp(){
	return &this -> App;
}

/*
* Gets current position of mouse in relation to the current render window
*/
sf::Vector2i GameView::getMousePosition(){
	return sf::Mouse::getPosition(this -> App);
}

/*
* Draws any text needed for the level
* @param text: text to draw
*/
void GameView::drawText(sf::Text &text) {
	text.setFont(*this -> font);
	text.setFillColor(sf::Color::White);
	this -> App.draw(text);
}

/*
* Draws Rectangle Object
* @param rect: rectangle to draw
*/
void GameView::drawRectangle(sf::RectangleShape &rect) {
	this -> App.draw(rect);
}

/*
 * Draws the CircleShape Object
 * @param &circle: circle shape to draw
 */
void GameView::drawCircle(sf::CircleShape &circle) {
	this -> App.draw(circle);
}

/*
 * Draws the level background using sprite sheet coordinates from the XML
 * @param level: Level object
 */
void GameView::drawBackground(Level &level){
    sf::Sprite background(*this -> backgroundSpriteSheet, sf::IntRect(level.backgroundStartX, level.backgroundStartY, 800, 600));
    this -> App.draw(background);
}

/*
* Writes dialogue pages
* @param text: text to draw that contains storyline
* @param funFact: fun fact to write
*/
void GameView::displayLevelStory(sf::Text &text, sf::Text &funFact){
	this -> App.clear();
	this -> drawText(text);
	this -> drawText(funFact);

	sf::Text escapePage;
	escapePage.setCharacterSize(20);
	escapePage.setString("Click anywhere or press any key to continue.");
	escapePage.setPosition(10,500);

	this -> drawText(escapePage);

	this -> App.display();
}

/*
* Creates all of the SFML-related objects that need to be drawn
* @param level: Level object representing current level
* @param play: true if in Game State PLAY
*/
void GameView::update(Level &level, bool play){
	this -> App.clear();
  this -> drawBackground(level);

	//Display healthbar
	//2 rectangles, top one is White, bottom is red. Make top one shorter on each hit
	sf::RectangleShape top(sf::Vector2f(level.stolenObject.health * 20, 10));
	top.setFillColor(sf::Color::White);
	top.setPosition(300, 80);
	sf::RectangleShape bottom(sf::Vector2f(200, 10));
	bottom.setFillColor(sf::Color::Red);
	bottom.setPosition(300, 80);
	this -> drawRectangle(bottom);
	this -> drawRectangle(top);

	//Display some text indictating bar at the top is healthbar
	sf::Text health;
	health.setCharacterSize(30);
	health.setString("Object Durability");
	health.setPosition(290, 40);
	this -> drawText(health);

	//Obstacles
	sf::RectangleShape platform;
	int i = 0;
	for (i; i < level.obstacles.size(); ++i){
		platform = this -> makeRectangle(level.obstacles[i].width, level.obstacles[i].height, level.obstacles[i].xCoord, level.obstacles[i].yCoord, level.obstacles[i].rotation);
		platform.setFillColor(level.obstacles[i].color);
		level.obstacles[i].bounds = platform.getGlobalBounds();
		level.obstacles[i].origin = platform.getPosition();
		this -> drawRectangle(platform);
	}

	//StolenObject
	sf::CircleShape circle = this -> makeStolenObject(level.stolenObject.radius, level.stolenObject.xCoord, level.stolenObject.yCoord, level.stolenObject.rotation);
	level.stolenObject.bounds = circle.getGlobalBounds();
	circle.setTextureRect(sf::IntRect(level.stolenObject.spriteSheetStartX, level.stolenObject.spriteSheetStartY, 256, 256));
	this -> drawCircle(circle);

	if (level.stolenObject.playSound){
		this -> thump.play();
		level.stolenObject.playSound = false;
	}

	//Goal
	sf::RectangleShape goal = this -> makeRectangle(level.goal.width, level.goal.height, level.goal.xCoord, level.goal.yCoord, 0);
	goal.setTexture(this -> objectSpriteSheet, false);
	goal.setTextureRect(sf::IntRect(0, 1320, 900, 400));
	level.goal.bounds = goal.getGlobalBounds();
	this -> drawRectangle(goal);

	//Platform menu
	if(level.finishButton.show){//if GameState setup
		sf::RectangleShape menu(sf::Vector2f(180, this -> screenY));
		menu.setPosition(this -> screenX - 180, 0);
		menu.setFillColor(sf::Color(0, 0, 0, 100));
		this -> drawRectangle(menu);
		this -> drawText(level.finishButton.button);
		this -> drawText(level.platformMenu.title);
	}

	//Platforms
	i = 0;
	for (i; i < level.platforms.size(); ++i){
		if(play && level.platforms[i].show){//If playing, don't show the platforms that haven't been dragged
			platform = this -> makeRectangle(level.platforms[i].width, level.platforms[i].height, level.platforms[i].xCoord, level.platforms[i].yCoord, level.platforms[i].rotation);
			platform.setFillColor(sf::Color::White);

			level.platforms[i].bounds = platform.getGlobalBounds();
			level.platforms[i].origin = platform.getPosition();

			this -> drawRectangle(platform);
		}else if (!play){
			platform = this -> makeRectangle(level.platforms[i].width, level.platforms[i].height, level.platforms[i].xCoord, level.platforms[i].yCoord, level.platforms[i].rotation);
			platform.setFillColor(sf::Color::White);

			level.platforms[i].bounds = platform.getGlobalBounds();
			level.platforms[i].origin = platform.getPosition();

			this -> drawRectangle(platform);
		}
	}

	this -> App.display();
}

/*
* Makes SFML rectangle objects
* Always sets origin to the center of the shape rather than default upper left corner
* @param width: width of the rectangle
* @param height: height of the rectangle
* @param xCoord: x coordinate of rectangle
* @param yCoord: y coordinate of rectangle 
* @param rotation: rotation of rectangle
*/
sf::RectangleShape GameView::makeRectangle(int width, int height, float xCoord, float yCoord, int rotation){
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setOrigin(width/2, height/2);
	rectangle.setPosition(xCoord, yCoord);
	rectangle.setRotation(rotation);

	return rectangle;
}

/*
* Makes SFML circle objects
* Always sets origin to the center of the shape rather than default upper left corner of bounding rectangle
* @param radius: radius of circle
* @param xCoord: x coordinate of circle
* @param yCoord: y coordinate of circle
* @param rotation: rotation of cirlce
*/
sf::CircleShape GameView::makeStolenObject(int radius, float xCoord, float yCoord, float rotation){
	sf::CircleShape circle(radius);
	circle.setOrigin(radius, radius);
	circle.setPosition(xCoord, yCoord);
	circle.setTexture(this -> objectSpriteSheet, false);
	circle.setRotation(rotation);

	return circle;
}

/*
* Pauses music associated with playing a level
*/
void GameView::pauseMusic(){
	this -> music.pause();
}

/*
* Plays menu music when playing a level
*/
void GameView::playMusic(){
	this -> music.play();
}
