#pragma once
#include "PlainText.h"

#define LETTERSTART 97
#define LETTEREND 122

class ShiftText : public PlainText {
protected:
	int _key;
public:
	ShiftText(string text, int key);
	~ShiftText();
	static string encrypt(string text, int key);
	static string decrypt(string text, int key);
	string encrypt();
	string decrypt();

};