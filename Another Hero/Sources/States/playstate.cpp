
#include <stdio.h>

#include "stdafx.h"
#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"
#include "menustate.h"

PlayState PlayState::_PlayState;

void PlayState::Init(GameEngine* game)
{
	board_size = 9; // A zone may have a unique size
	tile_size = (float)game->window.getSize().y / board_size;
	movement_rate = 192.0f;
	pc_.setTileSize(tile_size);

	// pc_ sprite
	pc_.sprite.setSize(sf::Vector2f(tile_size, tile_size));
	pc_texture_.loadFromFile("Textures/PIxelantasy/Characters/Soldier/PNG/Soldier.png");
	pc_.sprite.setTexture(&pc_texture_);
	pc_.setPosition(board_size / 2, board_size / 2);

	// side menu
	side_menu_ = sf::RectangleShape(sf::Vector2f(
		(float)game->window.getSize().x - game->window.getSize().y, // x
		(float)game->window.getSize().y)); // y

	side_menu_.setFillColor(sf::Color::Color(124, 60, 0));
	side_menu_.setPosition((float)game->window.getSize().y, 0.0f);

	printf("PlayState Init\n");
}

void PlayState::Cleanup()
{
	printf("PlayState Cleanup\n");
}

void PlayState::Pause()
{
	printf("PlayState Pause\n");
}

void PlayState::Resume()
{
	printf("PlayState Resume\n");
}

void PlayState::HandleEvents(GameEngine* game)
{
	sf::Event event;
	if (game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::MouseButtonPressed:
			// HandleClickEvents();
			break;

		case sf::Event::TextEntered:
			// change text on active side menu text box
			break;
		}
	}
}

void PlayState::Update(GameEngine* game)
{
	// PC Movement
	if (movement_timer_.getElapsedTime().asMilliseconds() >= movement_rate) {
		// checks W A S D and moves accordinglly, if not at border already
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			&& pc_.getPosition().x < (board_size - 1)) {

			pc_.move(1, 0);
			movement_timer_.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& pc_.getPosition().y < (board_size - 1)) {

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
}

void PlayState::Draw(GameEngine* game)
{
	game->window.clear();
	game->window.draw(side_menu_);
	game->window.draw(pc_.sprite);
	game->window.display();
}

