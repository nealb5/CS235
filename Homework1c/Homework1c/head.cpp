#include <iostream>
#include <fstream>
#include <string>

void print_lines(std::istream& input, int n) {
    std::string line;
    for (int i = 0; i < n && std::getline(input, line); ++i) {
        std::cout << line << std::endl;
    }
}

int main(int argc, char const* argv[]) {
    int num_lines = 10;

    if (argc == 1) {
        print_lines(std::cin, num_lines);
    }
    else if (argc == 2) {
        std::string arg1 = argv[1];
        if (arg1[0] == '-') {
            num_lines = std::stoi(arg1.substr(1));
            print_lines(std::cin, num_lines);
        } else {
            std::ifstream file(arg1);
            if (!file) {
                std::cerr << "ERROR: can't open " << arg1 << std::endl;
                return 1;
            }
            print_lines(file, num_lines);
        }
    }
    else if (argc == 3) {
        std::string arg1 = argv[1];
        if (arg1[0] == '-') {
            num_lines = std::stoi(arg1.substr(1));
            std::ifstream file(argv[2]);
            if (!file) {
                std::cerr << "ERROR: can't open " << argv[2] << std::endl;
                return 1;
            }
            print_lines(file, num_lines);
        } else {
            std::cerr << "Usage: " << argv[0] << " [-n] [file]" << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Usage: " << argv[0] << " [-n] [file]" << std::endl;
        return 1;
    }

    return 0;
}
