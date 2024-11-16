#include "header.h"
#include <fstream>
#include <iostream>
using namespace std;
void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open this file for reading: " << filename << endl;
        return;
    }
    string word;
    while (getline(inFile, word)) {
        outData.push_back(word);
    }
    inFile.close();
}
