#ifndef TILEMAP_H
#define TILEMAP_H
#include "Tile.h"
#include <iostream>
class TileMap
{
private:
	//std::string mapName;
	int capacity;
	int width;
	int height;
	int tileSize;
	int x;
	int y;
	Tile* *theTiles; //single pointer??

	void initiateTileCoords();
public:
	TileMap();
	~TileMap();
	
	void reset();
	void moveMap(float deltaTime);
	void update(sf::RenderWindow & window, float deltaTime);
};
#endif