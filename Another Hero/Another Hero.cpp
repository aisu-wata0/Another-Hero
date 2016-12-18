// Another Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stats.h"
#include "Character.h"

int main()
{

	enum GameState {
		Start, WorldMap,
		Encounter, Exiting
	};

	enum MenuState {
		Settings, Inventory,
		Party, Skills, Status
	};

	GameState game_state = Start;

	// render main window
	sf::RenderWindow window(
		sf::VideoMode(WindowWidth, WindowHeight),
		"Another Hero",
		sf::Style::Close);

	// pc character
	Character pc;

	// pc sprite
	pc.sprite.setSize(sf::Vector2f(TileSizef, TileSizef));
	sf::Texture pcTexture;
	pcTexture.loadFromFile("Textures/PIxelantasy/Characters/Soldier/PNG/Soldier.png");
	pc.sprite.setTexture(&pcTexture);
	pc.setPosition(BoardSize/2, BoardSize/2);

	// side menu
	sf::RectangleShape sideMenu(
		sf::Vector2f(WindowWidth - WindowHeight, WindowHeight));
	sideMenu.setFillColor(sf::Color::Color(124, 60, 0));
	sideMenu.setPosition(WindowHeight, 0.0f);

	// timers
	// TODO, make this a part of a pc class
	// make move method, getPosition etc. all part of it, remove it from 
	// Character class
	sf::Clock movementTimer;
		
	while (window.isOpen())
	{
		
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
		pc.sprite.getPosition();
		// PC Movement
		if (movementTimer.getElapsedTime().asMilliseconds() >= movementRate) {
			// checks W A S D and moves accordinglly, if not at border already
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
				&& pc.getPosition().x < (BoardSize - 1)) {

				pc.move(1, 0);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
				&& pc.getPosition().y < (BoardSize - 1)) {

				pc.move(0, 1);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
				&& pc.getPosition().x > 0) {

				pc.move(-1, 0);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
				&& pc.getPosition().y > 0) {

				pc.move(0, -1);
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
