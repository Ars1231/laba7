#include <iostream>
#include <vector>
#include "file_operations.h"
using namespace std;

int main() {
    vector<Book> books = {
        {"Lev Tolstoi", "Voina i mir", 1836},
        {"Sasha Pushkin", "Evgenii Onegin", 1831},
        {"Nabokov", "Lolita", 1955}
    };
    const string filename = "books.dat";
    saveToFile(filename, books);
    vector<Book> loadedBooks;
    loadFromFile(filename, loadedBooks);
    for (const auto& book : loadedBooks) {
        cout << "Author: " << book.Author << ", Title: " << book.Title << ", Year: " << book.Year << endl;
    }

    return 0;
}