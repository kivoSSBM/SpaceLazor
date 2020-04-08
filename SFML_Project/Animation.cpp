#include "Animation.h"

Animation::Animation(std::string file,sf::Vector2f startPos, int imageCount, float switchTime)
{
	this->setPosition(sf::Vector2f(startPos.x-35,startPos.y-35));
	std::string fileName = "textures/"+ file+".png";
	theTexture.loadFromFile(fileName);
	setSize(sf::Vector2f(60, 60));
	this->imageCount = 8; //8
	this->switchTime = 0.06f;
	this->totalTime = 0.f;
	this->currentImage = 0;

	this->cycle = false;
	uvRect.width = (int)this->theTexture.getSize().x / imageCount;
	uvRect.height = this->theTexture.getSize().y;
}

Animation::~Animation()
{
}

bool Animation::getCycle() const
{
	return this->cycle;
}

void Animation::update(sf::RenderWindow & window, float deltaTime)
{
	this->totalTime += deltaTime;

	if (this->totalTime >= this->switchTime)
	{
		this->totalTime -= this->switchTime;
		this->currentImage++;
		if (currentImage >= imageCount)
		{
			this->cycle = true;
			currentImage = imageCount-1;//0;
		}
	}
	uvRect.left = currentImage * uvRect.width;
	uvRect.top = 0;
	setTextureRect(this->uvRect);
	setTexture(&theTexture);
	window.draw(*this);
}

//void Animation::updateAnime(sf::RenderWindow & window, float deltaTime)
//{
//	this->totalTime += deltaTime;
//
//	if (this->totalTime >= this->switchTime)
//	{
//		this->totalTime -= this->switchTime;
//		this->currentImage++;
//		if (currentImage >= imageCount)
//		{
//			//this->cycle = true;
//			currentImage = 0;
//		}
//	}
//	uvRect.left = currentImage * uvRect.width;
//	uvRect.top = 0;
//	setTextureRect(this->uvRect);
//	setTexture(&theTexture);
//	window.draw(*this);
//}

sf::IntRect Animation::getUvRect() const
{
	return this->uvRect;
}
