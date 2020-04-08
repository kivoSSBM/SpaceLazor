#ifndef UNIT_H
#define	UNIT_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
class Unit :public sf::RectangleShape
{
public:
	static const float degrees;
private:
	sf::Texture theTexture;
	int lives;
	float xMovement;
public:
	Unit(std::string texture);
	virtual~Unit() = 0;
	virtual void update();

	void setLives(int lives);
	void loseLife();
	int getLives()const;

	void setxMovement(float x);
	float getxMovement()const;

	float windowX(float size);
	float windowY(float size);
};
#endif