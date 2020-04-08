#include "CollisionHandler.h"

float CollisionHandler::windowX(float size)
{
	float windowX = 1920.f / size;
	return sf::VideoMode::getDesktopMode().width / windowX;
}

float CollisionHandler::windowY(float size)
{
	float windowY = 1080.f / size;
	return sf::VideoMode::getDesktopMode().height / windowY;
}

CollisionHandler::CollisionHandler()
{
	this->currentDebris = -1;
	this->currentEnemy = -1;
	this->currentEnemyProjectile = -1;
	this->currentPlayerProjectile = -1;
}

CollisionHandler::~CollisionHandler(){}

int CollisionHandler::getCurrentDebris() const
{
	return currentDebris;
}

int CollisionHandler::getCurrentEnemy() const
{
	return currentEnemy;
}

int CollisionHandler::getCurrentEnemyProjectile() const
{
	return currentEnemyProjectile;
}

int CollisionHandler::getCurrentPlayerProjectile() const
{
	return currentPlayerProjectile;
}

//void CollisionHandler::collision(sf::RenderWindow & window, float deltaTime)
//{


//	int x = rand() % 1510 + 410;
//	int y = rand() % 2500 + 1300;
//	sf::Vector2f startPos = sf::Vector2f(windowX(x), windowY(y));
//

	//check alive
	//for (int i = 0;i < this->theDebris.getNrOfRocks();i++)
	//{
	//	if (this->theDebris.getRock(i).isAlive() == false)
	//	{
	//		this->theDebris.removeRock(i);
	//		this->score = this->score + 30;
	//	}
	//}
	//for (int i = 0;i < this->theEnemies.getNrOfEnemies();i++) 
	//{
	//	if (this->theEnemies.checkIfAliveFrom(i) == false) 
	//	{
	//		this->theEnemies.removeEnemy(i);
	//		this->score = this->score + 40;
	//	}
	//}

	//player
	//for (int i = 0;i < this->theDebris.getNrOfRocks();i++)
	//{
	//	for (int j = 0;j < thePlayer.getNrOfProjectiles();j++)
	//	{
	//		if (this->thePlayer.getProjectile(j).getGlobalBounds().intersects(this->theDebris.getRock(i).getGlobalBounds()))
	//		{
	//			this->thePlayer.removeProjectile(j);
	//			this->theDebris.gotHit(i);
	//			this->score = this->score + 10;
	//			this->theDebris.getRock(i).setBounce(); //bounce??
	//			this->runAnimation(this->theDebris.getRock(i).getPosition());
	//		}
	//	}
	//}
 //  	for (int i = 0;i < this->theEnemies.getNrOfEnemies();i++)
	//{
	//	for (int j = 0;j < thePlayer.getNrOfProjectiles();j++)
	//	{
 //			if (this->thePlayer.getProjectile(j).getGlobalBounds().intersects(this->theEnemies.getEnemyGBFrom(i)))
	//		{
	//			this->thePlayer.removeProjectile(j);
	//			this->theEnemies.gotHit(i); //
	//			this->score = this->score + 10;
	//			this->runAnimation(this->theEnemies.getEnemyPosFrom(i));
	//		}
	//	}
	//}

	//player boundaries
	//if (this->thePlayer.getPosition().x <= windowX(70))
	//	this->thePlayer.move(windowX(200 * deltaTime), 0);
	//else if (this->thePlayer.getPosition().x >= windowX(1530))
	//	this->thePlayer.move(windowX(-200 * deltaTime), 0);
	//if (this->thePlayer.getPosition().y <= windowY(70))
	//	this->thePlayer.move(0, windowY(200 * deltaTime));
	//else if (this->thePlayer.getPosition().y >= windowY(1010))
	//	this->thePlayer.move(0, windowY(-200 * deltaTime));

	//debris
	//for (int i = 0;i < this->theDebris.getNrOfRocks();i++)
	//{
	//	if (this->thePlayer.getGlobalBounds().intersects(theDebris.getRock(i).getGlobalBounds()))
	//	{
	//		this->runAnimation(this->theDebris.getRock(i).getPosition());
	//		this->theDebris.removeRock(i);
	//		this->thePlayer.loseLife();
	//	}
	//}
	//enemy
	//for (int i = 0;i < this->theEnemies.getNrOfEnemies();i++)
	//{
	//	for (int j = 0;j < this->theEnemies.getNrOfProjectilesFrom(i);j++)
	//	{
	//		if (this->thePlayer.getGlobalBounds().intersects(this->theEnemies.getProjectileFrom(i,j).getGlobalBounds()))
	//		{
	//			this->runAnimation(this->theEnemies.getEnemyPosFrom(i));
	//			this->theEnemies.removeProjectile(i,j);
	//			this->thePlayer.loseLife();
	//		}
	//	}
	//}

	//spawn
	//if(this->theDebris.checkAdd(startPos)==true);
	//if(this->theEnemies.checkAdd(startPos)==true);
	////boundaries
	//for (int i = 0;i < this->theDebris.getNrOfRocks();i++)
	//{
	//	this->theDebris.updateRock(i, window, deltaTime);
	//	if(this->theDebris.checkIfNullptr(i)==false)  
	//	{
	//		if (this->theDebris.getRock(i).getPosition().y < windowY(-30) || this->theDebris.getRock(i).getPosition().x < windowX(-200) || this->theDebris.getRock(i).getPosition().x > windowX(1730))
	//		{
	//			this->theDebris.removeRock(i);
	//		}
	//	}
	//}
	//for (int i = 0;i < this->theEnemies.getNrOfEnemies();i++) //
	//{
	//	this->theEnemies.updateEnemy(i, window, deltaTime, thePlayer.getPosition());
	//	if (this->theEnemies.checkIfNullptr(i) == false) 
	//	{
	//		if (this->theEnemies.getEnemyPosFrom(i).y < windowY(-30) || this->theEnemies.getEnemyPosFrom(i).x < windowX(-200)|| this->theEnemies.getEnemyPosFrom(i).x > windowX(1730))
	//		{
	//			this->theEnemies.removeEnemy(i);
	//		}
	//	}
	//}

	//animation
	//for (int h = 0;h < this->nrOfHits;h++)
	//{
	//	if (this->laserHit[h]->getCycle() == true) //need check if bool is correct
	//	{
	//		this->removeAnimation(h);
	//	}
	//	else
	//		this->laserHit[h]->update(window, deltaTime);
	//}
