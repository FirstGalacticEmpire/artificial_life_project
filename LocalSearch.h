//
// Created by jan.gruszczynski on 26.03.2023.
//

#ifndef ARTIFICIAL_LIFE_LOCALSEARCH_H
#define ARTIFICIAL_LIFE_LOCALSEARCH_H

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <chrono>

#include "RandomSolutions.h"
#include "utils.h"
#include "Instance.h"
#include "RandomGenerator.h"

int costOfNodeSwap2(vector<int> solution, long idx1, long idx2, Instance *instance, bool debug);

int costOfEdgeSwap(vector<int> solution, long idx1, long idx2, Instance *instance, bool debug);

int costOfEdgeSwap(vector<int> solution, long idx1, long idx2, Instance *instance);

tuple<vector<int>, long, int, long> localSearch(Instance *instance);

RESULT::Result localSearchEval(Instance *instance);

tuple<vector<int>, long, int, long> greedyLocalSearch(Instance *instance);

vector<int> generateRandomSolutionForLocalSearch(Instance *instance);

RESULT::Result greedyLocalSearchEval(Instance *instance);


#endif //ARTIFICIAL_LIFE_LOCALSEARCH_H
