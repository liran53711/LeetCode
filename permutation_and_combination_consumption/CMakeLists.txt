cmake_minimum_required(VERSION 3.31)
project(permutation_and_combination_consumption)

set(CMAKE_CXX_STANDARD 20)

add_executable(permutation_and_combination_consumption main.cpp
        src/combinations/no_repetition/full_perm/basic_perm.cpp
        src/combinations/no_repetition/full_perm/basic_perm.h
        src/combinations/no_repetition/full_perm/fixed_position.cpp
        src/combinations/no_repetition/full_perm/fixed_position.h
        src/combinations/no_repetition/full_perm/order_constraint.cpp
        src/combinations/no_repetition/full_perm/order_constraint.h
        src/combinations/no_repetition/partial_perm/basic_partial.cpp
        src/combinations/no_repetition/partial_perm/basic_partial.h
        src/combinations/no_repetition/partial_perm/adjacent_constraint.cpp
        src/combinations/no_repetition/partial_perm/adjacent_constraint.h)
