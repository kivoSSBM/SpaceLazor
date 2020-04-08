#include "Options.h"

void Options::updateController()
{
	for (int i = 0; i < 8;i++)
	{
		if (sf::Joystick::isConnected(i))
			this->controllers[i + 1].setTexture(&controllersTx[2]);
		else
			this->controllers[i + 1].setTexture(&controllersTx[1]);
	}
}

void Options::setMarkerPos()
{
	float xpos = 200.f;
	float ypos = 400.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isPressed == false)
		{
			this->currentOption++;
			this->isPressed = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isPressed == false)
		{
			this->currentOption--;
			this->isPressed = true;
		}
	}
	else
		this->isPressed = false;
	if (menuMode == 0)
	{
		if (this->currentOption > 3)
			this->currentOption = 3;
		else if (this->currentOption < 0)
			this->currentOption = 0;
		ypos = 400.f + (currentOption) * 40.f;
		marker.setPosition(xpos, ypos);
	}
	else if (menuMode == 1)
	{
		if (this->currentOption > 9)
			this->currentOption = 9;
		else if (this->currentOption < 0.f)
			this->currentOption = 0;
		if (this->currentOption == 0)
		{
			xpos = 130.f;
			ypos = 230.f;
		}
		else if (this->currentOption >= 1.f && this->currentOption < 9.f)
		{
			xpos = 100.f+ ((float)currentOption * 120.f);
			ypos = 500.f;
		}
		else if (this->currentOption==9)
		{
			xpos = 150.f;
			ypos = 950.f;
		}
	
		marker.setPosition(windowX(xpos), windowY(ypos));
	}
}

void Options::loadingScreen()
{
	sf::Clock timer;
	while (timer.getElapsedTime().asSeconds() <= 0.5)
	{
		//loading screen - fix the option bugg 
	}
}

float Options::windowX(float size)
{
	float windowX = 1920.f / size;
	return sf::VideoMode::getDesktopMode().width / windowX;
}

float Options::windowY(float size)
{
	float windowY = 1080.f / size;
	return sf::VideoMode::getDesktopMode().height / windowY;
}

Options::Options()
{
	this->deltaTime = 0;
	float textStartPos = windowX(400);
	float rowSize = 400;

	this->nrOfOptions = 10;
	this->currentOption = 0;
	this->isPressed = false;
	this->inMenu = true;
	this->menuMode = 0;
	this->gamepad = 0;

	this->theFont.loadFromFile("Font/pressstart2p.ttf");
	this->text = new sf::Text*[nrOfOptions];
	for (int i = 0;i < this->nrOfOptions;i++)
		this->text[i] = nullptr;
	//placement
	this->marker.setRadius(windowY(20));
	this->marker.setPosition(sf::Vector2f(windowX(200.f), windowY(400.f)));
	this->controllersTx[0].loadFromFile("textures/keyboard.png");
	this->controllersTx[1].loadFromFile("textures/red.png");
	this->controllersTx[2].loadFromFile("textures/green.png");

	//main menu
	this->text[0] = new sf::Text("Space Lazor",theFont, (int)windowY(70.f));
	this->text[0]->setPosition(sf::Vector2f(windowX(620.f), windowY(60.f))); //x620 y60

	this->text[1] = new sf::Text("Start ", theFont, (int)windowY(35.f)); //35
	this->text[1]->setPosition(sf::Vector2f(textStartPos, windowY(rowSize)));

	this->text[2] = new sf::Text("Multiplayer [in progress]", theFont, (int)windowY(35.f)); //35
	this->text[2]->setPosition(sf::Vector2f(textStartPos, windowY(rowSize+40)));

	this->text[3] = new sf::Text("Options", theFont, (int)windowY(35.f)); //35
	this->text[3]->setPosition(sf::Vector2f(textStartPos, windowY(rowSize+80)));

	this->text[4] = new sf::Text("Exit", theFont, (int)windowY(35.f)); //35
	this->text[4]->setPosition(sf::Vector2f(textStartPos, windowY(rowSize+120)));

	//Controller Settings
	this->text[5] = new sf::Text("Controller Settings", theFont, (int)windowY(60.f)); //60
	this->text[5]->setPosition(sf::Vector2f(windowX(420.f), windowY(60.f)));

	this->text[6] = new sf::Text("Keyboard", theFont, (int)windowY(20.f));
	this->text[6]->setPosition(sf::Vector2f(windowX(200.f),windowY(230.f)));

	this->controllers[0].setPosition(sf::Vector2f(windowX(400.f), windowY(220.f)));
	this->controllers[0].setSize(sf::Vector2f(windowX(90.f), windowY(80.f)));
	this->controllers[0].setTexture(&controllersTx[0]);

	this->text[7] = new sf::Text("Gamepads", theFont, (int)windowY(20.f));
	this->text[7]->setPosition(sf::Vector2f(windowX(200.f), windowY(350.f)));

	int imgSpace = (int)windowX(100.f);
	for (int i = 0;i < 8;i++)
	{
		this->controllers[i + 1].setPosition(sf::Vector2f(windowX(100.f) + imgSpace, windowY(420.f)));
		this->controllers[i + 1].setSize(sf::Vector2f(windowX(90.f), windowY(80.f)));
		this->controllers[i + 1].setTexture(&controllersTx[1]);
		imgSpace = imgSpace + (int)windowX(120);
	}

	//Sound settings here?

	this->text[8] = new sf::Text("Test your controller!", theFont, (int)windowY(36));
	this->text[8]->setPosition(sf::Vector2f(windowX(640.f), windowY(620.f)));

	this->text[9] = new sf::Text("Return", theFont, (int)windowY(36));
	this->text[9]->setPosition(sf::Vector2f(windowX(200.f), windowY(950.f)));

	//testGround
	this->testGround.setFillColor(sf::Color::White);
	this->testGround.setSize(sf::Vector2f(windowX(720.f), windowY(370.f)));
	this->testGround.setPosition(sf::Vector2f(windowX(650.f), windowY(700.f)));
	this->testPlayer.setScale(0.5,0.5);
	this->testPlayer.setPosition(windowX(1020.f), windowY(885.f)); //

	//gameOver
	this->gameOver = new sf::Text[4];
	this->gameOver[0] = sf::Text("Game Over!", theFont, (int)windowY(70.f));
	this->gameOver[0].setPosition(sf::Vector2f(windowX(700), windowY(350.f)));
	this->gameOver[1] = sf::Text("HighScore: ", theFont, (int)windowY(25.f));
	this->gameOver[1].setPosition(sf::Vector2f(windowX(620.f), windowY(480.f)));
	this->gameOver[2] = sf::Text("Score: ", theFont, (int)windowY(25.f));
	this->gameOver[2].setPosition(sf::Vector2f(windowX(620.f), windowY(530.f)));
	this->gameOver[3] = sf::Text("Traveled  ", theFont, (int)windowY(30.f));
	this->gameOver[3].setPosition(sf::Vector2f(windowX(620.f), windowY(650.f)));
}

