#include "../Headers/Layer.h"
#include "../Headers/Neuron.h"

Layer::Layer(int size){
    this->size = size;

    for(int i = 0; i < size; i++){
        Neuron *n = new Neuron(Scalar(0.000000000));
        this->neurons.push_back(n);
    }
}

void Layer::setValue(int i, Scalar val){
    this->neurons.at(i)->setValue(val);
}

// Makes matrix out of vector(c++ library)
Matrix *Layer::matrixifyVals(){
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for (int i = 0; i < this->neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->value);
    }

    return m;
}

Matrix *Layer::matrixifyActivatedVals(){
    Matrix *m = new Matrix(1, this->neurons.size(), false);

    for (int i = 0; i < this->neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->activatedVal);
    }

    return m;
}


Matrix *Layer::matrixifyDerivedVals(){
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for (int i = 0; i < this->neurons.size(); i++){
        m->setValue(0, i, this->neurons.at(i)->derivedVal);
    }

    return m;
}
