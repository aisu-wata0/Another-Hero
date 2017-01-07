
#include <stdio.h>

#include "stdafx.h"
#include "input.h"
#include "gameengine.h"
#include "gamestate.h"
#include "introstate.h"
#include "playstate.h"

#define kHeroNameInputHeight 120

IntroState IntroState::_IntroState;

void IntroState::Init(GameEngine* game)
{
	font.loadFromFile("Fonts/Roboto-Medium.ttf");

	pc_name_text_box_ = sf::Text("Type the hero name", font);
	pc_name_text_box_.setStyle(sf::Text::Style::Bold);
	pc_name_text_box_.setFillColor(sf::Color::Black);

	// text position centralized
	pc_name_text_box_.setPosition(
		(game->window.getSize().x - pc_name_text_box_.getGlobalBounds().width) / 2,
		kHeroNameInputHeight);

	//Load menu image from file
	menu_texture.loadFromFile("Textures/mainmenu.png");
	background = sf::Sprite(menu_texture);

	//Clickable regions

	//Play menu item coordinates
	MenuItem play_button;
	play_button.rect.left = 418;
	play_button.rect.top = 250;
	// right == 861
	play_button.rect.width = 861 - play_button.rect.left;
	// bot == 329
	play_button.rect.height = 329 - play_button.rect.top;
	play_button.action = kSummonHero;

	///Hall of Fame coordinates
	/*MenuItem hall_of_fame_button;
	hall_of_fame_button.rect.left = 0;
	hall_of_fame_button.rect.top = 383;
	hall_of_fame_button.rect.width = 1023;
	hall_of_fame_button.rect.height = 560;
	hall_of_fame_button.action = kHallOfFame;*/

	menu_items_.push_back(play_button);
	///menu_items_.push_back(hall_of_fame_button);

	printf("IntroState Init\n");
}

void IntroState::Cleanup()
{
	printf("IntroState Cleanup\n");
}

void IntroState::Pause()
{
	printf("IntroState Pause\n");
}

void IntroState::Resume()
{
	printf("IntroState Resume\n");
}

void IntroState::HandleEvents(GameEngine* game)
{
	sf::Event event;

	if (game->window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::MouseButtonPressed:
			switch (HandleClick(event.mouseButton))
			{
			case kSummonHero:
				if (pc_name_.getSize() > 0)
					game->ChangeState(PlayState::Instance());
				break;

			case kHallOfFame:

				break;
			}
			break;

		case sf::Event::TextEntered:

			Input::handleTextEvent(&pc_name_, event.text.unicode, 24);

			pc_name_text_box_.setString(pc_name_);

			// keep text position centralized
			pc_name_text_box_.setPosition(
				(game->window.getSize().x - pc_name_text_box_.getGlobalBounds().width) / 2,
				kHeroNameInputHeight);

			pc_name_text_box_.setStyle(sf::Text::Style::Regular);
			break;
		}
	}
}

void IntroState::Update(GameEngine* game) 
{
	
}

void IntroState::Draw(GameEngine* game) 
{
	game->window.clear();
	game->window.draw(background);
	game->window.draw(pc_name_text_box_);
	game->window.display();
}

IntroState::MenuResult IntroState::HandleClick(sf::Event::MouseButtonEvent mouse)
{
	std::list<MenuItem>::iterator it;

	for (it = menu_items_.begin(); it != menu_items_.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.contains(mouse.x, mouse.y))
		{
			return (*it).action;
		}
	}

	return kNothing;
}
