#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Unit.h"
class Projectile :public Unit
{
private:
	sf::Vector2f direction;
	void calcDirection(float angle);
public:
	Projectile(sf::Vector2f startPos, float angle); 
	virtual~Projectile();
	void operator=(const Projectile &otherObj);
	void update(sf::RenderWindow & window, float deltaTime);

	//Projectile & getThisProjectile() ;
};
#endif