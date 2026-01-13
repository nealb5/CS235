#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void insertion_sort(std::vector<std::string>& lines) {
    for (size_t i = 1; i < lines.size(); ++i) {
        std::string key = lines[i];
        int j = i - 1;

        while (j >= 0 && lines[j] > key) {
            lines[j + 1] = lines[j];
            --j;
        }
        lines[j + 1] = key;
    }
}

int main(int argc, char const* argv[]) {
    std::vector<std::string> lines;
    std::string line;

    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "Error: Could not open file " << argv[1] << std::endl;
            return 1;
        }

        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        while (std::getline(std::cin, line)) {
            lines.push_back(line);
        }
    }

    insertion_sort(lines);

    for (const auto& sorted_line : lines) {
        std::cout << sorted_line << std::endl;
    }

    return 0;
}
