#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "type.h"

class  Matrix{
    enum{DIM = 3};
    Scalar **data;
    void allocateMemory();
    void copyDataFrom(const
                      Matrix &src);
    void releaseMemory();
public:
    Matrix(Scalar diag = 0);
    Matrix(const Matrix &other);
    ~Matrix();
    Matrix& operator=(
            const Matrix &rhs
            );
    unsigned int getDim() const{
        return DIM;
    }
    Scalar& at(unsigned int i,
       unsigned int j);
    Scalar& operator()(unsigned int i,
                       unsigned int j);

//ukol
    Matrix operator-(Matrix &m);//rozdil matic
    Matrix operator-(); //opacna matice
    Scalar operator~(); //determinant, stopa
    //Matrix operator~();
    Matrix cofactor(int k, int p);

};

// ukol
Matrix operator*(Matrix &a, Matrix &b); //maticové násobení
Matrix operator*(Scalar a,  Matrix &n); //číslo * matice
Matrix operator*(Matrix &m, Scalar a); //matice * číslo
bool operator==(Matrix &a, Matrix &b); //rovnost matic
bool operator==(Matrix &a, Matrix &b); //nerovnost matic

std::ostream& operator<<(
            std::ostream &os,
            Matrix &m
        );
Matrix operator+(Matrix &a,
                 Matrix &b);


#endif // MATRIX_H
