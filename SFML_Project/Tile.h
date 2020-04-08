#ifndef TILE_H
#define TILE_H
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
class Tile :public sf::RectangleShape
{
private:
	sf::Texture tileTx;
	std::string tileId;

public:
	Tile(std::string tileId );
	virtual~Tile();
	void loadTexture(int id);
};
#endif