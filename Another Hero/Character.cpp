#include "StdAfx.h"

void Character::levelUp()
{
	level_++;
	stats_.levelUp();
}

void Character::setPosition(int X, int Y)
{
	// changes internal position_
	position_.x = X;
	position_.y = Y;

	// changes sprite position_
	sprite.setPosition(
		(float)position_.x * TileSizef,
		(float)position_.y * TileSizef);
}

void Character::move(int X, int Y)
{
	// changes internal position_
	position_.x += X;
	position_.y += Y;

	// changes sprite position_
	sprite.setPosition(
		(float)position_.x * TileSizef,
		(float)position_.y * TileSizef);
}

const sf::Vector2i& Character::getPosition()
{
	return position_;
}
