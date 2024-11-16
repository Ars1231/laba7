#include "header.h"
#include <iostream>
using namespace std;
int main() {
    vector<std::string> words = {"test1", "test2", "test3"};
    string filename = "output.txt";

    saveToFile(filename, words);
    cout << "Words saved to file." << endl;

    vector<std::string> loadedWords;
    loadFromFile(filename, loadedWords);

    cout << "Words loaded from file:" << endl;
    for (const auto& word : loadedWords) {
        cout << word << endl;
    }

    return 0;
}
