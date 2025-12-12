#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "common.h"


using namespace std;


vector<string> readFile(int day) {
    stringstream filename;
    string line;
    vector<string> lines;

    filename << "../input/day" << day << "/input.txt";
    fstream file(filename.str());
    assert(file && file.is_open());


    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}
