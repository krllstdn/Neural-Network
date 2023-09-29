#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include "Neuron.h"
#include "Matrix.h"
#include <vector>

using namespace std;

class Layer {
public:
    int size;
    vector<Neuron *> neurons;

    Layer(int size);
    void setValue(int i, Scalar val);

    Matrix *matrixifyVals();
    Matrix *matrixifyActivatedVals();
    Matrix *matrixifyDerivedVals();

    vector<double> getActivatedVals(); //??????

};


#endif 