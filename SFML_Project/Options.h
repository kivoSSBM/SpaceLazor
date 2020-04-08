#ifndef OPTIONS_H
#define OPTIONS_H
#include <SFML\Graphics.hpp>
//#include <SFML\Audio.hpp>
#include <iostream>
#include "player.h"
class Options
{
private:
	sf::Clock clock;
	float deltaTime;
	int nrOfOptions;
	int currentOption;
	bool isPressed;
	bool inMenu; 
	int menuMode;
	int gamepad;  
	sf::Font theFont;
	sf::Text* *text; //single pointer?
	sf::Text* gameOver;  
	sf::CircleShape marker;

	sf::Texture controllersTx[3]; 
	sf::RectangleShape controllers[9]; 
	sf::RectangleShape testGround; 
	Player testPlayer;
	void updateController();
	void setMarkerPos(); 

	void loadingScreen();
	float windowX(float size);
	float windowY(float size);
public:
	Options();
	~Options();

	void goToMenu();
	bool getMenuStatus()const;
	void menu(sf::RenderWindow & window);
	void mainMenu(sf::RenderWindow & window);
	void controllerMenu(sf::RenderWindow & window);
	void gameOverScreen(sf::RenderWindow & window,int highScore,int score, double lightYears);
	int getGamepad()const;

};
#endif