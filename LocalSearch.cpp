//
// Created by jan.gruszczynski on 26.03.2023.
//

#include "LocalSearch.h"


int costOfNodeSwap2(vector<int> solution, long idx1, long idx2, Instance *instance, bool debug) {
    int i1Before = solution[(idx1 - 1 + instance->size) % instance->size];
    int i2Before = solution[(idx2 - 1 + instance->size) % instance->size];
    int i1After = solution[(idx1 + 1 + instance->size) % instance->size];
    int i2After = solution[(idx2 + 1 + instance->size) % instance->size];

    if (debug) {
        cout << "Indexy:" << endl;
        cout << i1Before << " " << idx1 << " " << i1After << endl;
        cout << i2Before << " " << idx2 << " " << i2After << endl;
    }


    if (idx1 + 1 == idx2) {
        if (debug) cout << "edgecase1" << endl;
        idx1 = solution[idx1];
        idx2 = solution[idx2];
        int currentCost = instance->edge_weight(i1Before, idx1) + instance->edge_weight(idx1, idx2);
        currentCost = currentCost + instance->edge_weight(idx2, i2After);

        int newCost = instance->edge_weight(i1Before, idx2) + instance->edge_weight(idx1, idx2);
        newCost = newCost + instance->edge_weight(idx1, i2After);

        return currentCost - newCost;
    }

    if (idx1 == idx2 + 1) {
        if (debug) cout << "edgecase2" << endl;
        idx1 = solution[idx1];
        idx2 = solution[idx2];
        int currentCost = instance->edge_weight(i2Before, idx2) + instance->edge_weight(idx1, idx2);
        currentCost = currentCost + instance->edge_weight(idx1, i1After);

        int newCost = instance->edge_weight(i2Before, idx1) + instance->edge_weight(idx1, idx2);
        newCost = newCost + instance->edge_weight(idx2, i1After);
        return currentCost - newCost;
    }

    if ((idx1 == 0) && (idx2 == instance->size - 1)) {
        if (debug) cout << "edgecase3" << endl;
        idx1 = solution[idx1];
        idx2 = solution[idx2];
        int currentCost = instance->edge_weight(idx1, idx2) + instance->edge_weight(idx1, i1After);
        currentCost = currentCost + instance->edge_weight(i2Before, idx2);

        int newCost = instance->edge_weight(idx1, idx2) + instance->edge_weight(idx2, i1After);
        newCost = newCost + instance->edge_weight(i2Before, idx1);

        return currentCost - newCost;
    }

    if ((idx1 == instance->size - 1) && (idx2 == 0)) {
        if (debug) cout << "edgecase4" << endl;
        idx1 = solution[idx1];
        idx2 = solution[idx2];
        int currentCost = instance->edge_weight(idx1, idx2) + instance->edge_weight(idx2, i2After);
        currentCost = currentCost + instance->edge_weight(i1Before, idx1);

        int newCost = instance->edge_weight(idx1, idx2) + instance->edge_weight(idx1, i2After);
        newCost = newCost + instance->edge_weight(i1Before, idx2);

        return currentCost - newCost;
    }
    idx1 = solution[idx1];
    idx2 = solution[idx2];


    int currentCost = instance->edge_weight(i1Before, idx1) + instance->edge_weight(idx1, i1After);
    currentCost = currentCost + instance->edge_weight(i2Before, idx2) + instance->edge_weight(idx2, i2After);

    int newCost = instance->edge_weight(idx2, i1Before) + instance->edge_weight(idx2, i1After);
    newCost = newCost + instance->edge_weight(idx1, i2Before) + instance->edge_weight(idx1, i2After);

    return currentCost - newCost;
}

