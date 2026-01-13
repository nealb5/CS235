#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int start = std::atoi(argv[1]);
    int end = std::atoi(argv[2]);
    int divisor = std::atoi(argv[3]);

    if (start <= end) {
        for (int i = start; i <= end; ++i) {
            if (i % divisor == 0) {
                std::cout << i << std::endl;
            }
        }
    } else {
        for (int i = start; i >= end; --i) {
            if (i % divisor == 0) {
                std::cout << i << std::endl;
            }
        }
    }
    return 0;
}