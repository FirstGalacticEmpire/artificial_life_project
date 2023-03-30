cmake_minimum_required(VERSION 3.24)
project(artificial_life)

set(CMAKE_CXX_STANDARD 17)

add_executable(artificial_life main.cpp Instance.h CoordsWeightType.h Instance.cpp StringFunctions.cpp RandomGenerator.cpp RandomGenerator.h LocalSearch.cpp LocalSearch.h utils.cpp utils.h RandomSolutions.cpp RandomSolutions.h GreedyHeuristic.cpp GreedyHeuristic.h)
