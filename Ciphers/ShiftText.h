#pragma once
#include "PlainText.h"

class ShiftText : public PlainText {
	int _key;
public:
	ShiftText(string text, int key);
	string encrypt(string text, int key);
	string decrypt(string text, int key);
	string encrypt();
	string decrypt();

};