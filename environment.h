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
        Individual(int n); // initialize with n-sized random array.
        std::vector<int> getData();

    private:
        std::vector<int> data;
        void setRandomData(int n);
};