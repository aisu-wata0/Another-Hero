// Another Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define tileSizef 96.0f
#define movementRate 256.0f

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Another Hero", sf::Style::Close);
	sf::CircleShape pc(tileSizef/2);
	pc.setFillColor(sf::Color::White);

	sf::Clock clock;
	sf::Time elapsedTime;

	// timers
	sf::Clock movementTimer;
	//sf::Int32 movementTimer = 0;
		
	while (window.isOpen())
	{
		// get elapsedTime since last loop
		elapsedTime = clock.restart();

		// treat events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Movement
		/*if (movementTimer > 0.0f) {
			movementTimer -= elapsedTime.asMilliseconds();
		}*/
		
		if (movementTimer.getElapsedTime().asMilliseconds() >= movementRate) {
		//if (movementTimer <= 0.0f){
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				pc.move(tileSizef, 0.0f);
				//movementTimer = movementRate;
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				pc.move(0.0f, tileSizef);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				pc.move(-tileSizef, 0.0f);
				movementTimer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				pc.move(0.0f, -tileSizef);
				movementTimer.restart();
			}

		}

		window.clear();

		// draw all objects
		window.draw(pc);

		window.display();
	}

	return 0;
}
