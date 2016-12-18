#pragma once

class Start
{
	sf::RenderWindow* window_;

public:
	void Event();
	void Loop();
	Start(sf::RenderWindow* window);
};
