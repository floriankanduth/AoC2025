#include <string>

#include "../inc/day1.h"
#include "../inc/day2.h"

using namespace std;

int main(int argc, char **argv) {
    switch (stoi(argv[1])) {
        case 1:
            solve_day1();
        default: break;
    }
}
