#include "stdAfx.h"
#include "input.h"

void Input::handleTextEvent(sf::String* pstr, sf::Uint32 unicode) {
	handleTextEvent(pstr, unicode, pstr->getSize() + 1);
}

sf::String Input::handleTextEvent(sf::String str, sf::Uint32 unicode) {
	return handleTextEvent(str, unicode, str.getSize() + 1);
}

void Input::handleTextEvent(sf::String* pstr, sf::Uint32 unicode, size_t max) {

	char c = static_cast<char>(unicode);

	if (pstr->getSize() < max
		&& ((c > 0x30) && (c < 0x7a)))
	{
		*pstr += c;
	}
	// handle backspace
	else if (c == '\b' && (pstr->getSize() > 0)) {
		pstr->erase(pstr->getSize() - 1, 1);
	}
}

sf::String Input::handleTextEvent(sf::String str, sf::Uint32 unicode, size_t max) {

	char c = static_cast<char>(unicode);

	if (str.getSize() < max
		&& ((c > 0x30) && (c < 0x7a)))
	{
		str += c;
	}
	// handle backspace
	else if (c == '\b' && (str.getSize() > 0)) {
		str.erase(str.getSize() - 1, 1);
	}

	return str;
}
