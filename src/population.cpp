#include "population.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

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
        std::vector<int> selectedIndicies = this->selectUsingProbability(ranks, probabilityVector);
        std::vector<Individual> newGenerationVector;

        int iN = this->data[0].getData().size(); // size of an individual.
        int N = this->data.size();
        int n = selectedIndicies.size();
        int selectionCounter = 0;
        for (unsigned int i = 0; i < N; i++) {
            if (selectionCounter + 1 == n) {
                selectionCounter = 0;
            }
            int firstIndex = selectedIndicies[selectionCounter];
            int secondIndex = selectedIndicies[selectionCounter + 1];
            std::vector<int> reproductionVector = this->getReproductionVector(this->data[firstIndex], this->data[secondIndex]);
            
            Individual child(iN);
            // example of inplace (in memory) operation
            this->mutateNewborn(reproductionVector);
            child.overrideData(reproductionVector);
            newGenerationVector.push_back(child);
            selectionCounter++;
        }
        this->overrideData(newGenerationVector);
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
        vec.push_back(sum);
        }
    return vec;
};

std::vector<float> Population::calculateProbabilityVector(std::vector<int> ranksVector) {
    int vecSize = ranksVector.size();

    long totalScore = 0;
    std::vector<long> scoreVector;
    int positionCounter = 0;
    for (unsigned int i = vecSize; i > 0; i--) {
        long score = pow(i, this->scorePower);
        scoreVector.push_back(score);
        this->data[ranksVector[positionCounter]].setFitness(score);
        totalScore += score;
        positionCounter++;
    }

    std::vector<float> probabilityVector(vecSize);
    for (unsigned int i = 0; i < vecSize; i++) { // no simple vectorized scalar math?
        probabilityVector[ranksVector[i]] = (scoreVector[i] + 1) / float(totalScore);
    }
    return probabilityVector;
};

std::vector<int> Population::selectUsingProbability(std::vector<int> sampleVector, std::vector<float> probabilityVector) {
    const int outputSize = int(sampleVector.size() * this->reproductionProbability);
    std::vector<int> vec(outputSize);

    std::default_random_engine generator;
    std::discrete_distribution<int> distribution(probabilityVector.begin(), probabilityVector.end());

    std::vector<int> indices(vec.size());
    std::generate(indices.begin(), indices.end(), [&generator, &distribution]() { return distribution(generator); });

    std::transform(indices.begin(), indices.end(), vec.begin(), [&sampleVector](int index) { return sampleVector[index]; });
    return indices;
};

std::vector<int> Population::getReproductionVector(Individual i1, Individual i2) {
    int geneSplitIndex; 
    std::vector<int> firstData = i1.getData();
    std::vector<int> secondData = i2.getData();
    int vecSize = firstData.size();

    geneSplitIndex = rand() % (vecSize - 2) + 1; // ensure at least some data is passed from each parent.

    std::vector<int> vec(vecSize);
    
    for (unsigned int i = 0; i <= geneSplitIndex; i++) {
        vec[i] = firstData[i];
    }

    for (unsigned int i = geneSplitIndex + 1; i <= vecSize; i++) {
        vec[i] = secondData[i];
    }

    return vec;
};

void Population::mutateNewborn(std::vector<int> &newborn) {
    unsigned int i = rand() % (newborn.size() - 1); // index to mutate (make this configurable).
    int maximum = *max_element(newborn.begin(), newborn.end());
    int mutation = rand() % (maximum);
    newborn.at(i) = mutation;
};

void Population::overrideData(std::vector<Individual> newData) {
    this->data = newData;
};