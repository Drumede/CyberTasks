#include "Utils.h"

int fileToCol(char f) { 
	return f - 'a';
}

int rankToRow(char r) { 
	return 8 - (r - '0');
}