#include "DayTemplate.h"
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <string>
#include <stack>
#include <vector>
#include "../utility/visual.h"
#include "../utility/util.h"

using std::endl, std::pair, std::cout, std::string, std::vector, std::stack, std::format, std::println;


class Day_6 final : public DayTemplate {
public:
    std::string part_1(const std::vector<std::string> &lines) override {
        return "";
        vector<vector<int> > numbers{};
        for (size_t i = 0; i < lines.size() - 1; i++) {
            numbers.emplace_back();
            println("{}", lines[i]);
            const auto &line = lines[i];
            const auto line_nums = split_by_regex(line, std::regex("\\W+"));
            for (const auto &num: line_nums) {
                numbers[numbers.size() - 1].emplace_back(std::stoi(num));
            }
        }
        const auto height = numbers.size();
        const auto width = numbers[0].size();
        const auto& operator_string = lines[lines.size() - 1];
        const auto operators = split_by_regex(operator_string, std::regex(" *"));
        println("{}", operators);
        size_t total_sum{0};
        for (size_t x = 0; x < width; x++) {
            size_t col_result{0};
            for (size_t y = 0; y < height; y++) {
                auto op = operators[x][0];
                if (op == '*') {
                    if (col_result == 0) {
                        col_result = numbers[y][x];
                    } else {
                        col_result *= numbers[y][x];
                    }
                } else if (op == '+') {
                    col_result += numbers[y][x];
                }
            }
            total_sum += col_result;
        }
        println("{}", numbers);

        return std::format("{}", total_sum);
    }


    std::string part_2(const std::vector<std::string> &lines) override {

        vector<vector<int> > numbers{};
        for (size_t i = 0; i < lines.size() - 1; i++) {
            numbers.emplace_back();
            println("{}", lines[i]);
            const auto &line = lines[i];
            const auto line_nums = split_by_regex(line, std::regex("\\W+"));
            for (const auto &num: line_nums) {
                numbers[numbers.size() - 1].emplace_back(std::stoi(num));
            }
        }
        const auto height = numbers.size();
        const auto width = numbers[0].size();
        const auto& operator_string = lines[lines.size() - 1];
        const auto operators = split_by_regex(operator_string, std::regex(" *"));
        println("{}", operators);
        size_t total_sum{0};
        for (size_t x = 0; x < width; x++) {
            size_t col_result{0};
            for (size_t y = 0; y < height; y++) {
                auto op = operators[x][0];
                if (op == '*') {
                    if (col_result == 0) {
                        col_result = numbers[y][x];
                    } else {
                        col_result *= numbers[y][x];
                    }
                } else if (op == '+') {
                    col_result += numbers[y][x];
                }
            }
            total_sum += col_result;
        }
        println("{}", numbers);

        return std::format("{}", total_sum);
        return std::format("{}", "");
    }
};
