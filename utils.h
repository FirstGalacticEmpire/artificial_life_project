//
// Created by jan.gruszczynski on 26.03.2023.
//

#ifndef ARTIFICIAL_LIFE_UTILS_H
#define ARTIFICIAL_LIFE_UTILS_H

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include "Instance.h"
#include "RandomGenerator.h"
#include <chrono>

string printVector(const vector<int> &myVector);

namespace RESULT {
    struct Result {
        int numSteps = 0;
        int attainedScore{};
        chrono::duration<double> timeElapsed{};
        string instanceName;
        string functionName;
        double averageTimeElapsed;
        vector<int> solution;
        int startingScore{};
        int numEvaluation = 0;


        string toString() const {
            return to_string(numSteps) + ";" + to_string(attainedScore) + ";" +
                   to_string(timeElapsed.count()) + ";" + instanceName + ";" + functionName + ";"
                   + to_string(averageTimeElapsed) + ";" + to_string(startingScore) + ";" +
                   to_string(numEvaluation) + ';'
                   + printVector(solution) + "\n";
        }
    };


}


long calculateSolutionCost(vector<int> solution, Instance *instance);


vector<int> nodeSwap(vector<int> solution, unsigned long idx1, unsigned long idx2);

vector<int> edgeSwap(vector<int> solution, unsigned long idx1, unsigned long idx2);


#endif //ARTIFICIAL_LIFE_UTILS_H
