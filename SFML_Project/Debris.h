#ifndef DEBRIS_H
#define DEBRIS_H
#include "Unit.h"
class Debris :public Unit
{
private:
	int bounce;
public:
	Debris(sf::Vector2f startPos );
	~Debris();
	void setBounce();
	bool isAlive()const;
	void operator=(const Debris &otherObj);
	void update(sf::RenderWindow &window, float deltaTime);
};
#endif