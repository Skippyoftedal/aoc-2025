#include <algorithm>

#include "DayTemplate.h"
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <stack>
#include <vector>
#include "../utility/visual.h"
#include <set>
using std::endl, std::pair, std::cout, std::string, std::vector, std::stack, std::format, std::println;


vector<pair<int, int> > get_directions() {
    return {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
}

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
    return {a.first + b.first, a.second + b.second};
}


std::set<pair<int, int> > find_initial_blocked_yx(const auto &lines) {
    std::set<pair<int, int> > blocked_yx{};
    const size_t SIDE = lines.size();

    for (size_t y = 0; y < SIDE; y++) {
        for (size_t x = 0; x < SIDE; x++) {
            if (lines[y][x] == '@') {
                blocked_yx.emplace(y, x);
            }
        }
    }
    return blocked_yx;
}


class Day_4 final : public DayTemplate {
public:
    std::string part_1(const std::vector<std::string> &lines) override {
        const auto blocked_yx = find_initial_blocked_yx(lines);
        const auto directions = get_directions();
        auto total_match_count = 0;
        for (const auto &p: blocked_yx) {
            auto block_count = 0;
            for (const auto &dir: directions) {
                const auto search = p + dir;
                if (blocked_yx.contains(search)) {
                    block_count++;
                }
            }
            if (block_count < 4) {
                total_match_count++;
            }
        }
        return std::format("{}", total_match_count);
    }


    std::string part_2(const std::vector<std::string> &lines) override {
        auto blocked_yx = find_initial_blocked_yx(lines);
        const auto directions = get_directions();
        size_t total_removed = 0;

        std::set<pair<int, int> > to_remove{};
        while (true) {
            for (const auto &p: blocked_yx) {
                auto block_count = 0;
                for (const auto &dir: directions) {
                    const auto search = p + dir;
                    if (blocked_yx.contains(search)) {
                        block_count++;
                    }
                }
                if (block_count < 4) {
                    to_remove.emplace(p);
                }
            }
            if (to_remove.empty()) {
                break;
            }
            std::vector<pair<int,int>> diff{};
            std::ranges::set_difference(blocked_yx, to_remove, std::back_inserter(diff));
            blocked_yx = std::set(diff.begin(), diff.end());
            total_removed += to_remove.size();
            to_remove = {};
        }
        return std::format("{}", total_removed);
    }
};
