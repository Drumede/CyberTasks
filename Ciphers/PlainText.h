#pragma once
#include <string>
using namespace std;

class PlainText {
	string _text;
	bool _isEnc;
public:
	PlainText(string text);
	bool isEncrypted() const;
	string getText() const;
};