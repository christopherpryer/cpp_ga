#include "population.h"
#include "utils.h"
#include <time.h>

int main() {

  // initialize params.
  int initIndividualSize = 100;
  int initPopSize = 40000;
  int generations = 100000;
  Population pop(initIndividualSize, initPopSize, "random");

  // initialization tests.
  std::vector<Individual> popData = pop.getData();
  int popSize =  popData.size();
  std::vector<int> individualData = popData[0].getData();
  int individualSize = individualData.size();

  bool hasValidIndividualData = individualData.size() == initIndividualSize;
  bool hasValidPopulationData = popData.size() == initPopSize;

  if ((hasValidIndividualData & hasValidPopulationData) != true) {
    std::cout << "> test failed: " << endl;
    std::cout << "> hasValidIndividualData: " << hasValidIndividualData << endl;
    std::cout << "> hasValidPopulationData: " << hasValidPopulationData << endl;
    return 0;
  }

  // console.
  std::cout << "population size: " << popSize << endl;
  std::cout << "individual size: " << individualSize << endl;

  // begin optimizaiton.
  std::cout << "running " << n << " generations " << endl;

  time_t start = time(0);
  pop.run(generations);
  double secondsSinceStart = difftime(time(0), start);

  std::cout << "completed simulation in roughly " << secondsSinceStart << " second(s)" << endl;
  return 0;
}