#pragma once

class Start
{
public:
	enum MenuResult { kNothing, kSummonHero, kHallOfFame};

	struct MenuItem
	{
		public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	GameState Event(sf::Event);
	void Loop();
	Start(sf::RenderWindow* window);

private:
	sf::RenderWindow* window_;
	sf::Texture menu_texture;
	sf::Sprite sprite;

	sf::String pc_name_;
	sf::Text pc_name_text_;
	sf::Font font;
	MenuResult HandleClick(sf::Event::MouseButtonEvent);

	std::list<MenuItem> menu_items_;
};
