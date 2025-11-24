#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class FileHelper {
public:
	static string readFileToString(string fileName);
	static void writeWordsToFile(string inputFileName, string outputFileName);
	static void saveTextInFile(string text, string outputFileName);
};