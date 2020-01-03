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

    private:
        std::vector<int> data;
        void setRandomData(int n);
};

class Population {

    public:
        Population(int nI, int nP, std::string kind); // initialize with n-sized population vector using 'kind' initialization.
        std::vector<Individual> getData();

    private:
        std::vector<Individual> data;

        void setData(int nI, int nP, std::string kind);
        std::vector<Individual> initializeWithRandomIndividuals(int nI, int nP);
};