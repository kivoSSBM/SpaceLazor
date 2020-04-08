#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include "Debris.h"
#include "Enemy.h"
#include "Player.h"
class CollisionHandler
{
private:
	float windowX(float size);
	float windowY(float size);

	int currentDebris;
	int currentEnemy;
	int currentEnemyProjectile;
	int currentPlayerProjectile;
public:
	CollisionHandler();
	~CollisionHandler();

	int getCurrentDebris()const;
	int getCurrentEnemy()const;
	int getCurrentEnemyProjectile()const;
	int getCurrentPlayerProjectile()const;

	int checkAliveDebris(Debris *debris[], int nrOfDebris);
	int checkAliveEnemies(Enemy *enemies[], int nrOfEnemies);
	void playerBoundaries(Player & player, float deltaTime);

	bool checkCollision(Projectile *laser[], int nrOfEnemyLasers, Player & player); //enemy's projectile vs player
	bool checkCollision(Debris *debris[], int nrOfDebris, Player & player); //debris vs player
	bool checkCollision(Projectile *laser[], int nrOfLasers, Debris *debris[], int nrOfDebris); //player's projectile vs debris
	bool checkCollision(Projectile* laser[], int nrOfLasers, Enemy* enemy[], int nrOfEnemies); //player's projectile
};
#endif
