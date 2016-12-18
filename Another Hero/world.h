#pragma once

class World
{
	sf::RenderWindow* window_;

	Character pc;
	sf::Clock movementTimer;
	sf::RectangleShape sideMenu;	

public:
	void Event();
	void Loop();
	World(sf::RenderWindow* window);
};
