#include "environment.h"

int main() {
  int individualSize = 6;
  int popSize = 4;
  Population pop(individualSize, popSize);
  std::cout << "population size: " << popSize << endl;
  std::cout << "individual size: " << individualSize << endl;

  auto data = pop.getData();
  for (unsigned int i = 0; i < data.size(); i++) {
    std::vector<int> innerData = data[i].getData();
    std::cout << "unsorted [" << i << "] data: ";
    copy(begin(innerData), end(innerData), std::ostream_iterator<int>(std::cout, "\n"));
  }  
}