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
            int new_turn;
            std::from_chars(line.data() + 1, line.data() + line.size(), new_turn);
            char direction = line[0];
            for (int i = 0; i < new_turn; i++) {
                if (direction == 'R') {
                    turn += 1;
                } else if (direction == 'L') {
                    turn -= 1;
                } else {
                    throw std::runtime_error(std::format("invalid line: '{}'", line));
                }
                if (turn == -1) {
                    turn = 99;
                }
                if (turn == 100) {
                  turn = 0;
                }
                if (turn == 0) {
                    zero_counter++;
                }

            }
            println("The dial is rotated {} to point at {}", line, turn);

        }

        return std::to_string(zero_counter);
    }

    ~Day_2() override = default;
};


//6498

//0.014984583