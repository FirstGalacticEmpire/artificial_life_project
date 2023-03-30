//
// Created by jan.gruszczynski on 26.03.2023.
//

#include "GreedyHeuristic.h"

vector<int> generateGreedyHeuristicSolution(Instance *instance) {
    vector<int> cities;
    int startingCity = generateRandomInt(0, instance->size - 1);
    cities.push_back(startingCity);
//    cout << startingCity << endl;
    int myCost = 0;
    while (cities.size() != instance->size) {
        int min = numeric_limits<int>::max();
        int closestPoint = startingCity;
        for (int i = 0; i < instance->size; i++) {
            if (i == startingCity) {
                continue;
            }
            int edgeCost = instance->edge_weight(startingCity, i);
            if (min > edgeCost) {
                min = edgeCost;
                closestPoint = i;
            }
        }
        for (int x = 0; x < instance->size; x++) {
            instance->matrix_copy[x][closestPoint] = numeric_limits<int>::max();
        }
        myCost = myCost + min;
        cities.push_back(closestPoint);
        startingCity = closestPoint;
    }
    instance->resetCopyMatrix();
//    myCost = myCost + instance->edge_weight(cities[0], cities[instance->size - 1]);
//    printVector(cities);
//    cout << "Final cost: " << myCost << " " << calculateSolutionCost(cities, instance);
//    const auto duplicate = std::adjacent_find(cities.begin(), cities.end());
//    if (duplicate != cities.end())
//        std::cout << "Duplicate element = " << *duplicate << "\n";
    return cities;
}

RESULT::Result generateGreedyHeuristicSolutionEval(Instance *instance) {
    chrono::duration<double> deltaT{};
    auto t0 = chrono::high_resolution_clock::now();

    vector<int> randomSolution = generateGreedyHeuristicSolution(instance);

    deltaT = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - t0);
    int solutionCost = calculateSolutionCost(randomSolution, instance);
    return RESULT::Result{instance->size, solutionCost,
                          deltaT, instance->fileName, "greedyHeuristic",
                          0, randomSolution, 0};
}

