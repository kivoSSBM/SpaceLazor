#include "GameHandler.h"

void GameHandler::runAnimation(sf::Vector2f startPos)
{
	laserHit[this->nrOfHits++] = new Animation("Explosion", startPos, 8, 0.06f);
}

void GameHandler::removeAnimation(int nr)
{
		delete laserHit[nr];
		if (this->laserHit[nrOfHits - 1] != nullptr)
			this->laserHit[nr] = this->laserHit[--nrOfHits];
		this->laserHit[nrOfHits] = nullptr;
}

void GameHandler::spawn()
{
	int x = rand() % 1510 + 410;
	int y = rand() % 2500 + 1300;
	sf::Vector2f startPos = sf::Vector2f(windowX((float)x), windowY((float)y));
	this->theDebris.checkAdd(startPos);
	this->theEnemies.checkAdd(startPos);

	for (int i = 0;i < this->theDebris.getNrOfRocks();i++)
	{
		this->theDebris.updateRock(i, window, deltaTime);
		if(this->theDebris.checkIfNullptr(i)==false)  
		{
			if (this->theDebris.getRock(i).getPosition().y < windowY(-30) || this->theDebris.getRock(i).getPosition().x < windowX(-200) || this->theDebris.getRock(i).getPosition().x > windowX(1730))
			{
				this->theDebris.removeRock(i);
			}
		}
	}
	for (int i = 0;i < this->theEnemies.getNrOfEnemies();i++) //
	{
		this->theEnemies.updateEnemy(i, window, deltaTime, thePlayer.getPosition());
		if (this->theEnemies.checkIfNullptr(i) == false) 
		{
			if (this->theEnemies.getEnemyPosFrom(i).y < windowY(-30) || this->theEnemies.getEnemyPosFrom(i).x < windowX(-200)|| this->theEnemies.getEnemyPosFrom(i).x > windowX(1730))
			{
				this->theEnemies.removeEnemy(i);
			}
		}
	}

	for (int h = 0;h < this->nrOfHits;h++)
	{
		if (this->laserHit[h]->getCycle() == true) //
		{
			this->removeAnimation(h);
		}
		else
			this->laserHit[h]->update(window, deltaTime);
	}
}

void GameHandler::setHighScore()
{
	int theScore;
	std::ifstream fromFile;
	fromFile.open("files/highScore.txt");
	fromFile >> theScore;
	if (this->score > theScore)
	{
		this->highScore = this->score;
		std::ofstream toFile;
		toFile.open("files/highScore.txt");
		toFile << this->score;
		toFile.close();
	}
	else
		this->highScore = theScore;
	fromFile.close();
	this->highScoreText->setString("Highscore: "+std::to_string(this->highScore));
	this->highScoreText->setPosition(sf::Vector2f(windowX(820), windowY( 200)));
}

void GameHandler::theHud() 
{
	this->hud[1]->setString("Lives: "+ std::to_string(this->thePlayer.getPlayerLives()));
	this->hud[2]->setString("Score: " + std::to_string(this->score));
 	this->hud[3]->setString("Distance Traveled: " + std::to_string(this->lightYears) + " ly");
	this->lightYears += 0.00001*deltaTime;
	for(int i = 0;i < 4;i++)
	{
		this->window.draw(*hud[i]);
	}
}

void GameHandler::resetGame()
{
	this->score = 0;
	this->lightYears = 0;
	this->thePlayer.reset();
	this->theDebris.reset();
	this->theEnemies.reset();

	//this->theCollision.reset(); //nothing to reset in collision
	map.reset();  
}

float GameHandler::windowX(float size)
{
	float windowX = 1920.f / size;
	return sf::VideoMode::getDesktopMode().width / windowX;
}

float GameHandler::windowY(float size)
{
	float windowY = 1080.f / size;
	return sf::VideoMode::getDesktopMode().height/windowY;
}

GameHandler::GameHandler()
{
	this->window.setFramerateLimit(60);
	window.create(sf::VideoMode::getDesktopMode(), "Za Warudo!!", sf::Style::Fullscreen);
	this->deltaTime = 0;
	//this->fullscreen = true; //no need
	this->gameMode = 0;

	this->laserCap = 20;
	this->nrOfHits = 0;
	this->laserHit = new Animation*[laserCap];
	for (int i = 0;i < laserCap;i++)
		this->laserHit[i] = nullptr;

	this->score = 0;
	this->theFont.loadFromFile("Font/PressStart2p.ttf");
	this->highScoreText = new sf::Text("Highscore: " , theFont, (int)windowY(35.f));
	this->setHighScore();
	this->hud = new sf::Text*[4]; 
	for (int i = 0;i < 4;i++)
		this->hud[i] = nullptr;
	this->hud[0] = new sf::Text("Player 1 ", theFont, (int)windowY(20.f));
	this->hud[0]->setPosition(sf::Vector2f(windowX(1700.f), windowY(100.f)));
	this->hud[1] = new sf::Text("Lives:  ", theFont, 13);
	this->hud[1]->setPosition(sf::Vector2f(windowX(1610.f), windowY(150.f)));
	this->hud[2] = new sf::Text("Score: ", theFont, (int)windowY(13.f));
	this->hud[2]->setPosition(sf::Vector2f(windowX(1610.f), windowY(200.f)));
	this->hud[3] = new sf::Text("Distance Traveled: 0.000000000 ly ", theFont, (int)windowY(10.f));
	this->hud[3]->setPosition(sf::Vector2f(windowX(1610.f), windowY(250.f)));

	this->lightYears = 0.00000000;
	this->bolero.openFromFile("Audio/Bolero.ogg");
}

