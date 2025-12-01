#include <algorithm>
#include <charconv>

#include "DayTemplate.h"
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <stack>
#include <vector>
#include <iomanip>
#include "../utility/visual.h"


using std::endl, std::cout, std::string, std::vector, std::stack, std::format, std::println;


//8 er feil


class Day_1 final : public DayTemplate {
public:
    std::string part_1(const std::vector<std::string> &lines) override {
        int zero_counter = 0;
        int turn = 50;
        for (auto &line: lines) {
            char direction = line[0];
            int new_turn;
            std::from_chars(line.data() + 1, line.data() + line.size(), new_turn);
            if (direction == 'R') {
                turn += new_turn;
            } else if (direction == 'L') {
                turn -= new_turn;
            } else {
                throw std::runtime_error(std::format("invalid line: '{}'", line));
            }
            if (turn < 0) {
                turn += 100;
            }
            turn %= 100;
            println("{}", turn);
            if (turn == 0) { zero_counter++; }
        }

        return std::to_string(zero_counter);
    }

    std::string part_2(const std::vector<std::string> &lines) override {
        int zero_counter = 0;
        int turn = 50;
        for (auto &line: lines) {
            char direction = line[0];
            int new_turn;
            std::from_chars(line.data() + 1, line.data() + line.size(), new_turn);
            int prev = turn;
            if (direction == 'R') {
                turn += new_turn;
            } else if (direction == 'L') {
                turn -= new_turn;
            } else {
                throw std::runtime_error(std::format("invalid line: '{}'", line));
            }
            int before_calc = turn;
            while (turn < 0) {
                turn += 100;
                zero_counter++;
                println("    added ");
            }
            while (turn > 100) {
                turn -= 100;
                zero_counter++;
                println("    added ");
            }
            println("{}, went from {} to  {}", turn , prev, before_calc);
        }

        return std::to_string(zero_counter);
    }

    ~Day_1() override = default;
};

//3175 for lavt
//5986 er for lavt
//1348005
//12785886
