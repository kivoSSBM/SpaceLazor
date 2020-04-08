#include "Projectile.h"

void Projectile::calcDirection(float angle)
{
	float x = 1000.f;
	float y = 0.f;
	if (angle >= 0 && angle < 90)
	{
		x = 90-angle;
		y = angle;
	}
	if (angle >= 90 && angle < 180)
	{
		x = 90-angle;
		y = 180-angle;
	}
	if (angle >= 180 && angle < 270)
	{
		x = angle-270;
		y = 180-angle;
	}
	if (angle >= 270.f && angle < 360.f)
	{
		x = angle-270;
		y = angle-360;
	}
	this->direction = sf::Vector2f(x*7, y*7);
}

Projectile::Projectile(sf::Vector2f startPos, float angle) :Unit("laser")
{
	//this->setLives(1);
	setSize(sf::Vector2f(40, 8));
	setPosition(startPos);
	setOrigin(0,0);
	setRotation(angle);
	this->calcDirection(angle);
}

Projectile::~Projectile(){}

void Projectile::operator=(const Projectile & otherObj)
{
	if (this != &otherObj)
	{
		this->direction = otherObj.direction;
	}
}

void Projectile::update(sf::RenderWindow & window, float deltaTime)
{
 	move(this->direction.x*deltaTime, this->direction.y*deltaTime); 
}

//Projectile & Projectile::getThisProjectile() 
//{
//	return *this;
//}
