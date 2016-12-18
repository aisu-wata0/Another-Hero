#include "StdAfx.h"
#include "start.h"

GameState Start::Event(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		switch (HandleClick(event.mouseButton))
		{
		case kSummonHero:
			return kWorld;
			break;

		case kHallOfFame:

			break;
		}
	}
	
	return kStart;
}


void Start::Loop()
{
	window_->draw(sprite);
}

Start::MenuResult Start::HandleClick(sf::Event::MouseButtonEvent mouse)
{
	std::list<MenuItem>::iterator it;

	for (it = menu_items_.begin(); it != menu_items_.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.left < mouse.x
			&& menuItemRect.top < mouse.y
			&& menuItemRect.width > mouse.x
			&& menuItemRect.height > mouse.y)
		{
			return (*it).action;
		}
	}

	return kNothing;
}

Start::Start(sf::RenderWindow* window) {
	window_ = window;

	//Load menu image from file
	menu_texture.loadFromFile("Textures/mainmenu.png");
	sprite = sf::Sprite(menu_texture);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.left = 418;
	playButton.rect.top = 250;
	playButton.rect.width = 861;
	playButton.rect.height = 329;
	playButton.action = kSummonHero;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.top = 383;
	exitButton.rect.width = 1023;
	exitButton.rect.height = 560;
	exitButton.action = kHallOfFame;

	menu_items_.push_back(playButton);
	menu_items_.push_back(exitButton);
}
