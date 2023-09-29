#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <math.h>
#include "type.h"

using namespace std;

class Neuron
{
public:
    Scalar value;
    Scalar activatedVal;
    Scalar derivedVal;

    Neuron(Scalar value);

    void setValue(Scalar value);
    void activate();
    void derive();

};

#endif