GameHandler::~GameHandler()
{
	for (int i = 0; i < 4;i++)
		delete hud[i];
	delete[] hud;
	delete highScoreText;

	for (int i = 0; i < laserCap;i++)
		delete laserHit[i];
	delete[] laserHit;
}

void GameHandler::drawStartMenu()
{
	main.menu(window);
	this->window.draw(*this->highScoreText);
}

void GameHandler::drawAll() //update
{
	if(bolero.getStatus()!=bolero.Playing)
		this->bolero.play();
	this->map.update(this->window, this->deltaTime);
	this->thePlayer.update(window, deltaTime);
	this->spawn();
	//1
	//std::cout<<"nr Of enemies: "<<theEnemies.getNrOfEnemies() << std::endl;
	for (int e = 0;e < theEnemies.getNrOfEnemies();e++) //here, loops all enemies
	{
		if (&theEnemies.getEnemy(e) != nullptr)
		{
			//std::cout << "lives from " << e << ": " << theEnemies.getEnemy(e).getProjectiles().getLives() << std::endl;

			if (theCollision.checkCollision(&theEnemies.getProjectiles(e), theEnemies.getEnemy(e).getNrOfProjectiles(), thePlayer) == true) //&theEnemies.getEnemy(e).getProjectiles(),
			{
				this->runAnimation(this->theEnemies.getEnemyPosFrom(e));
				this->theEnemies.removeProjectile(e, theCollision.getCurrentEnemyProjectile()); //
				this->thePlayer.loseLife();
			}
		}
	}
	//2
	if (this->theCollision.checkCollision(&theDebris.getRocks(), theDebris.getNrOfRocks(), thePlayer) == true)
	{
		this->runAnimation(this->theDebris.getRock(theCollision.getCurrentDebris()).getPosition()); 
		this->theDebris.removeRock(theCollision.getCurrentDebris()); 
		this->thePlayer.loseLife();
	}
	//3
	//std::cout<<theDebris.getRock
	if (theCollision.checkCollision(&thePlayer.getProjectiles(), thePlayer.getNrOfProjectiles(),&theDebris.getRocks(),theDebris.getNrOfRocks())==true)
	{
		this->thePlayer.removeProjectile(theCollision.getCurrentPlayerProjectile()); 
		this->theDebris.gotHit(theCollision.getCurrentDebris());  
		this->score = this->score + 10;
		this->theDebris.getRock(theCollision.getCurrentDebris()).setBounce(); 
		this->runAnimation(this->theDebris.getRock(theCollision.getCurrentDebris()).getPosition()); 
	}
	//4
	if (theCollision.checkCollision(&thePlayer.getProjectiles(), thePlayer.getNrOfProjectiles(),&theEnemies.getEnemies(), theEnemies.getNrOfEnemies())==true)
	{
		this->thePlayer.removeProjectile(theCollision.getCurrentPlayerProjectile()); 
		this->theEnemies.gotHit(theCollision.getCurrentEnemy()); 
		this->score = this->score + 10;
		this->runAnimation(this->theEnemies.getEnemyPosFrom(theCollision.getCurrentEnemy())); 
	}
	this->theHud();
	if (theCollision.checkAliveDebris(&theDebris.getRocks(), theDebris.getNrOfRocks()) != -1)
	{
		theDebris.removeRock(theCollision.checkAliveDebris(&theDebris.getRocks(), theDebris.getNrOfRocks()));
	}
	if (theCollision.checkAliveEnemies(&theEnemies.getEnemies(), theEnemies.getNrOfEnemies()) != -1)
	{
		theEnemies.removeEnemy(theCollision.checkAliveEnemies(&theEnemies.getEnemies(), theEnemies.getNrOfEnemies()));
	}
}

void GameHandler::update() //run
{
	while (window.isOpen())
	{
		this->deltaTime = clock.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		while (window.pollEvent(this->theEvent))
		{
			if (this->theEvent.type == sf::Event::Closed)
				window.close();
		}

		if (main.getMenuStatus() == true)
		{
			//start mode - draw intro
			this->bolero.stop();
			this->window.clear();
			this->drawStartMenu();
			this->thePlayer.setGamepad(main.getGamepad());
			this->window.display();
		}
		if (main.getMenuStatus() == false)
		{
			//game mode
			this->window.clear();
			this->drawAll();
			this->window.display();
		}
		if (this->thePlayer.getPlayerLives() <= 0) 
		{
			this->bolero.setVolume(40);
			setHighScore();
			main.goToMenu();
			main.gameOverScreen(this->window, this->highScore, this->score, this->lightYears); //fix score
			resetGame();
		}
	}
}

int GameHandler::getScore() const
{
	return this->score;
}
