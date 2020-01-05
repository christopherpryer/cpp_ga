# include "individual.h"

Individual::Individual(int n) {
    this->setRandomData(n);
};

void Individual::setRandomData(int n) {
    std::random_device r;
    std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937       eng(seed); // a source of random data.

    std::uniform_int_distribution<int> dist;
    std::vector<int> v(n);

    generate(begin(v), end(v), bind(dist, eng));
    this->data = v;
};

std::vector<int> Individual::getData() {
    return this->data;
};

void Individual::setFitness(long f) {
    this->fitness = f;
};

long Individual::getFitness() {
    return this->fitness;
};

void Individual::overrideData(std::vector<int> newData) {
    this->data = newData;
};