#include "file_operations.h"
#include <fstream>
#include <iostream>
using namespace std;

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Unable to open this file for writing: " << filename << endl;
        return;
    }

    for (const auto& book : data) {
        size_t authorSize = book.Author.size();
        size_t titleSize = book.Title.size();
        outFile.write(reinterpret_cast<const char*>(&authorSize), sizeof(authorSize));
        outFile.write(book.Author.c_str(), authorSize);
        outFile.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
        outFile.write(book.Title.c_str(), titleSize);
        outFile.write(reinterpret_cast<const char*>(&book.Year), sizeof(book.Year));
    }

    outFile.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Unable to open this file for reading: " << filename << std::endl;
        return;
    }

    while (inFile) {
        Book book;
        size_t authorSize, titleSize;

        inFile.read(reinterpret_cast<char*>(&authorSize), sizeof(authorSize));
        if (inFile.eof()) break;
        book.Author.resize(authorSize);
        inFile.read(&book.Author[0], authorSize);
        inFile.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
        book.Title.resize(titleSize);
        inFile.read(&book.Title[0], titleSize);
        inFile.read(reinterpret_cast<char*>(&book.Year), sizeof(book.Year));
        outData.push_back(book);
    }

    inFile.close();
}
