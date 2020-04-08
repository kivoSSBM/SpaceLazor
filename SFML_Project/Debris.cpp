#include "Debris.h"

Debris::Debris(sf::Vector2f startPos) : Unit("rock4")
{
	int x = rand()% 3 + -3;
	setSize(sf::Vector2f(windowX(60), windowY(60)));
	setPosition(startPos);
	this->setLives(3);
	this->setxMovement(x*100.f);
	this->bounce = 1;
}

Debris::~Debris(){}

void Debris::setBounce()
{
	this->bounce = this->bounce * -1;
}

bool Debris::isAlive() const
{
	bool alive = false;
	if (this->getLives() > 0)
	{
		alive = true;
	}
	return alive;
}

void Debris::operator=(const Debris & otherObj)
{
	if (this != &otherObj)
	{
		this->setLives(otherObj.getLives());
		this->setxMovement( otherObj.getxMovement());
		this->bounce = otherObj.bounce;
	}
}

void Debris::update(sf::RenderWindow & window, float deltaTime) // fix horisontal drift
{
	rotate(1.4f+this->getLives()*this->getxMovement()*0.005f);
	move(windowX(this->bounce*this->getxMovement()*deltaTime*this->getLives()/3), windowY(-300*(this->getLives()/3)* deltaTime)); 
	if (getPosition().x > 0 && getPosition().x < windowX(1530.f) &&
		getPosition().y>0 && getPosition().y < windowY(1080.f))
	{
		window.draw(*this);
	}
}
