//
// Created by jan.gruszczynski on 25.03.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "RandomGenerator.h"
#include <random>

using namespace std;
random_device r;
default_random_engine e1(r());

int generateRandomInt(int a, int b) {
    uniform_int_distribution<int> uniform_dist(a, b);
    return uniform_dist(e1);
}

int *generateTwoRandomInts(int a, int b) {
// For some reason zjebane i nie dziala
    //        RandomIterator iterator(amount, min, max);
//        unsigned long i1 = iterator.next();
//        unsigned long i2 = iterator.next();
    static int ints[2];
    ints[0] = generateRandomInt(a, b);
    ints[1] = generateRandomInt(a, b);
    return ints;
}

vector<int> permutateList(vector<int> list_to_permutate) {
    auto vector_len = list_to_permutate.size();
    for (auto i = vector_len; i > 0; i--) {
//        int rand_val = rand() % i;
        int rand_val = generateRandomInt(0, i - 1);
//        cout << i << "  " << rand_val << endl;
//        swap(list_to_permutate[rand_val], list_to_permutate[i - 1]);
        swap(list_to_permutate[i - 1], list_to_permutate[rand_val]);
    }

    const auto duplicate = std::adjacent_find(list_to_permutate.begin(), list_to_permutate.end());
    if (duplicate != list_to_permutate.end())
        std::cout << "Duplicate element = " << *duplicate << "\n";

    return list_to_permutate;
}

void permutateList(int *list_to_permutate, int n) {
    for (auto i = n; i > 0; i--) {
        int rand_val = generateRandomInt(0, i - 1);
        swap(list_to_permutate[i - 1], list_to_permutate[rand_val]);
    }
}

//#include "RandomGenerator.h"
