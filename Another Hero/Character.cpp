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
		(float)position_.x * kTileSizef,
		(float)position_.y * kTileSizef);
}

void Character::move(int X, int Y)
{
	// changes internal position_
	position_.x += X;
	position_.y += Y;

	// changes sprite position_
	sprite.setPosition(
		(float)position_.x * kTileSizef,
		(float)position_.y * kTileSizef);
}

const sf::Vector2i& Character::getPosition()
{
	return position_;
}
