/**
 * https://adventofcode.com/2025/day/4
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include "common.h"
using namespace std;

constexpr char paper = '@';
constexpr char empty = '.';

void printPapers(const vector<string> &papers) {
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
int countAdjacentPapers(const int x, const int y, const vector<string> &papers) {
    int count = 0;
    const auto x_max = papers.at(0).size();
    const auto y_max = papers.size();
    assert(papers.at(x).at(y) == paper);

    for (int x_ = x - 1; x_ <= x + 1; ++x_) {
        //skip oob
        if (x_ < 0 || x_ >= x_max) {
            continue;
        }

        for (int y_ = y - 1; y_ <= y + 1; ++y_) {
            //skip oob and current paper
            if (y_ < 0 ||
                y_ >= y_max ||
                (x_ == x && y_ == y)) {
                continue;
            }

            if (papers.at(x_).at(y_) == paper) {
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
int solve_part1(const vector<string> &papers) {
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
int solve_part2(const vector<string> &papers) {
    printPapers(papers);
    auto papers_cpy = papers;
    auto papers_prev = papers;
    int removed_papers = 0;
    int removed_papers_prev = -1;

    const auto x_max = papers.at(0).size();
    const auto y_max = papers.size();
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

int main(int argc, char *argv[]) {
    const auto example = loadExample(4);
    const auto puzzle = loadPuzzle(4);
    const auto count = solve_part2(puzzle);

    cout << "Solution: " << count << endl;
    return 0;
}
