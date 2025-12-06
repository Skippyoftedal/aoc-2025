//
// Created by Tobias Oftedal on 15/11/2025.
//
#pragma once
#include <ostream>
#include <queue>
#ifndef AOC_2022_VISUAL_H
#define AOC_2022_VISUAL_H
#include <iosfwd>
#include <set>
#include <stack>
#include <__ranges/drop_view.h>

template<typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    os << "[";
    if (!vec.empty()) {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            os << ", " << vec[i];
        }
    }
    os << "]";
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &set) {
    os << "{";
    auto it = set.begin();
    if (!set.empty()) {
        os << *it;
        ++it;
        while (it != set.end()) {
            os << ", " << *it;
            ++it;
        }
    }
    os << "}";
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::queue<T> q) {
    os << "[";
    bool first = true;
    while (!q.empty()) {
        if (!first) os << "<-";
        os << q.front();
        q.pop();
        first = false;
    }
    os << "]";
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::stack<T> s) {
    os << "[";
    bool first = true;
    while (!s.empty()) {
        if (!first) os << "->";
        os << s.top();
        s.pop();
        first = false;
    }
    os << "]";
    return os;
}


class ANSI_COLOR {
public:
    static constexpr auto RESET = "\033[0m";
    static constexpr auto RED   = "\033[31m";
    static constexpr auto GREEN = "\033[32m";
    static constexpr auto BLUE  = "\033[34m";
    static constexpr auto YELLOW = "\033[33m";
    static constexpr auto CYAN   = "\033[36m";
    static constexpr auto MAGENTA = "\033[35m";
    static constexpr auto WHITE   = "\033[37m";
    static constexpr auto BG_BLACK   = "\033[40m";
    static constexpr auto BG_RED     = "\033[41m";
    static constexpr auto BG_GREEN   = "\033[42m";
    static constexpr auto BG_YELLOW  = "\033[43m";
    static constexpr auto BG_BLUE    = "\033[44m";
    static constexpr auto BG_MAGENTA = "\033[45m";
    static constexpr auto BG_CYAN    = "\033[46m";
    static constexpr auto BG_WHITE   = "\033[47m";
};

#endif //AOC_2022_VISUAL_H
