#pragma once

class Encounter
{
	sf::RenderWindow* window_;

public:
	void Event();
	void Loop();
	Encounter(sf::RenderWindow* window);
};
