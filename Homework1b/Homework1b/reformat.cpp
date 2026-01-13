#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input_file output_file" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string firstName, lastName;
    int points;
    double factor;

    while (inputFile >> firstName >> lastName >> points >> factor) {
        double newPoints = points * factor;
        outputFile << lastName << ", " << firstName << ": " << newPoints << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}