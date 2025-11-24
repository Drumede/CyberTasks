#pragma once
#include "PlainText.h"
#include <fstream>

#define LETTERSTART 97
#define LETTEREND 122

class SubstitutionText : public PlainText {
protected:
	string _dictionaryFileName;
public:
	SubstitutionText(string text, string dictionaryFileName);
	~SubstitutionText();
	static string encrypt(string text, string dictionaryFileName);
	static string decrypt(string text, string dictionaryFileName);
	string encrypt();
	string decrypt();
};