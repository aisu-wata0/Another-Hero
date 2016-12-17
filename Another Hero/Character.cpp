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
