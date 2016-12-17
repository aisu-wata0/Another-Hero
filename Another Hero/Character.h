#pragma once
#include "Stats.h"

class Character
{
	Stats stats;

public:
	sf::RectangleShape sprite;
	char name[24];
	bool party_leader;
	Stats getStats();
	void setStats(Stats);
	void levelUp();
};
