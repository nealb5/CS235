#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int countWords(const std::string& line) {
    std::istringstream iss(line);
    int wordCount = 0;
    std::string word;
    while (iss >> word) {
        wordCount++;
    }
    return wordCount;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line, longestLine;
    int maxWords = 0;

    while (std::getline(inputFile, line)) {
        int wordCount = countWords(line);
        if (wordCount > maxWords) {
            maxWords = wordCount;
            longestLine = line;
        }
    }

    inputFile.close();

    if (!longestLine.empty()) {
        std::cout << longestLine << std::endl;
    }

    return 0;
}
