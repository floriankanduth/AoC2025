/**
 * https://adventofcode.com/2025/day/5
 */

#include <iostream>
#include <ostream>

#include "common.h"

class FreshRange {

public:
    unsigned long from;
    unsigned long to;

    FreshRange(const int from, const int to) : from(from), to(to) {
    }

    explicit FreshRange(const string &line) {
        const auto sep = line.find('-');

        from = stoul(line.substr(0, sep));
        to = stoul(line.substr(sep + 1));
    }

    bool contains(const unsigned long &number) const {
        return from <= number && number <= to;
    }
};

/**
 * Looks through fresh ranges to see if ingredients are fresh.
 *
 * @param numbers ingredient IDs
 * @param ranges ranges of fresh ingredients
 * @return number of fresh ingredients
 */
int solve_part1(const vector<unsigned long> &numbers, const vector<FreshRange> &ranges) {
    int count = 0;

    for (const unsigned long &number: numbers) {
        for (const auto &range: ranges) {
            if (range.contains(number)) {
                count++;
                break;
            }
        }
    }
    return count;
}

/**
 * Split the puzzle input into ranges and numbers
 *
 * @param lines puzzle input
 * @param numbers pointer to number vector
 * @param ranges pointer to ranges vector
 */
void parse_input(const vector<string> &lines, vector<unsigned long> &numbers, vector<FreshRange> &ranges) {
    int i;

    for (i = 0; i < lines.size() && !lines[i].empty(); i++) {
        ranges.emplace_back(lines[i]);
    }

    //i++ as initializer looks cursed, but we need to consume the empty line
    for (i++; i < lines.size() && !lines[i].empty(); i++) {
        numbers.emplace_back(stoul(lines[i]));
    }
}


/**
 * The input is given as a list of ranges and a list of ingredient IDs, seperated by a blank line.
 * Ingredients with IDs inside the ranges are considered fresh.
 * Find the number of fresh ingredients.
 * @return 0
 */
int main() {
    const auto example = loadExample(5);
    const auto puzzle = loadPuzzle(5);

    vector<FreshRange> ranges;
    vector<unsigned long> numbers;

    parse_input(puzzle, numbers, ranges);
    const int count = solve_part1(numbers, ranges);


    cout << count << endl;
    return 0;
}
