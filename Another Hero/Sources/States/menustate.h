
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "stdafx.h"
#include "gamestate.h"

class MenuState : public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static MenuState* Instance() {
		return &m_MenuState;
	}

protected:
	MenuState() { }

private:
	static MenuState m_MenuState;

};

#endif

