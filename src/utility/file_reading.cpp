#include <fstream>
#include <iostream>
#include <vector>

#include "file_reading.h"


std::vector<std::string> read_lines(const int day, const bool is_test_file) {
    std::string path;
    if (is_test_file) {
        path = "resources/test/" + std::to_string(day) + ".txt";
    } else {
        path = "resources/input/" + std::to_string(day) + ".txt";
    }
    std::cout << "Reading path: " << path << std::endl;

    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    file.open(path);

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    return lines;
}