#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Grid.h"

bool is_valid_move(Grid &maze, int row, int col, int level) {
    return row >= 0 && row < maze.height() && col >= 0 && col < maze.width() &&
           level >= 0 && level < maze.depth() && maze.at(row, col, level) == 1;
}

bool find_maze_path(Grid &maze, int row, int col, int level, std::vector<std::tuple<int, int, int>> &solution) {
    if (row == maze.height() - 1 && col == maze.width() - 1 && level == maze.depth() - 1) {
        solution.push_back(std::make_tuple(row, col, level));
        return true;
    }

    if (!is_valid_move(maze, row, col, level)) {
        return false;
    }

    maze.at(row, col, level) = 2;
    solution.push_back(std::make_tuple(row, col, level));

    if (find_maze_path(maze, row + 1, col, level, solution) ||
        find_maze_path(maze, row - 1, col, level, solution) ||
        find_maze_path(maze, row, col + 1, level, solution) ||
        find_maze_path(maze, row, col - 1, level, solution) ||
        find_maze_path(maze, row, col, level + 1, solution) ||
        find_maze_path(maze, row, col, level - 1, solution)) {
        return true;
    }

    solution.pop_back();
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_maze_file> <output_solution_file>" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream outFile(argv[2]);
    if (!outFile) {
        std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
        return 1;
    }

    Grid maze;
    inFile >> maze;

    std::vector<std::tuple<int, int, int>> solution;

    if (find_maze_path(maze, 0, 0, 0, solution)) {
        outFile << "SOLUTION\n";
        for (const auto &step : solution) {
            outFile << std::get<0>(step) << " " << std::get<1>(step) << " " << std::get<2>(step) << std::endl;
        }
    } else {
        outFile << "NO SOLUTION\n";
    }

    return 0;
}
