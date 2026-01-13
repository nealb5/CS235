#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "prod requires 2 arguments" << std::endl;
        return 1;
    }

    try {
        double num1 = std::stod(argv[1]);
        double num2 = std::stod(argv[2]);
        double result = num1 * num2;
        std::cout << num1 << " * " << num2 << " = " << result << std::endl;
    } catch (...) {
        std::cerr << "Invalid input: Arguments must be numbers." << std::endl;
        return 1;
    }

    return 0;
}
