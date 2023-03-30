//
// Created by jan.gruszczynski on 26.03.2023.
//

#ifndef ARTIFICIAL_LIFE_GREEDYHEURISTIC_H
#define ARTIFICIAL_LIFE_GREEDYHEURISTIC_H

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <chrono>

#include "Instance.h"
#include "RandomSolutions.h"

vector<int> generateGreedyHeuristicSolution(Instance *instance);
RESULT::Result generateGreedyHeuristicSolutionEval(Instance *instance);


#endif //ARTIFICIAL_LIFE_GREEDYHEURISTIC_H
