#include "environment.h"

Individual::Individual(int n) {
    this->setRandomData(n);
};

void Individual::setRandomData(int n) {
    std::random_device r;
    std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937       eng(seed); // a source of random data

    std::uniform_int_distribution<int> dist;
    std::vector<int> v(n);

    generate(begin(v), end(v), bind(dist, eng));
    this->data = v;
};

std::vector<int> Individual::getData() {
    return this->data;
};

Population::Population(int nI, int nP) {
    this->setData(nI, nP);
};

void Population::setData(int nI, int nP) { 
    this->data = initializeWithRandomIndividuals(nI, nP);
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