#include "DebrisHandler.h"

void DebrisHandler::addRock(sf::Vector2f startPos)
{
	this->rocks[this->nrOfRocks++] = new Debris(startPos);
	//std::cout << "add one" << std::endl;
}

void DebrisHandler::removeRock(int nr)
{
	delete rocks[nr];
	if (this->rocks[nrOfRocks - 1] != nullptr)
		this->rocks[nr] = this->rocks[--nrOfRocks];
	this->rocks[nrOfRocks] = nullptr;
}

DebrisHandler::DebrisHandler()
{
	this->cap = 15;
	this->nrOfRocks = 0;
	rocks = new Debris*[cap];
	for (int i = 0;i < cap;i++)
		this->rocks[i] = nullptr;
}

DebrisHandler::~DebrisHandler()
{
	for (int i = 0;i < this->nrOfRocks;i++)
		delete rocks[i];
	delete[]rocks;
}

void DebrisHandler::reset()
{
	for (int i = 0;i < this->cap;i++)
		delete rocks[i];
	this->nrOfRocks = 0;
}

Debris & DebrisHandler::getRock(int nr)  //HERE
{
	return *this->rocks[nr];
}

Debris *& DebrisHandler::getRocks() const
{
	return *rocks;
}

void DebrisHandler::updateRock(int nr, sf::RenderWindow& window, float deltaTime)
{
	this->rocks[nr]->update(window, deltaTime);
}

void DebrisHandler::gotHit(int nr)
{
	this->rocks[nr]->loseLife();
}

bool DebrisHandler::checkIfNullptr(int nr)
{
	bool result = true;
	if (rocks[nr] != nullptr)
	{
		result = false;
	}
	return result;
}

int DebrisHandler::getNrOfRocks() const
{
	return this->nrOfRocks;
}

//int DebrisHandler::getCapacity() const
//{
//	return this->cap;
//}

bool DebrisHandler::checkAdd(sf::Vector2f startPos)
{
	bool result = false;
	if (this->nrOfRocks < this->cap)
	{
		result = true;
		this->addRock(startPos);
	}
	return result;
}

bool DebrisHandler::checkAlive()
{
	bool isAlive = true;
	for (int i = 0;i < this->nrOfRocks;i++)
	{
		if (rocks[i]->isAlive() == false)
		{
			this->removeRock(i);
			isAlive = false; 
		}
	}
	return isAlive;
}

