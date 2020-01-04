#include "population.h"

Population::Population(int nI, int nP, std::string kind) {
    this->setData(nI, nP, kind);
};

void Population::setData(int nI, int nP, std::string kind) {
    if (kind == "random") {
        this->data = initializeWithRandomIndividuals(nI, nP);
    } else {
        std::cout << "kind string was not found; initilizing randomized. " << endl;
        this->data = initializeWithRandomIndividuals(nI, nP); // could make this default initialization.
    }
};

std::vector<Individual> Population::initializeWithRandomIndividuals(int nI, int nP) { 
    std::vector<Individual> vec;
    for (unsigned int i = 0; i < nP; i++) {
        Individual individual(nI);
        vec.push_back(individual);
    }
    return vec;
};

std::vector<Individual> Population::getData() { 
    return this->data;
};

void Population::run(int n) {
    for (unsigned int i = 0; i < n; i++) { // for n generations.
        // get the rank of each individual as a vector.
        std::vector<int> ranks = this->calculateRanksVector(this->data);
        std::vector<float> probabilityVector = this->calculateProbabilityVector(ranks);
    }
};

std::vector<int> Population::calculateRanksVector(std::vector<Individual> popData) {
    // get ranks of individual vectors.
    std::vector<int> sums = this->calculateSumsVector(popData);
    std::vector<int> ranks(sums.size());
    std::size_t n(0);
    std::generate(std::begin(ranks), std::end(ranks), [&]{ return n++; });
    std::sort(std::begin(ranks), std::end(ranks), [&](int i1, int i2) { return sums[i1] < sums[i2]; });
    return ranks;
};

std::vector<int> Population::calculateSumsVector(std::vector<Individual> popData) {
    // calculate sums of individual vectors.
    std::vector<int> vec;
    int totalPop = popData.size();
    for (unsigned int i = 0; i < totalPop; i++) {
        std::vector<int> innerData = popData[i].getData();
        int sum = std::accumulate(innerData.begin(), innerData.end(), 0);
        popData[i].setFitness(sum);
        vec.push_back(sum);
        }
    return vec;
};

std::vector<float> Population::calculateProbabilityVector(std::vector<int> ranksVector) {
    int maximumIndex = *std::max_element(ranksVector.begin(), ranksVector.end());

    long totalScore = 0;
    std::vector<long> scoreVector(ranksVector.size());
    for (unsigned int i = 0; i <= maximumIndex; i++) {
        long score = pow(ranksVector[i] + 1, this->scorePower);
        scoreVector[i] = score;
        totalScore += score;
    }
    std::vector<float> probabilityVector(ranksVector.size());
    for (unsigned int i = 0; i <= maximumIndex; i++) { // no simple vectorized scalar math?
        probabilityVector[i] = (scoreVector[i] + 1) / float(totalScore);
    }
    return probabilityVector;
};