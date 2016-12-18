#include "StdAfx.h"

void World::Event()
{

}

void World::Loop()
{
	// PC Movement
	if (movement_timer_.getElapsedTime().asMilliseconds() >= kMovementRate) {
		// checks W A S D and moves accordinglly, if not at border already
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			&& pc_.getPosition().x < (kBoardSize - 1)) {

			pc_.move(1, 0);
			movement_timer_.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& pc_.getPosition().y < (kBoardSize - 1)) {

			pc_.move(0, 1);
			movement_timer_.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			&& pc_.getPosition().x > 0) {

			pc_.move(-1, 0);
			movement_timer_.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& pc_.getPosition().y > 0) {

			pc_.move(0, -1);
			movement_timer_.restart();
		}

	}

	// draw all objects
	window_->draw(side_menu_);
	window_->draw(pc_.sprite);
}

World::World(sf::RenderWindow* window){
	window_ = window;

	// pc_ sprite
	pc_.sprite.setSize(sf::Vector2f(kTileSizef, kTileSizef));
	pc_texture_.loadFromFile("Textures/PIxelantasy/Characters/Soldier/PNG/Soldier.png");
	pc_.sprite.setTexture(&pc_texture_);
	pc_.setPosition(kBoardSize / 2, kBoardSize / 2);

	// side menu
	side_menu_ = sf::RectangleShape(sf::Vector2f(
		kWindowWidth - kWindowHeight, // x
		kWindowHeight)); // y
	side_menu_.setFillColor(sf::Color::Color(124, 60, 0));
	side_menu_.setPosition(kWindowHeight, 0.0f);

}
