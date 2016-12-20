#pragma once

class Input
{
public:
	//Adds unicode character to str received.
	//Backspace removes last character from string
	static void handleTextEvent(sf::String* pstr, sf::Uint32 unicode);

	//Adds unicode character to str received.
	//Backspace removes last character from string
	static sf::String Input::handleTextEvent(sf::String str, sf::Uint32 unicode);

	//Adds unicode character to str received
	//unless the str is of max size already.
	//Backspace removes last character from string
	static void handleTextEvent(sf::String* pstr, sf::Uint32 unicode, size_t max);

	//Adds unicode character to str received
	//unless the str is of max size already.
	//Backspace removes last character from string
	static sf::String handleTextEvent(sf::String str, sf::Uint32 unicode, size_t max);
};
