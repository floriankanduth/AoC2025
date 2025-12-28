/**
* https://adventofcode.com/2025/day/6
 */

#include "day6.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
constexpr char sum = '+';
constexpr char mul = '*';

/**
 *  Remove whitespace and split input into number and operands.
 *  Numbers are in rows 0...n-1
 *  Operands are in row n
 *
 * @param input input as vector of strings
 * @return tokenized input
 */
std::vector<std::vector<std::string> > parse_input(const std::vector<std::string> &input) {
    std::vector<std::vector<std::string> > tokens;

    for (const auto &line: input) {
        constexpr char del = ' ';
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> token_line;

        while (getline(ss, token, del)) {
            if (!token.empty()) {
                token_line.push_back(token);
            }
        }

        tokens.push_back(token_line);
    }

    return tokens;
}

/**
 * Get operand in last row in column col.
 *
 * @param tokens 2d array of input tokens
 * @param col column of operand
 * @return
 */
constexpr char get_operator(const std::vector<std::vector<std::string> > &tokens, const int col) {
    const char op = tokens.at(tokens.size() - 1).at(col).at(0);
    return op;
}

/**
 * sum all numbers in a column.
 *
 * @param tokens 2d array of input tokens
 * @param col column index to sum
 * @return sum of column
 */
unsigned long sum_col(const std::vector<std::vector<std::string> > &tokens, const int col) {
    unsigned long sum = 0;

    for (int i = 0; i < tokens.size() - 1; ++i) {
        const unsigned long number = stoul(tokens.at(i).at(col));
        sum += number;
    }
    return sum;
}


/**
 * multiply all numbers in a column.
 *
 * @param tokens 2d array of input tokens
 * @param col column index to multiply
 * @return product of column
 */
unsigned long mul_col(const std::vector<std::vector<std::string> > &tokens, const int col) {
    unsigned long prod = 1;

    for (int i = 0; i < tokens.size() - 1; ++i) {
        const unsigned long number = stoul(tokens.at(i).at(col));
        prod *= number;
    }

    return prod;
}

int run_day6(const std::vector<std::string> &input) {
    const std::vector<std::vector<std::string> > tokens = parse_input(input);
    unsigned long long result = 0;

    for (int i = 0; i < tokens.at(0).size(); ++i) {
        switch (get_operator(tokens, i)) {
            case sum:
                result += sum_col(tokens, i);
                break;

            case mul:
                result += mul_col(tokens, i);
                break;

            default:
                assert(false && "Unknown operator");
        }
    }

    std::cout << result << std::endl;
    return 0;
}
