#include "PlainText.h"

PlainText::PlainText(string text) {
	this->_text = text;
	this->_isEnc = false;
}

bool PlainText::isEncrypted() const {
	return this->_isEnc;
}

string PlainText::getText() const {
	return this->_text;
}