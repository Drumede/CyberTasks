#pragma once
#include "ShiftText.h"
#include "PlainText.h"

#define CAESARKEY 3

class CaesarText : public ShiftText{
public:
	CaesarText(string text);
	~CaesarText();
	static string encrypt(string text);
	static string decrypt(string text);
	using ShiftText::encrypt;
	using ShiftText::decrypt;
};