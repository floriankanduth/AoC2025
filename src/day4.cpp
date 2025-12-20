/**
 * https://adventofcode.com/2025/day/4
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include "common.h"
#include "day4.h"

constexpr char paper = '@';
constexpr char empty = '.';

static void printPapers(const vector<string> &papers) {
    for (const auto &line: papers) {
        cout << line << endl;
    }
    cout << endl;
}

/**
 * Counts the number of paper rolls adjacent to roll at (x,y)
 *
 * @param x x coordinate of paper roll to check
 * @param y y coordinate of paper roll to check
 * @param papers array of papers
 * @return number of paper rolls adjacent to roll
 */
static int countAdjacentPapers(const int x, const int y, const vector<string> &papers) {
    int count = 0;
    const auto x_max = papers.at(0).size();
    const auto y_max = papers.size();
    assert(papers.at(x).at(y) == paper);

    for (int x_adj = x - 1; x_adj <= x + 1; ++x_adj) {
        //skip oob
        if (x_adj < 0 || x_adj >= x_max) {
            continue;
        }

        for (int y_adj = y - 1; y_adj <= y + 1; ++y_adj) {
            //skip oob and current paper
            if (y_adj < 0 ||
                y_adj >= y_max ||
                (x_adj == x && y_adj == y)) {
                continue;
            }

            if (papers.at(x_adj).at(y_adj) == paper) {
                count++;
            }
        }
    }

    return count;
}

/**
 * Check the floor to see how many paper rolls can be removed.
 * A paper roll can be removed if there are < 4 rolls adjacent to it.
 *
 * @param papers array of paper rolls
 * @return amount of paper rolls that can be removed
 */
static int solve_part1(const vector<string> &papers) {
    int count = 0;
    const auto x_max = papers.at(0).size();
    const auto y_max = papers.size();

    for (int x = 0; x < x_max; ++x) {
        for (int y = 0; y < y_max; ++y) {
            if (papers.at(x).at(y) == paper) {
                const auto adjacent_papers = countAdjacentPapers(x, y, papers);
                if (adjacent_papers < 4) {
                    count++;
                }
            }
        }
    }

    return count;
}

/**
 * Remove papers when there are < 4 rolls adjacent.
 * Repeat until no further paper rolls can be removed.
 *
 * @param papers array of papers
 * @return total number of removed papers
 */
static int solve_part2(const vector<string> &papers) {
    printPapers(papers);
    auto papers_cpy = papers;
    auto papers_prev = papers;
    int removed_papers = 0;
    int removed_papers_prev = -1;

    const auto x_max = papers.at(0).size();
    const auto y_max = papers.size();

    // remove rolls until nothing changes
    while (removed_papers != removed_papers_prev) {
        removed_papers_prev = removed_papers;

        for (int x = 0; x < x_max; ++x) {
            for (int y = 0; y < y_max; ++y) {
                if (papers_prev.at(x).at(y) == paper) {
                    const auto adjacent_papers = countAdjacentPapers(x, y, papers_prev);
                    if (adjacent_papers < 4) {
                        removed_papers++;
                        papers_cpy.at(x).at(y) = '.';
                    }
                }
            }
        }
        printPapers(papers_cpy);
        papers_prev = papers_cpy;
    }
    return removed_papers;
}

int run_day4(const std::vector<std::string>& input) {
    const auto example = loadExample(4);
    const auto puzzle = loadPuzzle(4);
    const auto count = solve_part2(puzzle);

    cout << "Solution: " << count << endl;
    return 0;
}
