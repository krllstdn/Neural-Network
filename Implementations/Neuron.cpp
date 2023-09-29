#include "../Headers/Neuron.h"

void Neuron::setValue(Scalar value){
    this->value = value;
    activate();
    derive();
}

// we are using sigmoid function
void Neuron::activate(){
    this->activatedVal = (1 / (1 + exp(-this->value)));
}

void Neuron::derive(){
    this->derivedVal = (this->activatedVal * (1 - this->activatedVal));
}

Neuron::Neuron(Scalar value){
    setValue(value);
}