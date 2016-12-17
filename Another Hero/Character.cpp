#include "StdAfx.h"
#include "Character.h"

Stats Character::getStats()
{
	return stats;
}

void Character::setStats(Stats value)
{
	stats = value;
}

void Character::levelUp()
{
	stats.levelUp();
}

void Character::setPosition(int X, int Y)
{
	position.x = X;
	position.y = Y;
	sprite.setPosition(
		(float)position.x * TileSizef,
		(float)position.y * TileSizef);
}

void Character::move(int X, int Y)
{
	position.x += X;
	position.y += Y;
	sprite.setPosition(
		(float)position.x * TileSizef,
		(float)position.y * TileSizef);
}

const sf::Vector2i& Character::getPosition()
{
	return position;
}
