#include "stdAfx.h"
#include "character.h"

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
		(float)position_.x * tile_size,
		(float)position_.y * tile_size);
}

void Character::move(int X, int Y)
{
	// changes internal position_
	position_.x += X;
	position_.y += Y;

	// changes sprite position_
	sprite.setPosition(
		(float)position_.x * tile_size,
		(float)position_.y * tile_size);
} // Todo, make a Player class

void Character::setTileSize(float size)
{
	tile_size = size;
	setPosition(position_.x, position_.y);
}

const sf::Vector2i& Character::getPosition()
{
	return position_;
}
