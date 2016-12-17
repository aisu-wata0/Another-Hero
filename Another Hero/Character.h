#pragma once
#include "Stats.h"

class Character
{
	Stats stats;
	sf::Vector2i position;

public:
	sf::RectangleShape sprite;
	char name[24];
	bool party_leader;
	Stats getStats();
	void setStats(Stats);
	void levelUp();
	const sf::Vector2i& getPosition();
	void setPosition(int, int);
	void move(int, int);
};
