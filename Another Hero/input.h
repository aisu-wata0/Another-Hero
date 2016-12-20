#pragma once

class Input 
{
public:
	//Adds to a string the unicode character received.
	//backspace removes last character from string
	static void handleTextEvent(sf::String*, sf::Uint32);

	//Adds to a string the unicode character received
	//unless the str is of max size already.
	//backspace removes last character from string
	static void handleTextEvent(sf::String*, sf::Uint32, int);
};
