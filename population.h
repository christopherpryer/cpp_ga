#pragma once

#include "individual.h"

class Population {

    public:
        Population(int nI, int nP, std::string kind); // initialize with n-sized population vector using 'kind' initialization.
        std::vector<Individual> getData();

    private:
        std::vector<Individual> data;

        void setData(int nI, int nP, std::string kind);
        std::vector<Individual> initializeWithRandomIndividuals(int nI, int nP);
};