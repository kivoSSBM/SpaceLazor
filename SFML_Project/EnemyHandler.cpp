#include "EnemyHandler.h"

void EnemyHandler::addEnemy(sf::Vector2f startPos)
{
	this->enemy[this->nrOfEnemies++] = new Enemy(startPos);
}

void EnemyHandler::removeEnemy(int nr)
{
	delete enemy[nr];
	if (this->enemy[nrOfEnemies - 1] != nullptr)
		this->enemy[nr] = this->enemy[--nrOfEnemies];
	this->enemy[nrOfEnemies] = nullptr;
}

void EnemyHandler::removeProjectile(int enemyID, int nr)
{
	this->enemy[enemyID]->removeProjectile(nr);
}

EnemyHandler::EnemyHandler()
{
	this->cap=10;
	this->nrOfEnemies = 0;
	enemy = new Enemy*[cap];
	for (int i = 0;i < cap;i++)
		this->enemy[i] = nullptr;
}

EnemyHandler::~EnemyHandler()
{
	for (int i = 0;i < this->nrOfEnemies;i++)
		delete enemy[i];
	delete[] enemy;
}

void EnemyHandler::reset()
{
	for (int i = 0;i < this->cap;i++)
		delete enemy[i];
	this->nrOfEnemies = 0;
}

Enemy *& EnemyHandler::getEnemies() const
{
	//for (int i = 0;i < nrOfEnemies;i++)
	//{

	//}
	return *enemy;
}

Enemy & EnemyHandler::getEnemy(int id) 
{
	return *this->enemy[id];
}

sf::Vector2f EnemyHandler::getEnemyPosFrom(int nr)const
{
	return this->enemy[nr]->getPosition();
}

void EnemyHandler::updateEnemy(int nr, sf::RenderWindow & window, float deltaTime, sf::Vector2f playerPos)
{
	this->enemy[nr]->update(window, deltaTime, playerPos);
}

void EnemyHandler::gotHit(int nr)
{
	this->enemy[nr]->loseLife();
}

sf::FloatRect EnemyHandler::getEnemyGBFrom(int nr) const
{
	return this->enemy[nr]->getGlobalBounds();
}

bool EnemyHandler::checkIfAliveFrom(int nr)const
{
	return this->enemy[nr]->isAlive();
}

Projectile *& EnemyHandler::getProjectiles(int enemyId)
{
	return enemy[enemyId]->getProjectiles();
}

//Projectile EnemyHandler::getProjectileFrom(int enemyID, int nr)
//{
//	return this->enemy[enemyID]->getProjectile(nr);
//}

//int EnemyHandler::getNrOfProjectilesFrom(int nr) const
//{
//	return this->enemy[nr]->getNrOfProjectiles();
//}

bool EnemyHandler::checkIfNullptr(int nr)
{
	bool result = true;
	if (enemy[nr] != nullptr)
	{
		result = false;
	}
	return result;
}

int EnemyHandler::getNrOfEnemies() const
{
	return this->nrOfEnemies;
}

//int EnemyHandler::getCapacity() const
//{
//	return this->cap;
//}

bool EnemyHandler::checkAdd(sf::Vector2f startPos)
{
	bool result = false;
	if (this->nrOfEnemies < this->cap)
	{
		result = true;
		this->addEnemy(startPos);
	}
	return result;
}

bool EnemyHandler::checkAlive()
{
	bool isAlive = true;
	for (int i = 0;i < this->nrOfEnemies;i++)
	{
		if (enemy[i]->isAlive() == false)
		{
			this->removeEnemy(i);
			isAlive = false; 
		}
	}
	return isAlive;
}

ProjectileHandler EnemyHandler::getLasers(int id) const
{
	return enemy[id]->getLasers();
}
