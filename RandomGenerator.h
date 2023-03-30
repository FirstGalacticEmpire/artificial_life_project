//
// Created by jan.gruszczynski on 25.03.2023.
//

#ifndef ARTIFICIAL_LIFE_RANDOMGENERATOR_H
#define ARTIFICIAL_LIFE_RANDOMGENERATOR_H


using namespace std;

int generateRandomInt(int a, int b);

int *generateTwoRandomInts(int a, int b);

void permutateList(int *list_to_permutate, int n);

vector<int> permutateList(vector<int> list_to_permutate);

//#include <vector>
//#include <random>
//#include <iostream>
//#include <stdexcept>
//
//using std::mt19937_64;
//using std::random_device;
//using std::uniform_int_distribution;
//using std::vector;
//using std::cout;
//using std::cerr;
//using std::endl;
//using std::out_of_range;
//
//// We'll use this class to generate random numbers
//class RandomIterator
//{
//public:
//    /* Constructor for RandomIterator class.
//     * Parameters:
//     *     - amount => Amount of numbers to generate
//     *     - min    => Minimum number in range to generate
//     *     - max    => Maximum number in range to generate
//     *
//     * The constructor also instanstiates the variable gen
//     * with a new random_device.
//     */
//    RandomIterator(const unsigned long long &amount, const unsigned long long &min, const unsigned long long &max): gen((random_device())())
//
//    {
//        floor = min;
//        num_left = amount;
//        last_k = min;
//        n = max;
//    }
//
//    // Return a bool to determine if there are any numbers left to generate
//    bool has_next()
//    {
//        return num_left > 0;
//    }
//
//    // Generate the next random number
//    unsigned long long next()
//    {
//        if (num_left > 0)
//        {
//            // Partition the range of numbers to generate from
//            unsigned long long range_size = (n - last_k) / num_left;
//
//            // Initialize random generator
//            uniform_int_distribution<unsigned long long> rnd(floor, range_size);
//
//            // Generate random number
//            unsigned long long r = rnd(gen) + last_k + 1;
//
//            // Set last_k to r so that r is not generated again
//            last_k = r;
//            num_left--;
//            return r;
//        }
//        else
//        {
//            throw out_of_range("Exceeded amount of random numbers to generate.");
//        }
//    }
//private:
//    unsigned long long floor;
//    unsigned long long n;
//    unsigned long long last_k;
//    unsigned long long num_left;
//    mt19937_64         gen;
//
//};

//int main()
//{
//    // Amount to create;
//    unsigned long long amount = 100000;
//
//    // Generate a number from 1 to 1,000,000
//    unsigned long long min = 1;
//    unsigned long long max = 1000000;
//
//    // If the amount is greater than the max then this will fail
//    if (amount > max)
//    {
//        cerr << "Amount must be less than max." << endl;
//        return -1;
//    }
//
//    // Instantiate iterator
//    RandomIterator iterator(amount, min, max);
//
//    // While there are still numbers left to generate,
//    // generate and display the numbers
//    while(iterator.has_next())
//    {
//        cout << iterator.next() << " ";
//    }
//    cout << endl;
//    return 0;
//}


#endif //ARTIFICIAL_LIFE_RANDOMGENERATOR_H
