#include "Player.h"

void Player::inputs(int gamepad, sf::RenderWindow & window, float deltaTime)
{
	float speed = 200.f;
	sf::Vector2f playerPosR = sf::Vector2f(getPosition().x+ 20, getPosition().y+20);
	sf::Vector2f playerPosL = sf::Vector2f(getPosition().x-20 , getPosition().y-20 );
	if (gamepad == 0) //keypad
	{
		//move
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			move(windowX(-(speed)*deltaTime), 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			move(windowX((speed)*deltaTime), 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			move(0, windowY(-(speed )*deltaTime));
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			move(0, windowY((speed)*deltaTime));
	
		//aim with mouse
		sf::Vector2i position = sf::Mouse::getPosition();
		float deltaY = getPosition().y - sf::Mouse::getPosition().y;
		float deltaX= getPosition().x- sf::Mouse::getPosition().x;
		float angleM = abs((atan(deltaY / deltaX)*(degrees)));//(180 / 3.14159265359)));

		//custom angles for mouse, its +180
		if (deltaX >= 0 && deltaY >= 0)
		{ //0 to 90
			angleM = 180 + angleM; //180 to 270
		}
		else if (deltaX <= 0 && deltaY >= 0)
		{
			angleM = 360 - angleM; //90 to 180
		}
		else if (deltaX <= 0 && deltaY <= 0)
		{
		}
		else if (deltaX >= 0 && deltaY <= 0)
		{
			angleM = 180 - angleM; //270 to 360
		}
		setRotation(angleM);
		//fire
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->isPressed == false)
		{
			lasers.fireProjectile(playerPosR,angleM);
			lasers.fireProjectile(playerPosL,angleM);
			this->isPressed = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{}
		else
		{
			this->isPressed = false;
		}
	}
	else if (gamepad > 0 && gamepad <= 8) //gamepads , 8???
	{
		float dirX = sf::Joystick::getAxisPosition(gamepad-1, sf::Joystick::PovX)*deltaTime;
		float dirY = sf::Joystick::getAxisPosition(gamepad-1, sf::Joystick::PovY)*deltaTime;
		move(windowX(2 * dirX), windowY(-2 * dirY));
		//examples for angles rightstick
		float posX = sf::Joystick::getAxisPosition(gamepad-1, sf::Joystick::U); //left =negative , right =positve
		float posY = sf::Joystick::getAxisPosition(gamepad-1, sf::Joystick::R); //up = negative, down = positive
		float angle = abs((atan(posY / posX)*(degrees)));
		if (abs(posX) < 10 && abs(posY) <10)
		{
			setRotation(this->lastAngle);
		}
		else
		{
			if (posX >= 0 && posY >= 0)
			{ //0 to 90
			}
			else if (posX <= 0 && posY >= 0)
			{
				angle = 180 - angle; //90 to 180
			}
			else if (posX <= 0 && posY <= 0)
			{
				angle = 180 + angle; //180 to 270
			}
			else if (posX >= 0 && posY <= 0)
			{
				angle = 360 - angle; //270 to 360
			}
			setRotation(angle);
			this->lastAngle = angle;
		}
		//fire
		if (sf::Joystick::isButtonPressed(gamepad-1, 5) && this->isPressed == false)
		{
			lasers.fireProjectile(playerPosR,this->lastAngle);
			lasers.fireProjectile(playerPosL,this->lastAngle);
			this->isPressed = true;
		}
		else if (sf::Joystick::isButtonPressed(gamepad-1, 5))
		{}
		else
		{
			this->isPressed = false;
		}
	}
	else if (gamepad > 8) //safe option
	{
		this->gamepad = 0;
	}
}

Player::Player(int gamepad) :Unit("player-right")
{
	setOrigin(windowX(60), windowY(60)); //center rotation
	setSize(sf::Vector2f(windowX(120),windowY(120)));
	setPosition(sf::Vector2f(windowX(960), windowY(540)));
	this->isPressed = false;
	this->gamepad = gamepad;
	this->setLives(15);
	this->lastAngle = 90.f;
}

Player::~Player(){}

int Player::getNrOfProjectiles() const
{
	return lasers.getNrOfProjectiles();
}

Projectile Player::getProjectile(int nr) const
{
	return lasers.getProjectile(nr);
}

Projectile *& Player::getProjectiles() 
{

	//std::cout<<lasers.getProjectiles()[0]->getLives()<<std::endl;
	
	return lasers.getProjectiles();
}

void Player::removeProjectile(int nr)
{
	lasers.removeProjectile(nr);
}

int Player::getPlayerLives() const
{
	return this->getLives();
}

void Player::setGamepad(int gamepad)
{
	this->gamepad = gamepad;
}

void Player::update(sf::RenderWindow & window, float deltaTime)
{
	inputs(this->gamepad, window, deltaTime);
	lasers.draw(window, deltaTime);
	window.draw(*this);
}

void Player::reset()
{
	this->setLives(15);
	lasers.reset();
	setPosition(sf::Vector2f(windowX(960), windowY(540)));
}
