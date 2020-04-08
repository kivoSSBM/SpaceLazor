#ifndef DEBRISHANDLER_H
#define DEBRISHANDLER_H
#include <iostream>
#include <string>
#include "Debris.h"
class DebrisHandler
{
private:
	Debris* *rocks;
	int nrOfRocks;
	int cap;

	//void initiate(int from = 0);
	void addRock(sf::Vector2f startPos);
	//void removeRock(int nr);
	
public:
	DebrisHandler();
	~DebrisHandler();

	void reset();
	Debris & getRock(int nr);
	Debris *&getRocks()const;
	void updateRock(int nr, sf::RenderWindow& window, float deltaTime);
	void gotHit(int nr);

	bool checkIfNullptr(int nr);
	int getNrOfRocks()const;
	//int getCapacity()const;
	bool checkAdd(sf::Vector2f startPos);
	void removeRock(int nr);
	bool checkAlive();

};
#endif