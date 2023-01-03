#ifndef PROJEKT_GENETICALGORITHM_H
#define PROJEKT_GENETICALGORITHM_H
#include <vector>
#include <random>
#include "Individual.h"
#include "KnapsackProblem.h"

using namespace std;

class GeneticAlgorithm {
private:
    vector<Individual *> individualVector;
    int populationSize;
    double crossProbability;
    double mutationProbability;
    int iterations;

    void createPopulation(int productsNumber);
    void setSolutionsValue(KnapsackProblem & knapsackProblem);
    void executeCross();
    void executeMutation();
    Individual* chooseAndPrintTheBestIndividual();
public:
    GeneticAlgorithm(int populationSize, double crossProbability, double mutationProbability, int iterationNumber);
    ~GeneticAlgorithm();

    Individual* init(KnapsackProblem & knapsackProblem);
};

#endif