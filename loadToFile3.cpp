#include "header3.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void loadFromFile(const std::string& filename, Groups& outGroups) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    string groupName;
    while (getline(inFile, groupName)) {
        vector<Student> students;
        string line;
        while (getline(inFile, line) && line != ";") {
            istringstream iss(line);
            Student student;
            iss >> student.Name >> student.Year;

            string subject;
            int score;
            while (iss >> subject >> score) {
                student.RecordBook[subject] = static_cast<Score>(score);
            }

            students.push_back(student);
        }
        outGroups[groupName] = students;
    }
    inFile.close();
}
