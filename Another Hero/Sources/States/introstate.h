#pragma once

#include "stdafx.h"
#include "gamestate.h"

class IntroState : public GameState
{
public:
	void Init(GameEngine* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static IntroState* Instance() {
		return &_IntroState;
	}
	///
	enum MenuResult { kNothing, kSummonHero, kHallOfFame };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

protected:
	IntroState() { }

private:
	static IntroState _IntroState;

	sf::Texture menu_texture;
	sf::Sprite background;

	sf::String pc_name_;
	sf::Text pc_name_text_box_;
	sf::Font font; // TODO: make this part of game engine, load on game.Init();
	MenuResult HandleClick(sf::Event::MouseButtonEvent);

	std::list<MenuItem> menu_items_;

};
