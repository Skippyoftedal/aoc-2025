cmake_minimum_required(VERSION 4.0)
project(aoc_2025)

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-o0)

file(GLOB ALL_DAYS "src/days/*")
file(GLOB UTILITY "src/utility/*")
file(GLOB RESOURCES "resources/*")


add_executable(aoc_2025 main.cpp ${All_DAYS} ${UTILITY}
)
