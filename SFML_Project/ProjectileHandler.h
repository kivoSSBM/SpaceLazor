#ifndef PROJECTILEHANDLER_H
#define PROJECTILEHANDLER_H
#include "projectile.h"
#include <iostream>
class ProjectileHandler
{
private:
	int capacity;
	int nrOfProjectiles;
	Projectile* *projectiles;

	void initiate(int from = 0);
	float windowX(float size);
	float windowY(float size);
public:
	ProjectileHandler();
	~ProjectileHandler();
	void reset();
	Projectile getProjectile(int nr)const;
	void removeProjectile(int nr);
	int getNrOfProjectiles()const; 
	int getCapacity()const;
	void fireProjectile(sf::Vector2f startPos, float facingDir);
	void draw(sf::RenderWindow & window, float deltaTime); //check this range
	Projectile *& getProjectiles();
	Projectile& operator[]( int nr)const;
	ProjectileHandler & getLasers();
};
#endif