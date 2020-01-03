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