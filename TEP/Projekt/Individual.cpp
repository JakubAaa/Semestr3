#include <random>
#include "Individual.h"
#include <iostream>

using namespace std;

Individual::Individual(vector<int> geneticType){
    genotype = geneticType;
    quality = 0;
}

Individual::~Individual() {
    genotype.clear();
}

void Individual::calculateAndSetQuality(double capacity, vector<double> weights, vector<double> values){
    double value = 0;
    double weight = 0;
    for(int i = 0; i < genotype.size(); i++){
        if(genotype[i] == 1){
            value += values[i];
            weight += weights[i];
        }
    }
    if(weight > capacity)
       quality = 0;
    else
        quality = value;
}

double Individual::getQuality(){
    return quality;
}

vector<Individual *> Individual::cross(Individual other) {
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<int> dis(1,genotype.size() - 1);

    int placeToSplit = dis(gen);
    std::vector<int> afterCross1;
    std::vector<int> afterCross2;
    for(int i = 0; i < genotype.size(); i++) {
        if (i < placeToSplit) {
            afterCross1.push_back(genotype[i]);
            afterCross2.push_back(other.genotype[i]);
        } else {
            afterCross1.push_back(other.genotype[i]);
            afterCross2.push_back(genotype[i]);
        }
    }
    vector<Individual *> temp;
    temp.push_back(new Individual(afterCross1));
    temp.push_back(new Individual(afterCross2));
    return temp;
}

vector<int> Individual::mutate(double mutationProbability){
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_int_distribution<int> dis(0.0,1.0);

    for(int i = 0; i < genotype.size(); i++){
        bool mutation = dis(gen) < mutationProbability;
        if(mutation)
            genotype[i] == 0 ? genotype[i] = 1 : genotype[i] = 0;
    }
    return genotype;
}

void Individual::print() {
    for (int i: genotype)
        std::cout << i << ' ';
    cout << endl;
}