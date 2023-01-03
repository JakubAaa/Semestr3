#ifndef PROJEKT_INDIVIDUAL_H
#define PROJEKT_INDIVIDUAL_H
#include <vector>

using namespace std;

class Individual {
private:
    vector<int> genotype;
    double quality;
public:
    Individual(vector<int> geneticCode);
    ~Individual();

    void calculateAndSetQuality(double capacity, vector<double> weights, vector<double> values);
    double getQuality();
    vector<Individual *> cross(Individual other);
    vector<int> mutate(double mutationProbability);
    void print();
};


#endif
