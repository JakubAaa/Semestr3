#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int populationNumber, double crossProb, double mutationProb, int iterationNumber) {
    populationSize = populationNumber;
    crossProbability = crossProb;
    mutationProbability = mutationProb;
    iterations = iterationNumber;
}

GeneticAlgorithm::~GeneticAlgorithm() {
    individualVector.clear();
}

void GeneticAlgorithm::createPopulation(int productsNumber) {
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<int> dis(1,10);

    for(int i = 0; i < populationSize; i++){
        vector<int> temp;
        for(int j = 0; j < productsNumber; j++){
            int randomValue = dis(gen) > 5 ? 1 : 0;
            temp.push_back(randomValue);
        }
        individualVector.push_back(new Individual(temp));
    }
}

void GeneticAlgorithm::setSolutionsValue(KnapsackProblem& knapsackProblem) {
    for(int i = 0; i < individualVector.size(); i++)
        knapsackProblem.calculateValueOfSolution(individualVector[i]);
}

void GeneticAlgorithm::executeCross() {
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<int> dis(0,populationSize - 1);
    uniform_int_distribution<int> randomCross(0.0,1.0);

    vector<Individual *> newIndividuals;
    while(newIndividuals.size() < populationSize) {
        int index1 = dis(gen);
        int index2 = dis(gen);

        while (index1 != index2) {
            index2 = dis(gen);
        }

        bool cross = randomCross(gen) < crossProbability;
        if(cross) {
            vector<Individual *> result;
            if(individualVector[index1]->getQuality() > individualVector[index2]->getQuality()){
                result = individualVector[index1]->cross(*individualVector[index2]);
            }
            else{
                result = individualVector[index2]->cross(*individualVector[index1]);
            }
            newIndividuals.push_back(result[0]);
            newIndividuals.push_back(result[1]);
        }
        else{
            newIndividuals.push_back(individualVector[index1]);
            newIndividuals.push_back(individualVector[index2]);
        }
    }
    individualVector = newIndividuals;
}

void GeneticAlgorithm::executeMutation() {
    for(int i = 0; i < individualVector.size(); i++)
        individualVector[i]->mutate(mutationProbability);
}

Individual* GeneticAlgorithm::chooseAndPrintTheBestIndividual(){
    Individual* temp = individualVector[0];
    for(int i = 1; i < individualVector.size(); i++){
        if(individualVector[i]->getQuality() > temp->getQuality())
            temp = individualVector[i];
    }
    if(temp->getQuality() == 0){
        cout << "Solution does not found!" << endl;
        return nullptr;
    }
    else {
        cout << "The best found solution is: ";
        temp->print();
        return temp;
    }
}

Individual* GeneticAlgorithm::init(KnapsackProblem& knapsackProblem){
    createPopulation(knapsackProblem.getNumberOfProducts());
    setSolutionsValue(knapsackProblem);
    for(int i = 0; i < iterations; i++){
        executeCross();
        executeMutation();
        setSolutionsValue(knapsackProblem);
    }
    return chooseAndPrintTheBestIndividual();
}