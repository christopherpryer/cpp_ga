#pragma once

#include "individual.h"

class Population {

    public:
        Population(int nI, int nP, std::string kind); // initialize with n-sized population vector using 'kind' initialization.
        std::vector<Individual> getData();
        void run(int n); // control n runs of a generation
        std::vector<int> calculateSumsVector(std::vector<Individual> popData);
        std::vector<int> calculateRanksVector(std::vector<Individual> popData); // rank individuals by least to most.

    private:
        std::vector<Individual> data;
        int scorePower = 2;
        float reproductionProbability = 0.4;

        void setData(int nI, int nP, std::string kind);
        std::vector<Individual> initializeWithRandomIndividuals(int nI, int nP);
        std::vector<float> calculateProbabilityVector(std::vector<int> ranksVector);
        std::vector<int> selectUsingProbability(std::vector<int> sampleVector, std::vector<float> probabilityVector);
        std::vector<int> getReproductionVector(Individual i1, Individual i2);
        void overrideData(std::vector<Individual> newData);
        void mutateNewborn(std::vector<int> &newborn);
};