int costOfEdgeSwap(vector<int> solution, long idx1, long idx2, Instance *instance, bool debug) {
    if (idx1 > idx2) {
        swap(idx1, idx2);
    }
    int i1Before = solution[(idx1 - 1 + instance->size) % instance->size];
    int i2After = solution[(idx2 + 1 + instance->size) % instance->size];


    idx1 = solution[idx1];
    idx2 = solution[idx2];
    int currentCost = instance->edge_weight(i1Before, idx1) + instance->edge_weight(idx2, i2After);
    int newCost = instance->edge_weight(i1Before, idx2) + instance->edge_weight(idx1, i2After);
    return currentCost - newCost;
}

int costOfEdgeSwap(vector<int> solution, long idx1, long idx2, Instance *instance) {
    return costOfEdgeSwap(solution, idx1, idx2, instance, false);
}

tuple<vector<int>, long, int, long> localSearch(Instance *instance) {
    vector<int> solution = generateRandomSolutionForLocalSearch(instance);
//    printVector(solution);
    int oldCost = calculateSolutionCost(solution, instance);
    int startingCost = oldCost;
//    int startingCost = oldCost;
//    cout << "Starting solution cost: " << oldCost << endl;
    int bestNodeX1 = solution[0];
    int bestNodeX2 = solution[1];

    int bestEdgeX1 = solution[0];
    int bestEdgeX2 = solution[1];

    int bestNodeGain;
    int bestEdgeGain;
    long numSteps = 0;
    long numEval = 0;
    do {
        numSteps++;
        bestNodeGain = 0;
        bestEdgeGain = 0;

        for (int x1 = 0; x1 < solution.size(); x1++) {
            for (int x2 = 0; x2 < solution.size(); x2++) {
                if (!(((x1 == 0) && (x2 == solution.size() - 1)) || ((x1 == solution.size() - 1) && (x2 == 0)))) {
                    if (abs(x1 - x2) > 1) {
                        vector<int> newSolution = edgeSwap(solution, x1, x2);
                        int edgeSwapCost = costOfEdgeSwap(solution, x1, x2, instance, false);
                        numEval ++;
                        if (edgeSwapCost > bestEdgeGain) {
                            bestEdgeGain = edgeSwapCost;
                            bestEdgeX1 = x1;
                            bestEdgeX2 = x2;
                        }

                    }
                }
                if (x1 != x2) {
                    vector<int> newSolution = nodeSwap(solution, x1, x2);
                    int nodeSwapCost = costOfNodeSwap2(solution, x1, x2, instance, false);
                    numEval ++;
                    if (nodeSwapCost > bestNodeGain) {
                        bestNodeGain = nodeSwapCost;
                        bestNodeX1 = x1;
                        bestNodeX2 = x2;
                    }
                }

            }

        }

//        for (int x1 = 0; x1 < solution.size(); x1++) {
//            for (int x2 = 0; x2 < solution.size(); x2++) {
//                if (x1 == x2) continue;
//                vector<int> newSolution = nodeSwap(solution, x1, x2);
//                int nodeSwapCost = costOfNodeSwap2(solution, x1, x2, instance, false);
//
//                if (nodeSwapCost > bestNodeGain) {
//                    bestNodeGain = nodeSwapCost;
//                    bestNodeX1 = x1;
//                    bestNodeX2 = x2;
//                }
//
//            }
//
//        }


        if ((bestNodeGain > 0) || (bestEdgeGain > 0)) {
            if (bestNodeGain > bestEdgeGain) {
                solution = nodeSwap(solution, bestNodeX1, bestNodeX2);
                oldCost = oldCost - bestNodeGain;
            } else {
                solution = edgeSwap(solution, bestEdgeX1, bestEdgeX2);
                oldCost = oldCost - bestEdgeGain;
            }

        }

    } while ((bestNodeGain > 0) || (bestEdgeGain > 0));

//    int currentCost = calculateSolutionCost(solution, instance);
//    cout << "Current cost: " << currentCost << endl;
//    cout << "Gain: " << startingCost - currentCost << endl;

    return {solution, numSteps, startingCost, numEval};
}