//}

int CollisionHandler::checkAliveDebris(Debris *debris[], int nrOfDebris)
{
	int id = -1;
	for (int i = 0;i < nrOfDebris && id == -1;i++)  //&& id ==-1
	{
		if (debris[i]->isAlive() == false)
		{
			id = i;
			
		}
	}
	return id;
}

int CollisionHandler::checkAliveEnemies(Enemy *enemies[], int nrOfEnemies)
{
	int id = -1;
	for (int i = 0;i < nrOfEnemies && id == -1;i++)
	{
		if (enemies[i]->isAlive() == false)
		{
			id = i;
		}
	}
	return id;
}

void CollisionHandler::playerBoundaries(Player & player, float deltaTime) //not implemented
{
	if (player.getPosition().x <= windowX(70))
		player.move(windowX(200 * deltaTime), 0);
	else if (player.getPosition().x >= windowX(1530))
		player.move(windowX(-200 * deltaTime), 0);
	if (player.getPosition().y <= windowY(70))
		player.move(0, windowY(200 * deltaTime));
	else if (player.getPosition().y >= windowY(1010))
		player.move(0, windowY(-200 * deltaTime));
}

bool CollisionHandler::checkCollision(Projectile * laser[], int nrOfEnemyLasers, Player & player) //here
{
	bool gotHit = false;
	for (int j = 0;j < nrOfEnemyLasers;j++)
	{
		if (&laser[j] != nullptr)
		{
			//std::cout <<"player lives: "<< player.getLives() << std::endl;
			//std::cout << "player lasers lives: " << player.getProjectiles()[0].getLives();
			//std::cout <<"enemy laser lives: "<< laser[j].getLives() << std::endl;
			if (player.getGlobalBounds().intersects(laser[j]->getGlobalBounds())) 
			{
				gotHit = true;
				this->currentEnemyProjectile = j;
			}
		}
	}
	return gotHit;
}

bool CollisionHandler::checkCollision(Debris *debris[], int nrOfDebris, Player& player) //here
{
	bool gotHit = false;
	for (int i = 0;i < nrOfDebris;i++)
	{
		if (&debris[i] != nullptr)
		{
			if (player.getGlobalBounds().intersects(debris[i]->getGlobalBounds()))
			{
				gotHit = true;
				this->currentDebris = i;
			}
		}
	}
	return gotHit;
}

bool CollisionHandler::checkCollision(Projectile *laser[], int nrOfLasers, Debris *debris[], int nrOfDebris)
{ //player's projectiles vs debris
	bool gotHit = false;
	for (int i = 0;i < nrOfDebris;i++)
	{
		for (int j = 0;j < nrOfLasers;j++)
		{
			if (&laser[j] != nullptr && &debris[i]!=nullptr)
			{
				if (laser[j]->getGlobalBounds().intersects(debris[i]->getGlobalBounds()))
				{
					gotHit = true;
					this->currentPlayerProjectile = j;
					this->currentDebris = i;
				}
			}
		}
	}
	return gotHit; //also need to return i & j
}

bool CollisionHandler::checkCollision(Projectile *laser[], int nrOfLasers, Enemy *enemy[], int nrOfEnemies)
{
	bool gotHit = false;
	for (int i = 0;i < nrOfEnemies;i++)
	{
		for (int j = 0;j < nrOfLasers;j++)
		{
			if (&laser[j] != nullptr && &enemy[i] != nullptr)
			{
				if (laser[j]->getGlobalBounds().intersects(enemy[i]->getGlobalBounds()))
				{
					gotHit = true;
					this->currentPlayerProjectile = j;
					this->currentEnemy = i;
				}
			}
		}
	}
	return gotHit;
}
