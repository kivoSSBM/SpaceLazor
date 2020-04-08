#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "ProjectileHandler.h"
class Player :public Unit
{
private:
	float lastAngle;
	bool isPressed;
	ProjectileHandler lasers;
	int gamepad;
	void inputs(int gamepad, sf::RenderWindow & window,float deltaTime);
public:
	Player(int gamepad=0); 
	~Player();
	int getNrOfProjectiles()const;
	Projectile getProjectile(int nr)const;
	Projectile *&getProjectiles();
	void removeProjectile(int nr);
	int getPlayerLives()const;
	void setGamepad(int gamepad);
	void update(sf::RenderWindow & window, float deltaTime);

	void reset();
};
#endif