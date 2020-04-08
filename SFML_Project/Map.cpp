#include "Map.h"

void TileMap::initiateTileCoords()
{
	for (int i = 0;i < this->capacity;i++)
	{
		theTiles[i] = new Tile(" ");
		theTiles[i]->setPosition(sf::Vector2f((float)this->x,(float)this->y));
		this->x += this->tileSize;
		if (this->x == (width*tileSize))
		{
			this->x = 0;
			this->y += this->tileSize;
		}
	}
}

TileMap::TileMap()
{
	this->width = 27; //27 //32
	this->height = 19;
	this->capacity = this->width*this->height; //513;
	this->tileSize = 60;
	this->x = 0;
	this->y = 0;
	this->theTiles = new Tile*[this->capacity];
	this->initiateTileCoords();
}

TileMap::~TileMap()
{
	for (int i = 0;i < this->capacity;i++)
	{
		delete theTiles[i];
	}
	delete[]theTiles;
}


void TileMap::reset()
{
	this->x = 0;
	this->y = 0;
	for (int i = 0;i < this->capacity;i++)
	{
		delete theTiles[i];
	}
	this->initiateTileCoords();
	
	//this->theTiles = new Tile*[this->capacity];
}

void TileMap::moveMap(float deltaTime)
{
	//float deltaTime = time.asSeconds();
	int randNr = 0;
	int tileNr = 0;
	for (int i = 0;i < capacity;i++)
	{
		theTiles[i]->move(0, -100*deltaTime);
		if (theTiles[i]->getPosition().y <= -30)
		{
			theTiles[i]->move(0.f, 1140.f);
			randNr = rand() % 100 + 0; //random percent
			if (randNr >= 0 && randNr < 50) //50% 
				tileNr = 0;
			else if (randNr >= 50 && randNr < 59) //9%
				tileNr = 1;
			else if (randNr >= 59 && randNr < 68) //9%	
				tileNr = 2;
			else if (randNr >= 68 && randNr < 69) //1%
				tileNr = 3;
			else if (randNr >= 69 && randNr < 71) //2%
				tileNr = 4;
			else if (randNr >= 71 && randNr < 80) //9%
				tileNr = 5;
			else if (randNr >= 80 && randNr < 88) //8%
				tileNr = 6;
			else if (randNr >= 88 && randNr < 92) //4%
				tileNr = 7;
			else if (randNr >= 92 && randNr <= 100) //8%
				tileNr = 8;
			theTiles[i]->loadTexture(tileNr);
		}
	}
}

void TileMap::update(sf::RenderWindow & window, float deltaTime)
{
	moveMap(deltaTime);
	for (int i = 0;i < capacity;i++)
	{
		window.draw(*theTiles[i]);
	}
}
