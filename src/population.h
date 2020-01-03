#pragma once

#include "individual.h"

class Population {

    public:
        Population(int nI, int nP, std::string kind); // initialize with n-sized population vector using 'kind' initialization.
        std::vector<Individual> getData();
        void run(int n); // control n runs of a generation
        std::vector<int> calculateSumsVector(std::vector<Individual> popData);
        std::vector<int> calculateRanksVector(std::vector<Individual> popData); // rank individuals by their sum (highest sum goes first).

    private:
        std::vector<Individual> data;

        void setData(int nI, int nP, std::string kind);
        std::vector<Individual> initializeWithRandomIndividuals(int nI, int nP);
};