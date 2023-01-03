cmake_minimum_required(VERSION 3.23)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt main.cpp KnapsackProblem.cpp KnapsackProblem.h GeneticAlgorithm.cpp GeneticAlgorithm.h Individual.cpp Individual.h)
