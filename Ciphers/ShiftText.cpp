#include "ShiftText.h"

ShiftText::ShiftText(string text, int key) : PlainText(text) {
	this->_key = key;
	this->encrypt();
}

ShiftText::~ShiftText() {
	this->_key = 0;
}

string ShiftText::encrypt(string text, int key) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] < LETTERSTART || text[i] > LETTEREND) continue;
		text[i] -= LETTERSTART;
		text[i] += key;
		text[i] = LETTERSTART + ((text[i]) % (LETTEREND + 1 - LETTERSTART));
	}
	return text;
}

string ShiftText::decrypt(string text, int key) {

	for (int i = 0; i < text.length(); i++) {
		if (text[i] < LETTERSTART || text[i] > LETTEREND) continue;
		text[i] -= key;
		if (text[i] < LETTERSTART)
			text[i] = (text[i] - LETTERSTART)+LETTEREND+1;
		text[i] = LETTERSTART + ((text[i] - LETTERSTART) % (LETTEREND + 1 - LETTERSTART));
	}
	return text;
}

string ShiftText::encrypt() {
	if (this->_isEnc)
		return this->_text;
	this->_text = this->encrypt(this->_text, this->_key);
	this->_isEnc = true;
	return this->_text;
}

string ShiftText::decrypt() {
	if (!this->_isEnc)
		return this->_text;
	this->_text = this->decrypt(this->_text, this->_key);
	this->_isEnc = false;
	return this->_text;
}

ostream& operator<<(std::ostream& os, const ShiftText& text) {
	os << "ShiftText" << "\n\n";
	os << text.getText();
	return os;
}