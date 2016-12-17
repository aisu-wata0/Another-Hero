// Another Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define movementRate 192.0f
#define WindowWidth 1280
#define WindowHeight 720
#define BoardSize 9
#define TileSizef WindowHeight/BoardSize


int main()
{
	// render main window
	sf::RenderWindow window(
		sf::VideoMode(WindowWidth, WindowHeight),
		"Another Hero",
		sf::Style::Close);

	// pc character
	/* TODO make a Character class,
	discrete values for position (mult by TileSize)*/
	sf::RectangleShape pc(sf::Vector2f(TileSizef, TileSizef));
	sf::Texture pcTexture;
	pcTexture.loadFromFile("Textures/PIxelantasy/Characters/Soldier/PNG/Soldier.png");
	pc.setTexture(&pcTexture);
	pc.setPosition(4 * TileSizef, 4 * TileSizef);

	sf::RectangleShape sideMenu(
		sf::Vector2f(WindowWidth - WindowHeight, WindowHeight));
	sideMenu.setFillColor(sf::Color::Color(124, 60, 0));
	sideMenu.setPosition(WindowHeight, 0.0f);

	// game loop clock
	sf::Clock clock;
	sf::Int64 elapsedTime;

	// timers
	sf::Clock movementTimer;
		
	while (window.isOpen())
	{
		// get elapsedTime since last loop
		elapsedTime = clock.restart().asMicroseconds();

		// treat events
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				// TODO Add key press events
				break;
			}

		}

		// Movement
		if (movementTimer.getElapsedTime().asMilliseconds() >= movementRate) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
				&& pc.getPosition().x < (BoardSize - 1)*TileSizef) {

				pc.move(TileSizef, 0.0f);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
				&& pc.getPosition().y < (BoardSize - 1)*TileSizef) {

				pc.move(0.0f, TileSizef);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
				&& pc.getPosition().x > 0.0f) {

				pc.move(-TileSizef, 0.0f);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
				&& pc.getPosition().y > 0.0f) {

				pc.move(0.0f, -TileSizef);
				movementTimer.restart();
			}

		}

		window.clear();

		// draw all objects
		window.draw(sideMenu);
		window.draw(pc);

		window.display();
	}

	return 0;
}
