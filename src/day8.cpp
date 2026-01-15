/**
 * https://adventofcode.com/2025/day/8
 */

#include "day8.h"
#include <cmath>
#include <set>
#include <string>
#include <vector>

struct Coord {
    int x, y, z;
};

/**
 * Square an integer
 * @param x integer to square
 * @return x^2
 */
constexpr float sqri(const int x) { return static_cast<float>(x * x); }

/**
 * Calculate the Euclidian distance from point a to point b.
 * @param a Coordinate a
 * @param b Coordinate b
 * @return Euclidean distance from a to b
 */
constexpr float dist(const Coord &a, const Coord &b) {
    return std::sqrt(sqri(a.x - b.x) + sqri(a.y - b.y) + sqri(a.z - b.z));
}

int run_day8(const std::vector<std::string> &) {
    std::multiset<float> distances;
    std::vector<std::vector<int> > circuits;


    return 0;
}
