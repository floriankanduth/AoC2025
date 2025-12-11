/**
* https://adventofcode.com/2025/day/2
*/

#include <cinttypes>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>
#include "../inc/day2.h"
using namespace std;
#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif
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

        auto find_matches() const {
            unsigned long sum = 0;

            try {
                const auto r = regex(R"(^(\d+)(\1)$)");
                smatch m;
                for (unsigned long i = from; i <= to; ++i) {
                    string str = to_string(i);
                    if (regex_search(str, m, r)) {
                        DEBUG_PRINT("%s\n", str.c_str());
                        sum += i;
                    }
                }
            } catch (const std::regex_error &e) {
                DEBUG_PRINT("%s\n", e.what());
            }

            return sum;
        }
    };

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

    int main() {
        const auto ranges = readFile("../input/day2/input.txt");
        unsigned long sum = 0;
        for (auto range: ranges) {
            sum += range.find_matches();
        }
        printf("Day 2 Final Sum = %lu", sum);

        return 0;
    }
