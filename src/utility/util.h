//
// Created by Tobias Oftedal on 06/12/2025.
//

#ifndef AOC_2025_UTIL_H
#define AOC_2025_UTIL_H
#include <regex>
#include <vector>

inline std::vector<std::string> split_by_regex(const std::string &text, const std::regex &re) {
    std::vector<std::string> result;
    std::sregex_token_iterator it(text.begin(), text.end(), re, -1);
    std::sregex_token_iterator end;
    while (it != end) {
        if (!it->str().empty()) {
            result.push_back(*it);
        }
        ++it;
    }
    return result;
}



#endif //AOC_2025_UTIL_H