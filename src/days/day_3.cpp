#include "DayTemplate.h"
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <stack>
#include <vector>
#include "../utility/visual.h"

using std::endl, std::pair, std::cout, std::string, std::vector, std::stack, std::format, std::println;


class Day_3 final : public DayTemplate {
public:
    std::string part_1(const std::vector<std::string> &lines) override {
        auto total = 0;
        for (const auto &line: lines) {
            char first = '0';
            char second = '0';
            for (size_t char_index = 0; char_index < line.size(); char_index++) {
                if (line[char_index] > first && char_index != line.size() - 1) {
                    first = line[char_index];
                    second = '0';
                } else if (line[char_index] > second) {
                    second = line[char_index];
                }
            }
            total += (first - '0') * 10 + (second - '0');
        }
        return std::format("{}", total);
    }


    std::string part_2(const std::vector<std::string> &lines) override {
        size_t total = 0;
        for (const auto &line: lines) {
            vector<char> result = std::vector(12, '!');
            for (size_t char_index = 0; char_index < line.size(); char_index++) {
                for (size_t num_index = 0; num_index < result.size(); num_index++) {
                    auto last_reachable_index = line.size() - (11 - num_index);
                    if (line[char_index] > result[num_index] && char_index < last_reachable_index) {
                        result[num_index] = line[char_index];
                        for (size_t refresh_index = num_index + 1; refresh_index < result.size(); refresh_index++) {
                            result[refresh_index] = '!';
                        }
                        break;
                    }
                }
            }

            string str_value = string(result.begin(), result.end());
            total += std::stol(str_value);
        }
        return std::format("{}", total);
    }
};

//00467925
