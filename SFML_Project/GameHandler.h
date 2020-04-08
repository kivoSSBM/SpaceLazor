#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <SFML\Audio.hpp>
#include <fstream>
#include "Animation.h"
#include "CollisionHandler.h"
#include "DebrisHandler.h"
#include "EnemyHandler.h"
#include "Map.h"
#include "Options.h"

class GameHandler
{
private:
	sf::RenderWindow window;
	sf::Event theEvent;
	sf::Clock clock;
	float deltaTime;
	
	int gameMode;

	CollisionHandler theCollision;
	Player thePlayer;
	DebrisHandler theDebris;
	EnemyHandler theEnemies;

	Animation* *laserHit;  
	int laserCap; 
	int nrOfHits; 

	Options main;
	TileMap map;

	int score; 
	int highScore;
	long double lightYears;
	sf::Font theFont; 
	sf::Text* highScoreText;
	sf::Text** hud;
	sf::Music bolero;

	void runAnimation(sf::Vector2f startPos);
	void removeAnimation(int nr);
	void spawn();

	void setHighScore();
	void theHud(); //int nrOf players
	void resetGame();
	float windowX(float size);
	float windowY(float size);

public:
	GameHandler();
	~GameHandler();

	void drawStartMenu();
	void drawAll();
	void update();
	int getScore()const;
};
#endif // !1