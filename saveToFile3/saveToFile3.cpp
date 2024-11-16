#include "header3.h"
#include <fstream>
#include <iostream>
using namespace std;

string scoreToString(Score score) {
    switch (score) {
        case Unsatisfactorily: return "Unsatisfactorily";
        case Satisfactorily: return "Satisfactorily";
        case Good: return "Good";
        case Excellent: return "Excellent";
        default: return "Unknown";
    }
}

void saveToFile(const std::string& filename, const Groups& groups) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& group : groups) {
        outFile << group.first << endl;
        for (const auto& student : group.second) {
            outFile << student.Name << " " << student.Year << endl;
            for (const auto& record : student.RecordBook) {
                outFile << record.first << " " << record.second << endl;
            }
        }
    }
    outFile.close();
}
