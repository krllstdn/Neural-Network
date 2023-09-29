#include "matrix.h"
#include <math.h>
#include <iomanip>

using namespace std;

Matrix::Matrix(Scalar diag){
    allocateMemory();
    for(unsigned int i = 0; i < DIM; i++){
        for(unsigned int j = 0; j < DIM; j++){
            data[i][j] =
                    (i == j ? diag : 0);
        }
    }
}

void Matrix::allocateMemory(){
    data = new Scalar*[DIM];
    for(unsigned int i = 0; i < DIM; i++){
        data[i] = new Scalar[DIM];
    }
}

void Matrix::copyDataFrom(const Matrix &src){
    for(unsigned int i = 0; i < DIM; i++){
        for(unsigned int j = 0; j < DIM; j++){
            this->data[i][j] = src.data[i][j];
            //this->at(i, j) = src.at(i, j);
        }
    }
}

Matrix::Matrix(const Matrix &other){
    this->allocateMemory();
    this->copyDataFrom(other);
}

void Matrix::releaseMemory(){
    if(data){
        for(unsigned int i = 0; i < DIM; i++){
            delete [] data[i];
        }
        delete [] data;
        data = nullptr;
    }
}

Matrix::~Matrix(){
    releaseMemory();
}

Scalar& Matrix::at(unsigned int i,
                   unsigned int j){
    //i--;
    //j--;
    if(i >= DIM || j >= DIM){
        //vyvolat vyjimku
    }
    return this->data[i][j];
    //return this->data[i*DIM+j];
}

Scalar& Matrix::operator()(unsigned int i,
                           unsigned int j){
    return this->at(i, j);
}

//#include <iomanip>
ostream& operator<<(ostream &os, Matrix &m){
    unsigned int N = m.getDim();
    for(unsigned int i = 0; i < N; i++){
        for(unsigned int j = 0; j < N; j++){
            os << setfill(' ');
            os << setw(6) <<
               setprecision(3)
               << m(i, j);
            //os << m.operator()(i, j);
            //os << m.at(i, j);
        }
        os << '\n';
    }
    return os;
}

Matrix operator+(Matrix &a, Matrix &b){
    Matrix c(0);
    unsigned int N = a.getDim();
    for(unsigned int i = 0; i < N; i++){
        for(unsigned int j = 0; j < N; j++){
            c(i, j) = a(i, j) + b(i, j);
        }
    }
    return c;
}

Matrix& Matrix::operator=(const Matrix &rhs){
    if(this == &rhs){
        return *this;
    }
    this->copyDataFrom(rhs);
    return *this;
}

// matrix substraction method
Matrix Matrix::operator-(Matrix &m){
    Matrix c(0);
    unsigned int N = getDim();
    for(unsigned int i = 0; i < N; i++){
        for(unsigned int j = 0; j < N; j++){
            c(i, j) = this->operator()(i, j) - m(i, j);
        }
    }
    return c;
}
// matrix inverse method
Matrix Matrix::operator-(){
    Matrix c(0);
    unsigned int N = getDim();
    for (unsigned int i = 0; i < N; i++){
        for(unsigned int i = 0; i < N; i++){

        }
    }

}

// determinant
// Number Matrix::operator~(){
//     int det = 0;
//     Matrix submatrix;
//     unsigned int N = getDim();
//     if (N == 2)
//     return ( (this->operator()(0,0) * this->operator()(1,1) ) 
//         - (this->operator()(1,0) * this->operator()(0,1)) );
//     else {
//         for (int x = 0; x < N; x++) {
//             int subi = 0;
//             for (int i = 1; i < N; i++) {
//                 int subj = 0;
//                 for (int j = 0; j < N; j++) {
//                     if (j == x)
//                         continue;
//                     submatrix(subi,subj) = this->operator()(i,j);
//                     subj++;
//                 }
//                 subi++;
//             }
//             det = det + (pow(-1, x) * this->operator()(0,x) * this->operator~( submatrix, N - 1 ));
//         }
//     }
//     return det;
// }

Matrix operator*(Matrix &a, Matrix &b) {
    unsigned int aN = a.getDim();
    unsigned int bN = b.getDim();
    Matrix c(0);
    if (aN == bN){
        int N = a.getDim();
        for(int row_m1 = 0; row_m1 < N; row_m1++){
            for(int col_m2 = 0; col_m2 < N; col_m2++){              
                for(int i = 0; i < N; i++){
                    c(row_m1, col_m2)+= a(row_m1, i) * b(i,col_m2);
                }
            }
        }
    }
    return c;
}


