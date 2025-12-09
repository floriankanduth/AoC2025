// Source - https://stackoverflow.com/a
// Posted by 111111, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-09, License - CC BY-SA 3.0

#include <cinttypes>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int get_distance(const string &line) {
    const string distance_str = line.substr(1, line.length() - 1);
    return stoi(distance_str);
}

int get_dir(const string &line) {
    return line[0] == 'L' ? -1 : 1;
}

int main() {
    ifstream file("input.txt");
    string line;

    int position = 50;
    int count = 0;


    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        position += get_dir(line) * get_distance(line);
        position %= 100;
        printf("New position: %d\n", position);

        if (position == 0) {
            count++;
        }
    }
    printf("Count: %d\n", count);
    return 0;
}
