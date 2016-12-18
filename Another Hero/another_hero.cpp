// Another Hero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stats.h"
#include "Character.h"
#include "World.h"

int main()
{

	enum GameState {
		kStart, kWorld,
		kEncounter
	};

	enum MenuState {
		kSettings, kInventory,
		kParty, kSkills, kStatus
	};

	GameState game_state = kStart;

	// render main window
	sf::RenderWindow window(
		sf::VideoMode(WindowWidth, WindowHeight),
		"Another Hero",
		sf::Style::Close);
	//window.setFramerateLimit(60);

	// State constructors
	Start start(&window);
	World world(&window);
	Encounter encounter(&window);

	while (window.isOpen())
	{
		
		// treat events
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			// Add more state independent events here
			}

			switch (game_state)
			{
			case kStart:
				start.Event();
				break;

			case kWorld:
				world.Event();
				break;

			case kEncounter:
				encounter.Event();
				break;
			}

		} // end while (window.pollEvent(event))

		switch (game_state)
		{
		case kStart:
			start.Loop();
			break;

		case kWorld:
			world.Loop();
			break;

		case kEncounter:
			encounter.Loop();
			break;
		}

	}

	return 0;
}
