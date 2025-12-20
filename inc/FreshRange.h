//
// Created by flo on 20.12.25.
//

#ifndef AOC_FRESHRANGE_H
#define AOC_FRESHRANGE_H
#include <string>


class FreshRange {
public:
    unsigned long from;
    unsigned long to;

    FreshRange(int from, int to);

    FreshRange(const std::string &line);

    bool contains(const unsigned long &number) const;

    bool overlaps(const FreshRange &other) const;

    FreshRange operator+=(const FreshRange &other);

    FreshRange operator+(const FreshRange &other) const;

    bool operator<(const FreshRange &other) const;

    bool operator>(const FreshRange &other) const;

    bool operator==(const FreshRange &other) const;

    bool operator!=(const FreshRange &other) const;
};


#endif //AOC_FRESHRANGE_H
