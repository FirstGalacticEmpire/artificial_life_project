//
// Created by jan.gruszczynski on 26.03.2023.
//

#ifndef ARTIFICIAL_LIFE_RANDOMSOLUTIONS_H
#define ARTIFICIAL_LIFE_RANDOMSOLUTIONS_H

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <chrono>

#include "utils.h"
#include "Instance.h"

tuple<vector<int>, int, int> generateRandomSolution(Instance *instance);

RESULT::Result generateRandomSolutionEval(Instance *instance);

tuple<vector<int>, long, int> generateRandomWalkSolution(Instance *instance);

RESULT::Result generateRandomWalkSolutionEval(Instance *instance);

#endif //ARTIFICIAL_LIFE_RANDOMSOLUTIONS_H
