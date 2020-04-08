#include "Enemy.h"
void Enemy::setDir(sf::Vector2f playerPos, float deltaTime) //dont need delta time??
{
	sf::Vector2f deltaPos = sf::Vector2f(playerPos.x - this->getPosition().x, playerPos.y - getPosition().y);
	float angle = 0.f;
	int chance= rand() % 400 + 0;
	if (deltaPos.x > 0 && deltaPos.y > 0)
	{
		if (deltaPos.x == 0)
			angle = 90;
		else
			angle = abs(atan(deltaPos.y / deltaPos.x))*(degrees);//(180 / 3.14159265359);
	}
	else if (deltaPos.x < 0 && deltaPos.y>0)
		angle = 180 - abs(atan(deltaPos.y / deltaPos.x))*(degrees);
	else if (deltaPos.x < 0 && deltaPos.y<0)
	{
		if (deltaPos.x == 0)
			angle = 270;
		else
			angle = 180 + abs(atan(deltaPos.y / deltaPos.x))*(degrees);
	}
	else if (deltaPos.x > 0 && deltaPos.y<0)
		angle = 360 - abs(atan(deltaPos.y / deltaPos.x))*(degrees);

	if (chance >= 397 ) 
	{
		lasers.fireProjectile(this->getPosition(), angle);
	}
}


Enemy::Enemy(sf::Vector2f startPos) :Unit("Enemy")
{
	setSize(sf::Vector2f(windowX(60), windowY(60)));
	setPosition(startPos);
	this->setLives(2);
	this->timer = 0;
	this->setxMovement(0);
}

Enemy::~Enemy(){}

bool Enemy::isAlive() const
{
	bool alive = false;
	if (this->getLives() > 0)
	{
		alive = true;
	}
	return alive;
}

int Enemy::getNrOfProjectiles() const
{
	return lasers.getNrOfProjectiles();
}

Projectile Enemy::getProjectile(int nr) const
{
	return lasers.getProjectile(nr);
}

Projectile *&Enemy::getProjectiles()
{
	return lasers.getProjectiles();
}

void Enemy::removeProjectile(int nr)
{
	lasers.removeProjectile(nr);
}

void Enemy::update(sf::RenderWindow& window, float deltaTime, sf::Vector2f playerPos)
{
	int movement = 0;

	if (this->timer < this->clock.getElapsedTime().asSeconds()) //
	{
		int time = rand() % 21 + 0;
		this->timer = float(time/10);
		movement = rand() % 64 + -32;
		this->setxMovement(15.f*movement);
		this->clock.restart();
	}
	move(windowX(this->getxMovement()*deltaTime), windowY(-100*deltaTime));
	setDir(playerPos,deltaTime);
	if (getPosition().x > windowX(-40) && getPosition().x < windowX(1530) &&
		getPosition().y>windowY(-40) && getPosition().y < windowY(1080))
	{
		window.draw(*this); //change to only draw when inside view
		lasers.draw(window, deltaTime);
	}
}

ProjectileHandler & Enemy::getLasers() 
{
	return lasers.getLasers();
}
