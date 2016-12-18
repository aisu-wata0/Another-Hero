#include "StdAfx.h"

void World::Event()
{

}

void World::Loop()
{
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

	window_->clear();

	// draw all objects
	window_->draw(sideMenu);
	window_->draw(pc.sprite);

	window_->display();

}

World::World(sf::RenderWindow* window){
	window_ = window;

	// pc sprite
	pc.sprite.setSize(sf::Vector2f(TileSizef, TileSizef));
	pcTexture.loadFromFile("Textures/PIxelantasy/Characters/Soldier/PNG/Soldier.png");
	pc.sprite.setTexture(&pcTexture);
	pc.setPosition(BoardSize / 2, BoardSize / 2);

	// side menu
	sideMenu = sf::RectangleShape(sf::Vector2f(
		WindowWidth - WindowHeight, // x
		WindowHeight)); // y
	sideMenu.setFillColor(sf::Color::Color(124, 60, 0));
	sideMenu.setPosition(WindowHeight, 0.0f);

}
