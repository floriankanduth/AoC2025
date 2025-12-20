#include "../inc/FreshRange.h"

FreshRange::FreshRange(const int from, const int to) : from(from), to(to) {
}

FreshRange::FreshRange(const std::string &line) {
    const auto sep = line.find('-');

    from = stoul(line.substr(0, sep));
    to = stoul(line.substr(sep + 1));
}

bool FreshRange::contains(const unsigned long &number) const {
    return from <= number && number <= to;
}

bool FreshRange::overlaps(const FreshRange &other) const {
    return this->contains(other.from) || this->contains(other.to);
}

FreshRange FreshRange::operator+=(const FreshRange &other) {
    from += other.from;
    to += other.to;
    return *this;
}

FreshRange FreshRange::operator+(const FreshRange &other) const {
    FreshRange tmp = *this;
    tmp += other;
    return tmp;
}

bool FreshRange::operator<(const FreshRange &other) const {
    return from < other.from;
}

bool FreshRange::operator>(const FreshRange &other) const {
    return from > other.from;
}

bool FreshRange::operator==(const FreshRange &other) const {
    return from == other.from && to == other.to;
}

bool FreshRange::operator!=(const FreshRange &other) const {
    return !(*this == other);
}

