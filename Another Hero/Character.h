#pragma once

class Character{
	Stats stats_;
	sf::Vector2i position_;

public:
	char name_[24];
	long level_;
	bool party_leader_;

	void levelUp();

	sf::RectangleShape sprite;
	const sf::Vector2i& getPosition();
	void setPosition(int, int);
	void move(int, int);
};
