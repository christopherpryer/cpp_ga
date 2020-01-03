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