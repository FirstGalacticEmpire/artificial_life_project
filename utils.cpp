//
// Created by jan.gruszczynski on 26.03.2023.
//

#include "utils.h"

string printVector(const vector<int> &myVector) {
    string solution;
    for (auto y: myVector) {
//        cout << y << " ";
        solution +=to_string(y);
        solution +=" ";
    }
    return solution;
//    cout << "\n";
}

long calculateSolutionCost(vector<int> solution, Instance *instance) {
    long cost = 0;
    for (auto x = 0; x < solution.size(); x++) {
        if ((x + 1) == solution.size()) {
            break;
        }
        cost = cost + instance->edge_weight(solution[x], solution[x + 1]);
    }
    cost = cost + instance->edge_weight(solution[solution.size() - 1], solution[0]);
    return cost;
}

vector<int> nodeSwap(vector<int> solution, unsigned long idx1, unsigned long idx2) {
    swap(solution[idx1], solution[idx2]);
    return solution;
}

vector<int> edgeSwap(vector<int> solution, unsigned long idx1, unsigned long idx2) {
    if (idx1 > idx2) {
        swap(idx1, idx2);
    }

    while (idx1 < idx2) {
        swap(solution[idx1], solution[idx2]);
        idx1++;
        idx2--;
    }
    return solution;
}
