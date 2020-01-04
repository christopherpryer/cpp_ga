// TODO: currently not working.

#define CATCH_CONFIG_MAIN

#include "src/population.h"
#include "catch.hpp"


TEST_CASE( "Random Individual initialization", "[single-file]" ) {
    int objective = 5;
    Individual individual(objective);
    std::vector<int> data = individual.getData();
    bool hasValidData = data.size() == objective;
    REQUIRE(hasValidData);
}

TEST_CASE( "Random Individual initialization for generating populations", "[single-file]" ) {
    int objectiveA = 5;
    int objectiveB = 6;
    Population pop(objectiveA, objectiveB, "random");

    std::vector<Individual> popData = pop.getData();
    std::vector<int> sampleIndividual = popData[0].getData();

    bool hasValidIndividualData = sampleIndividual.size() == objectiveA;
    bool hasValidPopulationData = popData.size() == objectiveB;

    REQUIRE(hasValidIndividualData);
    REQUIRE(hasValidPopulationData);
}