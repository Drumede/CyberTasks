#include "CaesarText.h"

CaesarText::CaesarText(string text) : ShiftText(text, CAESARKEY) {
	this->_key = CAESARKEY;
	this->encrypt();
}

CaesarText::~CaesarText() {
	this->_key = 0;
}

string CaesarText::encrypt(string text) {
	return ShiftText::encrypt(text, CAESARKEY);
}

string CaesarText::decrypt(string text) {
	return ShiftText::decrypt(text, CAESARKEY);
}

ostream& operator<<(std::ostream& os, const CaesarText& text) {
	os << "CaesarText" << "\n\n";
	os << text.getText();
	return os;
}