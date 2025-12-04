
#include <filesystem>
#include <iostream>
#include <ostream>
#include "src/utility/file_reading.h"
#include "src/days/day_2.cpp"

template<typename F>
auto time_it(const F& func) {
    const auto start = std::chrono::high_resolution_clock::now();
    const auto result = func();
    const auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    return std::make_pair(result, elapsed);
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

    //std::cout << "cwd: " << std::filesystem::current_path() << std::endl;
    const auto is_test =false ;
    const auto lines = read_lines(2, is_test);

    if (lines.empty()) {
        std::cerr << "found no lines in the file for selected day" << std::endl;
        return 1;
    }
    std::cout << "Read file with " << lines.size() << " lines\n" << std::endl;

    const auto [p1, p1_time] = time_it(
        [lines](){return Day_2().part_1(lines);}
        );

    const auto [p2, p2_time] = time_it(
        [lines](){return Day_2().part_2(lines);}
        );

    //3175 er for lavt

     std::cout << std::format("p1: {}, took {} seconds\n", p1, p1_time.count());
    std::cout << std::format("p2: {}, took {} seconds\n", p2 , p2_time.count()) << endl;
    return 0;
};