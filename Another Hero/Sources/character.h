#pragma once

#include "stats.h"


class Character
{
	Stats stats_;
	sf::Vector2i position_;

public:
	char name_[24];
	long level_;
	bool party_leader_;

	void levelUp();

	float tile_size;
	
	void setTileSize(float size);
	sf::RectangleShape sprite;
	const sf::Vector2i& getPosition();
	void setPosition(int, int);
	void move(int, int);
};
