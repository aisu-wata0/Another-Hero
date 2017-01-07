// another_hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gameengine.h"
#include "introstate.h"
#include "party.h"

int main()
{

	GameEngine game;

	game.Init("Another Hero");

	game.ChangeState(IntroState::Instance());

	std::list<Party> party_list;

	while (game.window.isOpen()) {

		game.HandleEvents();
		game.Update();
		game.Draw();

	}

	return 0;
}
