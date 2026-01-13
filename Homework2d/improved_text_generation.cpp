#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::unordered_map<std::string, std::vector<std::string>> trainModel(std::istream &in) {
    std::unordered_map<std::string, std::vector<std::string>> model;
    std::string prev1 = "";
    std::string prev2 = "";
    std::string curr;

    while (in >> curr) {
        std::string key = prev1 + " " + prev2;
        model[key].push_back(curr);

        prev1 = prev2;
        prev2 = curr;
    }
    return model;
}

void generateText(const std::unordered_map<std::string, std::vector<std::string>>& model, std::string start, int numWords, std::ostream &out) {
    std::string word1 = "";
    std::string word2 = "";
    srand(time(0));

    for (int i = 0; i < numWords; ++i) {
        std::string key = word1 + " " + word2;
        auto it = model.find(key);
        if (it != model.end() && !it->second.empty()) {
            const std::vector<std::string>& nextWords = it->second;
            std::string nextWord = nextWords[rand() % nextWords.size()];

            out << nextWord << " ";
            word1 = word2;
            word2 = nextWord;
        } else {
            word1 = "";
            word2 = "";
        }
    }
    out << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <num_words>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    int numWords = std::stoi(argv[2]);
    std::unordered_map<std::string, std::vector<std::string>> model = trainModel(inputFile);
    generateText(model, "", numWords, std::cout);

    return 0;
}
