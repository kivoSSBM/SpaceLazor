#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML\Graphics.hpp>
#include <string>
class Animation: public sf::RectangleShape
{
private:
	sf::Texture theTexture;
	int imageCount;
	int currentImage; 
	bool cycle;
	float totalTime;
	float switchTime;
	sf::IntRect uvRect;
public:
	Animation(std::string fileName,sf::Vector2f startPos,int imageCount, float switchTime);
	~Animation();
	bool getCycle()const;
	void update(sf::RenderWindow & window, float deltaTime); //one loop
//	void updateAnime(sf::RenderWindow & window, float deltaTime); //loops animation
	sf::IntRect getUvRect()const; 
};
#endif // !Explosion
