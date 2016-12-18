#pragma once

class Character
{
	Stats stats;
	sf::Vector2i position;

public:
	char name[24];
	long level;
	bool party_leader;

	Stats getStats();
	void setStats(Stats);
	void levelUp();

	sf::RectangleShape sprite;
	const sf::Vector2i& getPosition();
	void setPosition(int, int);
	void move(int, int);
};
