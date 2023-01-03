#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include <vector>

int main() {
    vector<double> weights1 = {4, 1, 3, 2};
    vector<double> values1 = {5, 1, 4, 3};
    KnapsackProblem knapsackProblem1(5, weights1, values1);
    GeneticAlgorithm genetic1(100, 0.6, 0.1, 10);
    genetic1.init(knapsackProblem1); // The best solution: 0 0 1 1

    vector<double> weights2 = {2, 2, 3, 15, 1, 4, 5, 6};
    vector<double> values2 = {40, 160, 70, 300, 70, 25, 25, 180};
    KnapsackProblem knapsackProblem2(15, weights2, values2);
    GeneticAlgorithm genetic2(1000, 0.6, 0.1, 10);
    genetic2.init(knapsackProblem2); //The best solution: 1 1 1 0 1 0 0 1

    KnapsackProblem knapsackProblem3("../initialFiles/knapsack1.txt");
    GeneticAlgorithm genetic3(100, 0.6, 0.6, 10);
    genetic3.init(knapsackProblem3); //The best solution: 1 1 0 0

    KnapsackProblem knapsackProblem4("../initialFiles/knapsack2.txt");
    GeneticAlgorithm genetic4(100, 0.6, 0.6, 10);
    genetic4.init(knapsackProblem4); //The best solution: 1 0 0 1 1
    return 0;
}
