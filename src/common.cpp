#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "common.h"


using namespace std;


vector<string> loadPuzzle(int day) {
    stringstream filename;
    string line;
    vector<string> lines;

    filename << "input/day" << day << "/input.txt";
    fstream file(filename.str());
    assert(file.is_open());


    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

vector<string> loadExample(int day) {
    stringstream filename;
    string line;
    vector<string> lines;

    filename << "input/day" << day << "/example.txt";
    fstream file(filename.str());
    assert(file.is_open());


    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}