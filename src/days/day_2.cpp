#include "DayTemplate.h"
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <stack>
#include <vector>
#include <iomanip>
#include "../utility/visual.h"
#include "../utility/util.h"

using std::endl, std::pair, std::cout, std::string, std::vector, std::stack, std::format, std::println;


bool is_valid2(const size_t int_value) {
    auto s_val = std::to_string(int_value);
    for (size_t div_len = s_val.size() / 2; div_len > 0; --div_len) {
        if (s_val.size() % div_len == 0) {
            auto str_count = s_val.size() / div_len;
            bool is_valid = true;
            auto first = s_val.substr(0, div_len);
            for (auto i = 0; i < str_count; i++) {
                if (first != s_val.substr(div_len * i, div_len)) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                return true;
            }
        }
    }
    return false;
}

class Day_2 final : public DayTemplate {
public:
    std::string part_1(const std::vector<std::string> &lines) override {
        auto pair_strings = split_by_regex(lines[0], std::regex(","));
        size_t sum = 0L;
        for (const auto &line: pair_strings) {
            auto pair_content = split_by_regex(line, std::regex("-"));
            size_t int_1 = std::stol(pair_content[0]);
            size_t int_2 = std::stol(pair_content[1]);
            while (int_1 <= int_2) {
                auto s_val = std::to_string(int_1);
                if (s_val.size() % 2 == 0) {
                    auto first_part = s_val.substr(0, s_val.size() / 2);
                    auto second_part = s_val.substr(s_val.size() / 2);
                    if (first_part == second_part) {
                        sum += int_1;
                    }
                }
                int_1++;
            }
        }
        return std::format("{}", sum);
    }


    std::string part_2(const std::vector<std::string> &lines) override {
        auto pair_strings = split_by_regex(lines[0], std::regex(","));
        size_t sum = 0L;
        for (const auto &line: pair_strings) {
            auto pair_content = split_by_regex(line, std::regex("-"));
            size_t int_1 = std::stol(pair_content[0]);
            size_t int_2 = std::stol(pair_content[1]);
            while (int_1 <= int_2) {
                if (is_valid2(int_1)) {
                    sum += int_1;
                }
                int_1++;
            }
        }
        return std::to_string(sum);
    }
};