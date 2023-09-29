#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "type.h"

using namespace std;

class Matrix
{
public:
    int numRows;
    int numCols;
    vector< vector<Scalar> > values;

    Matrix(int numRows, int numCols, bool isRandom); 

    Matrix *transpose();
    Matrix *copy();

    void setValue(int r, int c, Scalar v) { this->values.at(r).at(c) = v; }
    Scalar getValue(int r, int c) { return this->values.at(r).at(c); }

    vector< vector<Scalar> > getValues() { return this->values; }

    void printToConsole();

    Matrix matrixMultiplication
    // int getNumRows() { return this->numRows; }
    // int getNumCols() { return this->numCols; }

private:
  Scalar generateRandomNumber();

  

};

#endif
