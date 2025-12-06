#include <algorithm>

#include "DayTemplate.h"
#include <iostream>
#include <ranges>
#include <regex>
#include <string>
#include <stack>
#include <vector>
#include "../utility/visual.h"
#include "../utility/util.h"

using std::endl, std::pair, std::cout, std::string, std::vector, std::stack, std::format, std::println;

class IngredientRange {
public:
    size_t start;
    size_t end;

    IngredientRange(size_t start, size_t end) : start(start), end(end) {
    }

    [[nodiscard]] constexpr bool is_in_range(const size_t ingredient) const {
        return start <= ingredient && ingredient <= end;
    }

    void merge(const IngredientRange &range2) {
        this->start = std::ranges::min(this->start, range2.start);
        this->end = std::ranges::max(this->end, range2.end);
    }

    string to_string() const {
        return std::format("[{}->{}]", start, end);
    }
};

class SuperRange {
    std::vector<IngredientRange> ranges;

public:
    SuperRange() = default;

    void check_overlap() {
        for (size_t i = 0; i < ranges.size(); i++) {
            for (size_t j = 0; j < ranges.size(); j++) {
                if (i == j){ continue;}
                auto range_a = ranges[i];
                auto range_b = ranges[j];
                if (range_a.is_in_range(range_b.start) || range_a.is_in_range(range_b.end)) {
                    throw std::runtime_error("case 1");
                }
                if (range_b.is_in_range(range_a.start) || range_b.is_in_range(range_a.end)) {
                    throw std::runtime_error(std::format("case 2: {}{}", range_a.to_string(), range_b.to_string()));//problem med fully enclosed
                }
            }
        }
    }

    void add_range(IngredientRange range_to_insert) {
        std::erase_if(ranges,
                      [&](const auto &range) {
                          if (range.is_in_range(range_to_insert.start)
                              || range.is_in_range(range_to_insert.end)
                              || range_to_insert.is_in_range(range.start)
                              || range_to_insert.is_in_range(range.end)) {
                              range_to_insert.merge(range);
                              return true;
                          }
                          return false;
                      });
        ranges.emplace_back(range_to_insert);
    }

    [[nodiscard]] size_t get_size() const {
        size_t size{0};
        for (const auto &range: ranges) {
            size += range.end - range.start + 1;
        }
        return size;
    }
};


vector<IngredientRange> parse_ranges(const vector<string> &range_lines) {
    vector<IngredientRange> ranges;
    for (const auto &line: range_lines) {
        const auto nums = split_by_regex(line, std::regex("-")) | std::views::transform([](const auto &s) {
            return std::stol(s);
        });
        ranges.emplace_back(nums[0], nums[1]);
    }
    return ranges;
}

class Day_5 final : public DayTemplate {
public:
    std::string part_1(const std::vector<std::string> &lines) override {
        auto empty_line_it = std::ranges::find_if(lines, [](const auto &line) { return line.empty(); });
        vector ranges_lines(lines.begin(), empty_line_it);
        const auto ranges = parse_ranges(ranges_lines);
        const vector ids(std::next(empty_line_it), lines.end());
        size_t valid_ids{0};
        for (const auto &id_as_str: ids) {
            size_t id_as_long = std::stol(id_as_str);
            bool id_is_valid = false;
            for (const auto &range: ranges) {
                if (range.is_in_range(id_as_long)) {
                    id_is_valid = true;
                    break;
                }
            }
            if (id_is_valid) valid_ids++;
        }
        return std::format("{}", valid_ids);
    }


    std::string part_2(const std::vector<std::string> &lines) override {
        auto empty_line_it = std::ranges::find_if(lines, [](const auto &line) { return line.empty(); });
        vector ranges_lines(lines.begin(), empty_line_it);
        const auto ranges = parse_ranges(ranges_lines);


        SuperRange super_range{};
        for (auto &range: ranges) {
            super_range.add_range(range);
        }
        super_range.check_overlap();

        return std::format("{}", super_range.get_size());
    }
};