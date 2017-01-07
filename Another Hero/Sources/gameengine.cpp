
#include <stdio.h>

#include "stdafx.h"
#include "gameengine.h"
#include "gamestate.h"

void GameEngine::Init(const char* title, int width, int height, 
						 int bpp, bool fullscreen)
{

	// create main window
	window.create(sf::VideoMode(width, height),
		title,
		sf::Style::Close);

	//window.setFramerateLimit(60);

	if (fullscreen) {
		_fullscreen = true;
	}
	
	printf("GameEngine Init\n");
}

void GameEngine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	printf("GameEngine Cleanup\n");
}

void GameEngine::ChangeState(GameState* state) 
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// push new state
	states.push_back(state);
	states.back()->Init(this);
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void GameEngine::HandleEvents() 
{
	// current state handle events
	states.back()->HandleEvents(this);
}

void GameEngine::Update() 
{
	// current state update the game
	states.back()->Update(this);
}

void GameEngine::Draw() 
{
	// current state draw the screen
	states.back()->Draw(this);
}
