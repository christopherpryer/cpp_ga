#pragma once

#include <random>     // mt19937 and uniform_int_distribution
#include <algorithm>  // generate
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind
#include <iostream>   // coutcopuu

using namespace std;

class Individual {

    public:
        Individual(int n); // initialize with n-sized random vector.
        std::vector<int> getData();
        void setFitness(long f);
        long getFitness();

    private:
        std::vector<int> data;
        long fitness = 0;
        
        void setRandomData(int n);
};