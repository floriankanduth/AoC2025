#include <array>
#include <iostream>
#include <ostream>
#include <vector>

#include "common.h"
#include "day1.h"
#include "day10.h"
#include "day11.h"
#include "day12.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"

typedef int (*DayFn)(const std::vector<std::string> &);

constexpr std::array<DayFn, 12> days = {
    run_day1,
    run_day2,
    run_day3,
    run_day4,
    run_day5,
    run_day6,
    run_day7,
    run_day8,
    run_day9,
    run_day10,
    run_day11,
    run_day12
};
const std::string usage_str = "Usage: aoc <day>\n";

int main(int argc, char *argv[]) {
    int day = 0;

    if (argc < 2) {
        std::cerr << usage_str << std::endl;
        return -1;
    }

    if (std::string("-h") == argv[1]) {
        std::cout << usage_str << std::endl;
        return 0;
    }

    try {
        day = std::stoi(argv[1]);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << usage_str << std::endl;
        return -1;
    }

    if (day < 1 || day > days.size()) {
        std::cerr << usage_str << std::endl;
        std::cerr << "Invalid Day: " << day << std::endl;
        std::cerr << "Must be between 1 and " << days.size() << std::endl;
        return -1;
    }

    auto input = loadExample(day);
    days[day - 1](input);

    input = loadPuzzle(day);
    days[day - 1](input);

    return 0;
}
