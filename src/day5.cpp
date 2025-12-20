/**
 * https://adventofcode.com/2025/day/5
 */

#include <iostream>
#include <ostream>
#include <vector>

#include "common.h"
#include "FreshRange.h"

/**
 * Looks through fresh ranges to see if ingredients are fresh.
 *
 * @param numbers ingredient IDs
 * @param ranges ranges of fresh ingredients
 * @return number of fresh ingredients
 */
int solve_part1(const std::vector<unsigned long> &numbers, const std::vector<FreshRange> &ranges) {
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
void parse_input(const std::vector<string> &lines, std::vector<unsigned long> &numbers, std::vector<FreshRange> &ranges) {
    int i;

    for (i = 0; i < lines.size() && !lines[i].empty(); i++) {
        ranges.emplace_back(lines[i]);
    }

    //i++ as initializer looks cursed, but we need to consume the empty line
    for (i++; i < lines.size() && !lines[i].empty(); i++) {
        numbers.emplace_back(std::stoul(lines[i]));
    }
}


/**
 * The input is given as a list of ranges and a list of ingredient IDs, seperated by a blank line.
 * Ingredients with IDs inside the ranges are considered fresh.
 * Find the number of fresh ingredients.
 * @return 0
 */
int run_day5(const std::vector<std::string>& input) {
    std::vector<FreshRange> ranges;
    std::vector<unsigned long> numbers;

    parse_input(input, numbers, ranges);
    const int count = solve_part1(numbers, ranges);


    cout << count << endl;
    return 0;
}
