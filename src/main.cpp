#include "population.h"

int main() {

  // initialize params.
  int individualSize = 6;
  int popSize = 4;
  Population pop(individualSize, popSize, "random");

  // console.
  std::cout << "population size: " << popSize << endl;
  std::cout << "individual size: " << individualSize << endl;

  // begin optimizaiton.
  int n = 1000;
  std::cout << "running " << n << " generations " << endl;
  pop.run(n);

  std::cout << "completed simulation" << endl;
}