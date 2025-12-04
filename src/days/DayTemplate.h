//
// Created by Tobias Oftedal on 27/11/2025.
//


#ifndef AOC_2022_DAYTEMPLATE_H
#define AOC_2022_DAYTEMPLATE_H

#pragma once
#include <string>
#include <vector>


class DayTemplate {
public:
    virtual std::string part_1(const std::vector<std::string> &lines) = 0;

    virtual std::string part_2(const std::vector<std::string> &lines) = 0;

    virtual ~DayTemplate() = default;
};
#endif //AOC_2022_DAYTEMPLATE_H
