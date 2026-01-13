#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    int n = std::atoi(argv[1]);

    while (n != 1) {
        std::cout << n << std::endl;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }

    std::cout << n << std::endl;
    return 0;
}