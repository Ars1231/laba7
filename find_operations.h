#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H
using namespace std;
#include <string>
#include <vector>
#include "book.h"

void saveToFile(const std::string& filename, const std::vector<Book>& data);
void loadFromFile(const std::string& filename, std::vector<Book>& outData);

#endif
