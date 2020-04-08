#include "ProjectileHandler.h"

void ProjectileHandler::initiate(int from)
{
	for (int i = from;i < this->capacity;i++)
		this->projectiles[i] = nullptr;
}

float ProjectileHandler::windowX(float size)
{
	float windowX = 1920.f / size;
	return sf::VideoMode::getDesktopMode().width / windowX;
}

float ProjectileHandler::windowY(float size)
{
	float windowY = 1080.f / size;
	return sf::VideoMode::getDesktopMode().height / windowY;
}

ProjectileHandler::ProjectileHandler()
{
	this->capacity = 20; 
	this->nrOfProjectiles = 0;
	this->projectiles = new Projectile*[capacity];
	this->initiate();
}

ProjectileHandler::~ProjectileHandler()
{
	//if (this->nrOfProjectiles >= 0)
	//{
		for (int i = 0;i < this->nrOfProjectiles;i++)
			delete projectiles[i];
		delete[] projectiles;
	//}
}

void ProjectileHandler::reset()
{
	for (int i = 0;i < this->nrOfProjectiles;i++)
		delete projectiles[i];
	this->nrOfProjectiles = 0;
	initiate(0);
}

Projectile ProjectileHandler::getProjectile(int nr) const
{
	return *this->projectiles[nr];
}

void ProjectileHandler::removeProjectile(int nr)
{
	delete projectiles[nr];
	this->projectiles[nr] = this->projectiles[--nrOfProjectiles];
	this->projectiles[nrOfProjectiles] = nullptr;
}

int ProjectileHandler::getNrOfProjectiles() const
{
	return this->nrOfProjectiles;
}

int ProjectileHandler::getCapacity() const
{
	return this->capacity;
}

void ProjectileHandler::fireProjectile(sf::Vector2f startPos, float facingDir)
{
	if (nrOfProjectiles < capacity)
	{
		this->projectiles[nrOfProjectiles++] = new Projectile(startPos, facingDir);
	}
}

void ProjectileHandler::draw(sf::RenderWindow & window, float deltaTime)
{
	//std::cout << "nrOf " << nrOfProjectiles << std::endl;
	for (int i = 0;i < nrOfProjectiles;i++)
	{
		if (this->projectiles[i]->getPosition().x > windowX(-40) && this->projectiles[i]->getPosition().x < windowX(1530) &&
			this->projectiles[i]->getPosition().y>windowY(-40) && this->projectiles[i]->getPosition().y < windowY(1080))
		{
			window.draw(*this->projectiles[i]);
		}
		this->projectiles[i]->update(window,deltaTime);
		if (projectiles[i] != nullptr)
		{
			if (this->projectiles[i]->getPosition().y > windowY(1080) || this->projectiles[i]->getPosition().y < windowY(-30) || 
				this->projectiles[i]->getPosition().x > windowX(1920)|| this->projectiles[i]->getPosition().x < windowX(-200) )  //1080 *1920 - stuff is still behind hud
			{
				delete projectiles[i];
				this->projectiles[i] = this->projectiles[--nrOfProjectiles];
				this->projectiles[nrOfProjectiles] = nullptr;
			}
		}
	}
}

Projectile *& ProjectileHandler::getProjectiles()
{
	//for (int i = 0; i < nrOfProjectiles;i++)
	//{
	//	projectiles[i]->getLives();
	//}

	return *projectiles;
}

Projectile& ProjectileHandler::operator[]( int nr)const
{
	return *projectiles[nr];
}

ProjectileHandler& ProjectileHandler::getLasers() 
{
	return *this;
}
