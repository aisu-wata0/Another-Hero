#include "stdAfx.h"
#include "input.h"

void Input::handleTextEvent(sf::String* pstr, sf::Uint32 unicode) {
	handleTextEvent(pstr, unicode, pstr->getSize() + 1);
}

void Input::handleTextEvent(sf::String* pstr, sf::Uint32 unicode, int max) {

	char c = static_cast<char>(unicode);

	if (pstr->getSize() < max
		&& ( (c > 0x30) && (c < 0x7a) ) ) {
		*pstr += c;
	}
	// handle backspace
	else if (c == '\b' && (pstr->getSize() > 0)) {
		pstr->erase(pstr->getSize() - 1, 1);
	}
}
