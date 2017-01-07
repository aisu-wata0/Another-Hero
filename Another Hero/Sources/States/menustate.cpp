
#include <stdio.h>

#include "stdafx.h"
#include "gameengine.h"
#include "gamestate.h"
#include "menustate.h"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
	printf("MenuState Init\n");
}

void MenuState::Cleanup()
{
	printf("MenuState Cleanup\n");
}

void MenuState::Pause()
{
	printf("MenuState Pause\n");
}

void MenuState::Resume()
{
	printf("MenuState Resume\n");
}

void MenuState::HandleEvents(CGameEngine* game)
{
	sf::Event event;
	if (game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::MouseButtonPressed:
			break;

		case sf::Event::TextEntered:
			break;
		}
	}
}

void MenuState::Update(GameEngine* game) 
{

}

void MenuState::Draw(GameEngine* game) 
{
	game->window.clear();
	//game->window.draw();
	game->window.display();
}
