#include "FileHelper.h"

string FileHelper::readFileToString(string fileName) {
    ifstream file(fileName);
    if (!file) return "";

    string result;
    string line;

    bool first = true;
    while (std::getline(file, line)) {
        if (!first) result += '\n';
        first = false;
        result += line;
    }

    return result;
}

void FileHelper::writeWordsToFile(string inputFileName, string outputFileName) {
    ifstream input(inputFileName);
    ofstream output(outputFileName);

    if (!input || !output) {
        return;
    }

    std::string word;

    while (input >> word) {
        output << word << "\n";
    }
}

void FileHelper::saveTextInFile(string text, string outputFileName) {
    ofstream output(outputFileName);

    if (!output) {
        return;
    }

    output << text;
}