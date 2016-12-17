// Another Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define movementRate 128.0f
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
	/*TODO make a Character class,
	discrete values for position (mult by TileSize)*/
	sf::CircleShape pc(TileSizef/2);
	pc.setFillColor(sf::Color::White);
	pc.setPosition(4 * TileSizef, 4 * TileSizef);

	// game loop clock
	sf::Clock clock;
	sf::Int32 elapsedTime;

	// timers
	sf::Clock movementTimer;
	//sf::Int32 movementTimer = 0;
		
	while (window.isOpen())
	{
		// get elapsedTime since last loop
		elapsedTime = clock.restart().asMicroseconds();

		// treat events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			
			if (event.type == sf::Event::KeyPressed) {

				// Movement
				/*if (movementTimer > 0.0f) {
				movementTimer -= elapsedTime.asMilliseconds();
				}*/

				if (movementTimer.getElapsedTime().asMilliseconds() >= movementRate) {
					//if (movementTimer <= 0.0f){

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
					&& pc.getPosition().x < (BoardSize - 1)*TileSizef) {
						pc.move(TileSizef, 0.0f);
						//movementTimer = movementRate;
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
			} // end if (event.type == sf::Event::KeyPressed)

		}

		window.clear();

		// draw all objects
		window.draw(pc);

		window.display();
	}

	return 0;
}
