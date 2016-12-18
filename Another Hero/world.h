#pragma once

class World{
	sf::RenderWindow* window_;

	Character pc_;
	sf::Texture pc_texture_;

	sf::Clock movement_timer_;
	sf::RectangleShape side_menu_;

	enum MenuState {
		kSettings, kInventory,
		kParty, kSkills, kStatus
	};

public:
	void Event();
	void Loop();
	World(sf::RenderWindow* window);
};
