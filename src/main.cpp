#include "population.h"

int main() {

  // initialize params.
  int initIndividualSize = 6;
  int initPopSize = 4;
  Population pop(initIndividualSize, initPopSize, "random");

  // initialization tests.

  std::vector<Individual> popData = pop.getData();
  int popSize =  popData.size();
  std::vector<int> individualData = popData[0].getData();
  int individualSize = individualData.size();

  bool hasValidIndividualData = individualData.size() == initIndividualSize;
  bool hasValidPopulationData = popData.size() == initPopSize;

  if ((hasValidIndividualData & hasValidPopulationData) != true) {
    std::cout << "> test failed: "  << endl;
    std::cout << "> hasValidIndividualData: " << hasValidIndividualData << endl;
    std::cout << "> hasValidPopulationData: " << hasValidPopulationData << endl;
    return 0;
  }

  // console.
  std::cout << "population size: " << popSize << endl;
  std::cout << "individual size: " << individualSize << endl;

  // begin optimizaiton.
  int n = 1000;
  std::cout << "running " << n << " generations " << endl;
  pop.run(n);

  std::cout << "completed simulation" << endl;
  return 0;
}