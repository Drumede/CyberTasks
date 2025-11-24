#include "SubstitutionText.h"

SubstitutionText::SubstitutionText(string text, string dictionaryFileName) : PlainText(text) {
	this->_dictionaryFileName = dictionaryFileName;
	this->encrypt();
}

SubstitutionText::~SubstitutionText() {
	this->_dictionaryFileName = "";
}

string SubstitutionText::encrypt(string text, string dictionaryFileName) {
	string line;
	ifstream dict;
	dict.open(dictionaryFileName);
	if (!dict.is_open()) return text;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] < LETTERSTART || text[i] > LETTEREND) continue;
		while (getline(dict, line))
		{
			if (line[0] == text[i])
				break;
		}
		dict.seekg(0);
		if (line.empty())
			continue;
		text[i] = line[2];
	}
	dict.seekg(0);
	dict.close();
	return text;
}

string SubstitutionText::decrypt(string text, string dictionaryFileName) {
	string line;
	ifstream dict;
	dict.open(dictionaryFileName);
	if (!dict.is_open()) return text;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] < LETTERSTART || text[i] > LETTEREND) continue;
		while (getline(dict, line))
		{
			if (line[2] == text[i])
				break;
		}
		dict.seekg(0);
		if (line.empty())
			continue;
		text[i] = line[0];
	}
	dict.seekg(0);
	dict.close();
	return text;
}

string SubstitutionText::encrypt() {
	if (this->_isEnc)
		return this->_text;
	this->_text = this->encrypt(this->_text, this->_dictionaryFileName);
	this->_isEnc = true;
	return this->_text;
}

string SubstitutionText::decrypt() {
	if (!this->_isEnc)
		return this->_text;
	this->_text = this->decrypt(this->_text, this->_dictionaryFileName);
	this->_isEnc = false;
	return this->_text;
}

ostream& operator<<(std::ostream& os, const SubstitutionText& text) {
	os << "SubstitutionText" << "\n\n";
	os << text.getText();
	return os;
}