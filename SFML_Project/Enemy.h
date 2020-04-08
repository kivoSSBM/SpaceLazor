#ifndef ENEMY_H
#define ENEMY_H
#include "Unit.h"
#include "ProjectileHandler.h"
class Enemy :public Unit
{
private:
	ProjectileHandler lasers;
	sf::Clock clock;
	float timer;
public:
	Enemy(sf::Vector2f startPos);
	~Enemy();
	bool isAlive()const;
	int getNrOfProjectiles()const;
	Projectile getProjectile(int nr)const;
	Projectile *& getProjectiles();
	void removeProjectile(int nr);
	void setDir(sf::Vector2f playerPos, float deltaTime);  
	void update(sf::RenderWindow &window, float deltaTime, sf::Vector2f playerPos);
	ProjectileHandler& getLasers();
};
#endif