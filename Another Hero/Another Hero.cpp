// Another Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stats.h"
#include "Character.h"

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
	/* TODO make class have
	discrete values for position (mult by TileSize)*/
	Character pc;
	pc.sprite.setSize(sf::Vector2f(TileSizef, TileSizef));
	sf::Texture pcTexture;
	pcTexture.loadFromFile("Textures/PIxelantasy/Characters/Soldier/PNG/Soldier.png");
	pc.sprite.setTexture(&pcTexture);
	pc.sprite.setPosition(4 * TileSizef, 4 * TileSizef);

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
		
		// PC Movement
		if (movementTimer.getElapsedTime().asMilliseconds() >= movementRate) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
				&& pc.sprite.getPosition().x < (BoardSize - 1)*TileSizef) {

				pc.sprite.move(TileSizef, 0.0f);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
				&& pc.sprite.getPosition().y < (BoardSize - 1)*TileSizef) {

				pc.sprite.move(0.0f, TileSizef);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
				&& pc.sprite.getPosition().x > 0.0f) {

				pc.sprite.move(-TileSizef, 0.0f);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
				&& pc.sprite.getPosition().y > 0.0f) {

				pc.sprite.move(0.0f, -TileSizef);
				movementTimer.restart();
			}

		}

		window.clear();

		// draw all objects
		window.draw(sideMenu);
		window.draw(pc.sprite);

		window.display();
	}

	return 0;
}
