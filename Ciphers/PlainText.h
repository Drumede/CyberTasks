#pragma once
#include <string>
#include <iostream>
using namespace std;

class PlainText {
protected:
	string _text;
	bool _isEnc;
public:
	static int numOfTexts;
	PlainText(string text);
	~PlainText();
	bool isEncrypted() const;
	string getText() const;
};