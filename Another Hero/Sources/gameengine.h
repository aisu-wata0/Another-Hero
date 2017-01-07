#pragma once

#include "stdafx.h"

#include <vector>
using namespace std;

class GameState;

class GameEngine
{
public:

	void Init(const char* title, int width=1280, int height=720, 
		      int bpp=0, bool fullscreen=false);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();
	
	sf::RenderWindow window;

private:
	// stack of states
	vector<GameState*> states;

	bool _fullscreen;
};
