#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H
#include <iostream>
#include <string>
#include "Enemy.h"
class EnemyHandler
{
private:
	Enemy* *enemy;
	int nrOfEnemies;
	int cap;

	//void initiate(int from=0);
	void addEnemy(sf::Vector2f startPos);
	//void removeEnemy(int nr);

public:
	EnemyHandler();
	~EnemyHandler();
	
	void reset();
	Enemy *&getEnemies()const;
	Enemy &getEnemy(int id);
	sf::Vector2f getEnemyPosFrom(int nr)const;
	void updateEnemy(int nr, sf::RenderWindow& window, float deltaTime, sf::Vector2f playerPos ); //this->thePlayer.getPosition()
	void gotHit(int nr);
	bool checkIfAliveFrom(int nr)const;
	sf::FloatRect getEnemyGBFrom(int nr)const;

	Projectile *&getProjectiles(int enemyId);
	//Projectile getProjectileFrom(int enemyID, int nr);
  	//int getNrOfProjectilesFrom(int nr)const;
	bool checkIfNullptr(int nr);
	int getNrOfEnemies()const;
	//int getCapacity()const;
	bool checkAdd(sf::Vector2f startPos);
	void removeEnemy(int nr);
	void removeProjectile(int enemyID,int nr);
	bool checkAlive();

	ProjectileHandler getLasers(int id)const;

};
#endif 
