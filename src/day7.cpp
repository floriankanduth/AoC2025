/**
 * https://adventofcode.com/2025/day/7
 */

#include "day7.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "TokenField.h"

auto solve_part1(day7::TokenField &field) {
    int splits = 0;

    for (int i = 1; i < field.get_height(); ++i) {
        //copy beams, so we can add new ones without changing the loop
        const std::set<unsigned int> beams = field.beams;

        for (const unsigned int &beam: beams) {
            //create 2 new beams on splitter
            if (field.get_token(beam, i) == day7::Splitter) {
                field.insert_beam(beam - 1, i);
                field.insert_beam(beam + 1, i);
                field.destroy_beam(beam);
                splits++;
            } else {
                //pass through existing beam
                field.insert_beam(beam, i);
            }
        }

        field.print();
        printf("Number of splits: %d\n\n\n\n", splits);
    }
    return splits;
}

int run_day7(const std::vector<std::string> &input) {
    auto field = day7::TokenField(input);
    field.print();
    solve_part1(field);

    return 0;
}
