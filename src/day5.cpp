/**
 * https://adventofcode.com/2025/day/5
 */

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

#include "common.h"
#include "FreshRange.h"

/**
 * Merge overlapping ranges to minimize searchable ranges.
 *
 * @param ranges ranges to merge
 * @return merged ranges
 */
static vector<FreshRange> merge(const vector<FreshRange> &ranges) {
    std::vector<FreshRange> ranges_cpy = ranges;
    //sort ranges by from entry
    std::sort(ranges_cpy.begin(), ranges_cpy.end());

    //when a range overlaps the previous range, merge and remove
    for (int i = 0; i < ranges_cpy.size(); ++i) {
        while (i < ranges_cpy.size() - 1 && ranges_cpy[i].overlaps(ranges_cpy[i + 1])) {
            ranges_cpy[i] += ranges_cpy[i + 1];
            ranges_cpy.erase(ranges_cpy.begin() + i + 1);
        }
    }

    return ranges_cpy;
}

/**
 * Looks through fresh ranges to see if ingredients are fresh.
 *
 * @param numbers ingredient IDs
 * @param ranges ranges of fresh ingredients
 * @return number of fresh ingredients
 */
static int solve_part1(const std::vector<unsigned long> &numbers, const std::vector<FreshRange> &ranges) {
    int count = 0;
    auto merged_ranges = merge(ranges);

    for (const unsigned long &number: numbers) {
        for (const auto &range: merged_ranges) {
            if (range.contains(number)) {
                count++;
                break;
            }
        }
    }
    return count;
}

/**
 * Looks through fresh ranges to see if ingredients are fresh.
 *
 * @param ranges ranges of fresh ingredients
 * @return number of fresh ingredients
 */
static unsigned long solve_part2(const std::vector<FreshRange> &ranges) {
    auto merged_ranges = merge(ranges);
    unsigned long count = 0;

    for (const auto &range: merged_ranges) {
        count += range.freshIDs();
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
void parse_input(const std::vector<string> &lines, std::vector<unsigned long> &numbers,
                 std::vector<FreshRange> &ranges) {
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
int run_day5(const std::vector<std::string> &input) {
    std::vector<FreshRange> ranges;
    std::vector<unsigned long> numbers;

    parse_input(input, numbers, ranges);
    const unsigned long part1 = solve_part1(numbers, ranges);
    cout << "Solution Part 1:" << part1 << endl;

    const unsigned long part2 = solve_part2(ranges);
    cout << "Solution Part 1:" << part2 << endl;
    return 0;
}
