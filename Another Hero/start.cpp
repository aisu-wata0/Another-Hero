#include "StdAfx.h"
#include "start.h"
#include "input.h"

GameState Start::Event(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		switch (HandleClick(event.mouseButton))
		{
		case kSummonHero:
			if(pc_name_.getSize() > 0 )
				return kWorld;
			break;

		case kHallOfFame:

			break;
		}
		break;

	case sf::Event::TextEntered:

		Input::handleTextEvent(&pc_name_, event.text.unicode,24);
		
		pc_name_text_.setString(pc_name_);

		// keep text position centralized
		pc_name_text_.setPosition(
			(kWindowWidth - pc_name_text_.getGlobalBounds().width)/2,
			kHeroNameInputHeight);

		pc_name_text_.setStyle(sf::Text::Style::Regular);
	}
	
	return kStart;
}


void Start::Loop()
{
	window_->draw(sprite);
	window_->draw(pc_name_text_);
}

Start::MenuResult Start::HandleClick(sf::Event::MouseButtonEvent mouse)
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

Start::Start(sf::RenderWindow* window) {
	window_ = window;
	

	font.loadFromFile("Fonts/Roboto-Medium.ttf");

	pc_name_text_ = sf::Text("Type the hero name", font);
	pc_name_text_.setStyle(sf::Text::Style::Bold);
	pc_name_text_.setFillColor(sf::Color::Black);

	// text position centralized
	pc_name_text_.setPosition(
		(kWindowWidth - pc_name_text_.getGlobalBounds().width) / 2,
		kHeroNameInputHeight);

	//Load menu image from file
	menu_texture.loadFromFile("Textures/mainmenu.png");
	sprite = sf::Sprite(menu_texture);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem play_button;
	play_button.rect.left = 418;
	play_button.rect.top = 250;
	// right == 861
	play_button.rect.width = 861 - play_button.rect.left;
	// bot == 329
	play_button.rect.height = 329 - play_button.rect.top;
	play_button.action = kSummonHero;

	//Exit menu item coordinates
	MenuItem hall_of_fame_button;
	hall_of_fame_button.rect.left = 0;
	hall_of_fame_button.rect.top = 383;
	hall_of_fame_button.rect.width = 1023;
	hall_of_fame_button.rect.height = 560;
	hall_of_fame_button.action = kHallOfFame;

	menu_items_.push_back(play_button);
	menu_items_.push_back(hall_of_fame_button);
}
