#include "../Headers/NeuralNetwork.h"
#include "../Headers/Layer.h"

NeuralNetwork::NeuralNetwork(vector<int> topology)
{
    this->topology = topology;
    this->topologySize = topology.size();

    // initializing layers
    for(int i = 0; i < topologySize; i++ ){
        Layer *l = new Layer(topology.at(i));
        this->layers.push_back(l);
    }

    // initializing weights
    for(int i =0; i < topologySize - 1; i++ ){
        Matrix *m = new Matrix(topology.at(i), topology.at(i+1), true);
        this->weightMatrices.push_back(m);
    }
}

void NeuralNetwork::setCurrentInput(vector<Scalar> input){
    this->input = input;
    // this->
}