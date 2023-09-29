#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <iostream>
#include <vector>
#include "type.h"
#include "Layer.h"
#include "Matrix.h"

using namespace std;

class NeuralNetwork {
public:
    // neuron layers
    // weights
    // bias

    NeuralNetwork(vector<int> topology); // constructor
    void setCurrentInput(vector<Scalar> input);

    void feedForward();
    void backPropagation();

    void errorCalculation();
    

    void train();

    int topologySize;
    vector<int> topology; // num of neurons in each layer
    vector<Layer *> layers;
    vector<Matrix *> weightMatrices;
    vector<Scalar> input;


};

#endif

