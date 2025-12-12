/**
* https://adventofcode.com/2025/day/2
*/

#include <cinttypes>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;
#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif
/**
 * Specifies search ranges from-to (incl.)
 */
class Range {
public:
    unsigned long from;
    unsigned long to;

    Range(const int from, const int to) : from(from), to(to) {
    }

    explicit Range(const string &range_str) {
        //"11-22"
        const auto delim_idx = range_str.find('-');

        from = stoul(range_str.substr(0, delim_idx));
        to = stoul(range_str.substr(delim_idx + 1));
    }
};

/**
 * Instantiate Ranges from puzzle input.
 * @param fileName input file
 * @return ranges
 */
vector<Range> readFile(const string &fileName) {
    fstream file(fileName);
    string segment;
    vector<Range> ranges;
    while (getline(file, segment, ',')) {
        DEBUG_PRINT("%s\n", segment.c_str());
        ranges.emplace_back(segment);
    }

    file.close();

    return ranges;
}

/**
 * Search number range for regex matches.
 * @param range search range for matches
 * @param r regex to match
 * @return sum of matched numbers
 */
auto find_matches(const Range &range, const regex &r) {
    unsigned long sum = 0;

    smatch m;
    for (unsigned long i = range.from; i <= range.to; ++i) {
        string str = to_string(i);
        if (regex_search(str, m, r)) {
            DEBUG_PRINT("%s\n", str.c_str());
            sum += i;
        }
    }


    return sum;
}

/**
 * Find numbers that are made up of sequences of digits that are repeated twice.
 * E.g.: 11, 22, 99, 1010, 123123, ...
 * We only need to check numbers specified by the given range.
 * @param ranges range to search for matches
 */
void solve_part1(const vector<Range> &ranges) {
    unsigned long sum = 0;
    try {
        const auto r = regex(R"(^(\d+)(\1)$)");

        for (auto range: ranges) {
            sum += find_matches(range, r);
        }
        printf("Day 2.1 Final Sum = %lu", sum);
    } catch (const std::regex_error &e) {
        DEBUG_PRINT("%s\n", e.what());
    }
}

/**
 * Find numbers that are made up of sequences of digits that are repeated at least once.
 * E.g.: 11, 111, 22, 222, 999, 1010, 123123, ...
 * We only need to check numbers specified by the given range.
 * @param ranges range to search for matches
 */
void solve_part2(const vector<Range> &ranges) {
    unsigned long sum = 0;
    try {
        const auto r = regex(R"(^(\d+)(\1)+$)");

        for (auto range: ranges) {
            sum += find_matches(range, r);
        }
        printf("Day 2.2 Final Sum = %lu", sum);
    } catch (const std::regex_error &e) {
        DEBUG_PRINT("%s\n", e.what());
    }
}

int main() {
    const auto ranges = readFile("../input/day2/input.txt");

    solve_part1(ranges);
    solve_part2(ranges);

    return 0;
}
