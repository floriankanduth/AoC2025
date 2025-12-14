/**
 * https://adventofcode.com/2025/day/1
 */

#include <cinttypes>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include "common.h"


/**
 *
 * @param line line from puzzle input
 * @return distance to turn the dial
 */
int get_distance(const string &line) {
    const string distance_str = line.substr(1, line.length() - 1);
    return stoi(distance_str);
}

/**
 *
 * @param line line from puzzle input
 * @return direction factor as +-1
 */
int get_dir(const string &line) {
    return line[0] == 'L' ? -1 : 1;
}

int main(int argc, char **argv) {
    const auto lines = loadPuzzle(1);

    int position = 50;
    int count = 0;

    for (const auto &line: lines) {
        const int dir = get_dir(line);
        const int dist = get_distance(line);

        for (int i = 0; i < dist; i++) {
            position += dir;
            position %= 100;
            position = position < 0 ? position + 100 : position;
            if (position == 0) {
                count++;
                DEBUG_PRINT("count: %d\n", count);
            }
        }

        DEBUG_PRINT("New position: %d\n", position);
    }
    printf("final count: %d\n", count);
    return 0;
}
