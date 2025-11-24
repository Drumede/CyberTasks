#include "PlainText.h"

int PlainText::numOfTexts = 0;

PlainText::PlainText(string text) {
	this->_text = text;
	this->_isEnc = false;
	numOfTexts++;
}

PlainText::~PlainText() {
	this->_text = "";
}

bool PlainText::isEncrypted() const {
	return this->_isEnc;
}

string PlainText::getText() const {
	return this->_text;
}

ostream& operator<<(std::ostream& os, const PlainText& text) {
	os << "PlainText" << "\n\n";
	os << text.getText();
	return os;
}