Options::~Options()
{
	for (int i = 0; i < nrOfOptions;i++)
	{
		delete text[i];
	}
	delete[] text;
	delete[] gameOver;
}

void Options::goToMenu()
{
	this->inMenu = true;
}

bool Options::getMenuStatus() const
{
	return this->inMenu;
}
 
void Options::menu(sf::RenderWindow & window) //decides menu
{
	if (this->menuMode == 0) 
	{
		this->mainMenu(window);
	}
	else if (this->menuMode == 1)
	{
		this->controllerMenu(window);
	}
}

void Options::mainMenu(sf::RenderWindow & window)
{

	setMarkerPos();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && currentOption == 0)
	{
		this->loadingScreen();
		inMenu = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && currentOption == 1)
	{
		//multiplayer???
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && currentOption == 2)
	{
		this->menuMode = 1;
		this->currentOption = 0;
		this->loadingScreen();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && currentOption == 3)
	{
		window.close();
	}
	window.draw(marker);
	for (int i = 0;i < 5;i++)
	{
		//std::cout << "text id: " << i << std::endl;
		window.draw(*text[i]);
	}
}

void Options::controllerMenu(sf::RenderWindow & window)
{
	this->deltaTime = clock.restart().asSeconds();
	updateController();
	setMarkerPos();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && currentOption == 0)
	{
		this->gamepad = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && (currentOption >= 1 && currentOption <= 8))
	{
		this->gamepad = currentOption;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inMenu == true && currentOption == 9)
	{
		loadingScreen();
		this->menuMode = 0;
		this->currentOption = 0;
	}
	
	window.draw(testGround);
	window.draw(marker);
	for (int i = 5;i < 10;i++)
	{
		window.draw(*text[i]);
	}
	for (int i = 0;i < 9;i++)
	{
		window.draw(controllers[i]);
	}
 	this->testPlayer.update(window, this->deltaTime);
	this->testPlayer.setGamepad(this->gamepad);
	if (testPlayer.getPosition().x <= windowX(680))
	{
		testPlayer.move(windowX(200 * this->deltaTime), 0);
	}
	else if (testPlayer.getPosition().x >= windowX(1340))
	{
		testPlayer.move(windowX(-200 * this->deltaTime), 0);
	}
	if (testPlayer.getPosition().y <= windowY(730))
	{
		testPlayer.move(0, windowY(200 * this->deltaTime));
	}
	else if (testPlayer.getPosition().y >= windowY(1040))
	{
		testPlayer.move(0, windowY(-200 * this->deltaTime));
	}
}

void Options::gameOverScreen(sf::RenderWindow & window, int highScore,int score, double lightYears)
{
	bool enter = false;
	double counter = 0.000001;
	if (score >= highScore)
	{
		//play sound
		gameOver[1].setString("Highscore:  " + std::to_string(highScore) + "  <-- [NEW RECORD!!]");
	}
	else
		gameOver[1].setString("Highscore:  " + std::to_string(highScore));
	gameOver[2].setString("Score:      " + std::to_string(score));
	while (enter == false)
	{
		gameOver[3].setString("Traveled " + std::to_string(counter) + " Light-Years");
		if (counter < lightYears)
		{
			counter += 0.000001;
		}
		window.clear();
		for (int i = 0;i < 4;i++)
		{
			window.draw(gameOver[i]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			enter = true;
		}
		window.display();
	}
}

int Options::getGamepad() const
{
	return this->gamepad;
}