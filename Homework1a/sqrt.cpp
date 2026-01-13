#include <iostream>
#include <cstdlib>
#include <cmath>

int main(int argc, char* argv[]) {
    double x = std::atof(argv[1]);

    if (x < 0) {
        std::cout << "Input must be greater than 0" << std::endl;
        return 1;
    }

    double lower = 0;
    double upper = x;
    double midpt;

    while (true) {
        midpt = (lower + upper) / 2.0;
        double square = midpt * midpt;
        std::cout << midpt << " (" << square << ")" << std::endl;

        if (std::abs(square - x) < 0.0001) {
            break;
        }

        if (square > x) {
            upper = midpt;
        } else {
            lower = midpt;
        }
    }

    return 0;
}