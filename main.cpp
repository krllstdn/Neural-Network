#include <iostream>
#include <vector>
#include "Headers/Neuron.h"
#include "Headers/NeuralNetwork.h"
#include "Headers/type.h"


using namespace std;

int main (){
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    vector <Scalar> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    NeuralNetwork *nn = new NeuralNetwork(topology);
    nn->setCurrentInput(input);

    return 0;
}

