/**
 * https://adventofcode.com/2025/day/3
 */

#include <cassert>
#include <cstring>
#include <iostream>
#include <sstream>

#include "common.h"
/**
 * Find the maximum Joltage [sic.] of the battery bank.
 * Search for the biggest value in the bank as 10s digit. Afterward, search for the biggest value after that.
 *
 * @param line input line
 * @return joltage
 */
unsigned int find_max_joltage(const string &line) {
    unsigned int max_joltage;
    char joltage_str[3] = {'\0'};

    //find the biggest value in line
    for (int i = 9; i >= 0; --i) {
        //search only until 2nd last digit. We need space for one more.
        const size_t upper_idx = line.substr(0, line.size() - 1).find(to_string(i));
        if (upper_idx != string::npos) {
            //This is our 10s digit.
            joltage_str[0] = line[upper_idx];
            //find the biggest digit after the first.
            for (int j = 9; j >= 0; --j) {
                const size_t lower_idx = line.find(to_string(j), upper_idx + 1);
                if (lower_idx != string::npos) {

                    //This is the 1s digit
                    joltage_str[1] = line[lower_idx];

                    max_joltage = stoi(joltage_str);
                    return max_joltage;
                }
            }
        }
    }
    assert(false && "No battery pair found");
    return 0;
}

/**
 * Find maximum joltage by switching on 2 batteries in each line.
 * 987654321111111 -> 98
 * ^^
 * 811111111111119 -> 89
 * ^             ^
 * 234234234234278 -> 78
 *              ^^
 * 818181911112111 -> 92
 *       ^    ^
 *
 * @return sum of all Joltages
 */
unsigned int solve_part1(const vector<string> &puzzle) {
    unsigned int sum = 0;
    for (const auto &line: puzzle) {
        sum += find_max_joltage(line);
    }
    return sum;
}

int main(int argc, char **argv) {
    const auto example = loadExample(3);
    const auto puzzle = loadPuzzle(3);

    const unsigned int sum = solve_part1(puzzle);
    cout << "Total Joltage: " << sum << endl;
}
