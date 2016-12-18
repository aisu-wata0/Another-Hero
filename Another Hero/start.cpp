#include "StdAfx.h"
#include "start.h"
void inputText(sf::String* pstr, char c, int max) {
	if (c < 128) {
		// handle backspace
		if (c == '\b' && (pstr->getSize() > 0)) {
			pstr->erase(pstr->getSize() - 1, 1);
		}
		else if(pstr->getSize() < max) {
			*pstr += c;
		}
	}
} // TODO make a TextInput class

GameState Start::Event(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		switch (HandleClick(event.mouseButton))
		{
		case kSummonHero:
			return kWorld;
			break;

		case kHallOfFame:

			break;
		}
		break;

	case sf::Event::TextEntered:
		char c = static_cast<char>(event.text.unicode);
		inputText(&pc_name_, c,24);

		pc_name_text_.setString(pc_name_);
		printf("%lf", pc_name_text_.getGlobalBounds().width);
		pc_name_text_.setPosition(
			(kWindowWidth - pc_name_text_.getGlobalBounds().width)/2,
			190);
		// TODO make 190 a constant
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
	

	font.loadFromFile("Fonts/Roboto-Medium.ttf");

	pc_name_text_ = sf::Text("Type the hero name", font);
	pc_name_text_.setStyle(sf::Text::Bold);
	pc_name_text_.setFillColor(sf::Color::Black);
	pc_name_text_.setPosition(
		(kWindowWidth - pc_name_text_.getGlobalBounds().width) / 2,
		190);
	// TODO make 190 a constant

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
