#include "header.h"
#include <fstream>
#include <iostream>
using namespace std;
void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Unable to open this file for writing: " << filename << endl;
        return;
    }
    for (const auto& word : data) {
        outFile << word << endl;
    }
    outFile.close();
}
