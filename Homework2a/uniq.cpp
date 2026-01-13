#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <unordered_set>

int main(int argc, char const* argv[]) {
    std::unordered_set<std::string> seenLines;
    std::istream* input = &std::cin;
    std::ifstream file;


    if (argc == 2) {
        file.open(argv[1]);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << argv[1] << std::endl;
            return 1;
        }
        input = &file;
    }

    std::string line;

    while (std::getline(*input, line)) {
        if (seenLines.find(line) == seenLines.end()) {
            std::cout << line << std::endl;
            seenLines.insert(line);
        }
    }

    if (file.is_open()) {
        file.close();
    }

    return 0;
}
