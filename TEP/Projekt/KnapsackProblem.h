#ifndef PROJEKT_KNAPSACKPROBLEM_H
#define PROJEKT_KNAPSACKPROBLEM_H
#include <vector>
#include <iostream>
#include "Individual.h"

using namespace std;

class KnapsackProblem{
private:
    double capacity;
    vector<double> weightsTable;
    vector<double> valuesTable;

    static vector<double> convertStringTableToVector(const string& stringToConvert);
public:
    KnapsackProblem(double capacityOfKnapsack, const vector<double>& weights, const vector<double>& values);
    KnapsackProblem(const string& filePath);
    ~KnapsackProblem();

    int getNumberOfProducts();
    void calculateValueOfSolution(Individual* individual);
};

#endif
