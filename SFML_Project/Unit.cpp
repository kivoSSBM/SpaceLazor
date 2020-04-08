#include "Unit.h"
const float Unit::degrees =180.f / (float)3.14159265359;
Unit::Unit(std::string texture)
{
	std::string fileName = "textures/" + texture + ".png";
	theTexture.loadFromFile(fileName);
	setTexture(&theTexture);
	this->lives = 1;
}
void Unit::update()
{

}
void Unit::setLives(int lives)
{
	this->lives = lives;
}
void Unit::loseLife()
{
	this->lives = this->lives - 1;
}
int Unit::getLives() const
{
	return this->lives;
}
void Unit::setxMovement(float x)
{
	this->xMovement = x;
}
float Unit::getxMovement() const
{
	return this->xMovement;
}
float Unit::windowX(float size)
{
	float windowX = 1920.f / size;
	return sf::VideoMode::getDesktopMode().width / windowX;
}

float Unit::windowY(float size)
{
	float windowY = 1080.f / size;
	return sf::VideoMode::getDesktopMode().height / windowY;
}
Unit::~Unit(){}
