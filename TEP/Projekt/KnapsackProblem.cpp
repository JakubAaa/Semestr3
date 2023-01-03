#include "KnapsackProblem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

KnapsackProblem::KnapsackProblem(double capacityOfKnapsack, const vector<double>& weights, const vector<double>& values) {
    if(capacityOfKnapsack < 0) {
       cout << "Number of capacity must be greater or equal 0!" << endl;
       return;
    }

    if(weights.size() != values.size()) {
        cout << "Tables of weights and values must contain the same number of items!" << endl;
        return;
    }

    capacity = capacityOfKnapsack;
    weightsTable = weights;
    valuesTable = values;
}

KnapsackProblem::KnapsackProblem(const string& filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    double capacityOfKnapsack;
    vector<double> weights;
    vector<double> values;

    string word;
    int i = 0;

    while (file >> word) {
        if(i == 1)
            capacityOfKnapsack = stod(word);
        if(i == 3)
            weights = convertStringTableToVector(word);
        if(i == 5)
            values = convertStringTableToVector(word);
        i++;
    }

    file.close();

    if(capacityOfKnapsack < 0) {
        cout << "Number of capacity must be greater or equal 0!" << endl;
        return;
    }

    if(weights.size() != values.size()) {
        cout << "Tables of weights and values must contain the same number of items!" << endl;
        return;
    }

    capacity = capacityOfKnapsack;
    weightsTable = weights;
    valuesTable = values;
}

KnapsackProblem::~KnapsackProblem() {
    weightsTable.clear();
    valuesTable.clear();
}

void KnapsackProblem::calculateValueOfSolution(Individual* individual){
    individual->calculateAndSetQuality(capacity, weightsTable, valuesTable);
}

int KnapsackProblem::getNumberOfProducts() {
    return weightsTable.size();
}

vector<double> KnapsackProblem::convertStringTableToVector(const string& stringToConvert) {
    vector<double> temp;
    vector<string> numbers;
    string token;
    istringstream token_stream(stringToConvert);

    while (getline(token_stream, token, ','))
        numbers.push_back(token);

    for(int i = 0; i < numbers.size(); i++)
        temp.push_back(stod(numbers[i]));

    return temp;
}