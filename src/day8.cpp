/**
 * https://adventofcode.com/2025/day/8
 */

#include "day8.h"
#include <cmath>
#include <string>
#include <vector>
#include <bits/valarray_after.h>

struct Coord {
    int x, y, z;
};

/**
 * Square an integer
 * @param x integer to square
 * @return x^2
 */
constexpr float sqri(const int x) { return x * x; }

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
    return 0;
}
