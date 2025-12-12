#ifndef AOC_COMMON_H
#define AOC_COMMON_H
#include <string>
#include <vector>
//#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif


std::vector<std::string> readFile(int day);

#endif //AOC_COMMON_H