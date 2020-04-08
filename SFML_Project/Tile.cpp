#include "Tile.h"

Tile::Tile(std::string tileId)
{
	tileTx.loadFromFile("textures/space0.png");
	setTexture(&tileTx);
	setSize(sf::Vector2f(60,60));
}

void Tile::loadTexture(int id)
{
	std::string fileName = "textures/space" + std::to_string(id) + ".png";
	tileTx.loadFromFile(fileName);
	setTexture(&tileTx);
}

Tile::~Tile(){}