RESULT::Result localSearchEval(Instance *instance) {
    chrono::duration<double> deltaT{};
    auto t0 = chrono::high_resolution_clock::now();

    auto [randomSolution, numSteps, startingCost, numEval] = localSearch(instance);

    deltaT = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - t0);
    int solutionCost = calculateSolutionCost(randomSolution, instance);
    return RESULT::Result{numSteps, solutionCost, deltaT, instance->fileName,
                          "localSearch", 0, randomSolution,
                          startingCost, numEval};
}

tuple<vector<int>, long, int, long> greedyLocalSearch(Instance *instance) {
    vector<int> solution = generateRandomSolutionForLocalSearch(instance);
//    printVector(solution);
    int oldCost = calculateSolutionCost(solution, instance);
    int startingCost = oldCost;
//    int startingCost = oldCost;
//    cout << "Starting solution cost: " << oldCost << endl;
    int bestNodeX1 = solution[0];
    int bestNodeX2 = solution[1];

    int bestEdgeX1 = solution[0];
    int bestEdgeX2 = solution[1];

    int bestNodeGain;
    int bestEdgeGain;
    long numSteps = 0;
    long numEval = 0;
    do {
        numSteps++;
        bestNodeGain = 0;
        bestEdgeGain = 0;
        bool shouldBreak = false;
        for (int x1 = 0; x1 < solution.size(); x1++) {
            for (int x2 = 0; x2 < solution.size(); x2++) {
                if (((x1 == 0) && (x2 == solution.size() - 1)) || ((x1 == solution.size() - 1) && (x2 == 0))) {
                    continue;
                }
                if (abs(x1 - x2) <= 1) {
                    continue;
                }

                vector<int> newSolution = edgeSwap(solution, x1, x2);
                int edgeSwapCost = costOfEdgeSwap(solution, x1, x2, instance, false);
                numEval ++;
                if (edgeSwapCost > bestEdgeGain) {
                    bestEdgeGain = edgeSwapCost;
                    bestEdgeX1 = x1;
                    bestEdgeX2 = x2;
                    shouldBreak = true;
                    break;
                }

            }
            if (shouldBreak) break;
        }


        if (!shouldBreak) {
            for (int x1 = 0; x1 < solution.size(); x1++) {
                for (int x2 = 0; x2 < solution.size(); x2++) {
                    if (x1 == x2) continue;
                    vector<int> newSolution = nodeSwap(solution, x1, x2);
                    int nodeSwapCost = costOfNodeSwap2(solution, x1, x2, instance, false);
                    numEval ++;
                    if (nodeSwapCost > bestNodeGain) {
                        bestNodeGain = nodeSwapCost;
                        bestNodeX1 = x1;
                        bestNodeX2 = x2;
                    }
                }
            }
        }

        if ((bestNodeGain > 0) || (bestEdgeGain > 0)) {
            if (bestNodeGain > bestEdgeGain) {
                solution = nodeSwap(solution, bestNodeX1, bestNodeX2);
                oldCost = oldCost - bestNodeGain;
            } else {
                solution = edgeSwap(solution, bestEdgeX1, bestEdgeX2);
                oldCost = oldCost - bestEdgeGain;
            }
        }

    } while ((bestNodeGain > 0) || (bestEdgeGain > 0));

//    int currentCost = calculateSolutionCost(solution, instance);
//    cout << "Current cost: " << currentCost << endl;
//    cout << "Gain: " << startingCost - currentCost << endl;

    return {solution, numSteps, startingCost, numEval};
}

RESULT::Result greedyLocalSearchEval(Instance *instance) {
    chrono::duration<double> deltaT{};
    auto t0 = chrono::high_resolution_clock::now();

    auto [randomSolution, numSteps, startingCost, numEval] = greedyLocalSearch(instance);

    deltaT = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - t0);
    int solutionCost = calculateSolutionCost(randomSolution, instance);
    return RESULT::Result{numSteps, solutionCost, deltaT, instance->fileName,
                          "greedyLocalSearch", 0,
                          randomSolution, startingCost, numEval};
}