#include <algorithm>

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
    template<typename T>
    size_t calculate_value(vector<T> numbers, char op) {
        auto add = [](T a, T b) { return a + b; };
        auto mul = [](T a, T b) { return a * b; };

        size_t value{0};
        if (op == '*') {
            value = std::accumulate(std::next(numbers.begin()), numbers.end(), numbers[0], mul);
        } else if (op == '+') {
            value = std::accumulate(numbers.begin(), numbers.end(), 0, add);
        } else {
            throw std::runtime_error(std::format("Invalid operator {}", op));
        }
        return value;
    }

public:
    std::string part_1(const std::vector<std::string> &lines) override {
        vector<vector<int> > numbers{};
        for (size_t i = 0; i < lines.size() - 1; i++) {
            numbers.emplace_back();
            const auto &line = lines[i];
            const auto line_nums = split_by_regex(line, std::regex("\\W+"));
            for (const auto &num: line_nums) {
                numbers[numbers.size() - 1].emplace_back(std::stoi(num));
            }
        }
        const auto height = numbers.size();
        const auto width = numbers[0].size();
        const auto &operator_string = lines[lines.size() - 1];
        const auto operators = split_by_regex(operator_string, std::regex(" *"));
        size_t total_sum{0};
        for (size_t x = 0; x < width; x++) {
            size_t col_result{0};
            for (size_t y = 0; y < height; y++) {
                if (const auto op = operators[x][0]; op == '*') {
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
        return std::format("{}", total_sum);
    }


    std::string part_2(const std::vector<std::string> &lines) override {
        auto op = '?';
        std::vector<size_t> current_numbers{};

        auto max_x = std::ranges::max_element(lines.begin(), lines.end(), [](auto l1, auto l2) {
            return l1.size() < l2.size();
        })->size();

        size_t total_sum = 0;
        for (size_t x = 0; x < max_x; x++) {
            std::string col_value;
            for (size_t y = 0; y < lines.size() - 1; y++) {
                if (x >= lines.at(y).size()) continue; //the last line might be shorter
                auto current_char = lines.at(y).at(x);
                col_value += current_char;
            }

            if (std::ranges::all_of(col_value, [](const char c) { return c == ' '; })) {
                //empty column = new equation

                total_sum += calculate_value(current_numbers, op);
                op = '?';
                current_numbers = {};
                continue;
            }
            current_numbers.emplace_back(std::stoi(col_value));

            if (auto &last_line = lines[lines.size() - 1]; x < last_line.size()) {
                if (const auto possibleOperator = last_line[x]; possibleOperator != ' ') {
                    op = possibleOperator;
                }
            }
        }
        //last column is not preced by whitespace so has to be cleared manually
        total_sum += calculate_value(current_numbers, op);

        return std::format("{}", total_sum);
    }
};
