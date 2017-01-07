#pragma once

#include "stdafx.h"
#include "gamestate.h"
#include "character.h"

class PlayState : public GameState
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static PlayState* Instance() {
		return &_PlayState;
	}

protected:
	PlayState() { }

private:
	static PlayState _PlayState;

	int board_size;
	float movement_rate;
	float tile_size;

	Character pc_;
	sf::Texture pc_texture_;

	sf::Clock movement_timer_;
	sf::RectangleShape side_menu_;

	enum MenuState {
		kSettings, kInventory,
		kParty, kSkills, kStatus
	};

};
