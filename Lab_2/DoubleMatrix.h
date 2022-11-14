#include "MatrixSize.h"

class DoubleMatrix
{
private:
    friend ostream& operator << (ostream &out, const DoubleMatrix&);
    friend istream& operator >> (istream &input, DoubleMatrix&);
    friend DoubleMatrix& operator--(DoubleMatrix&);
    friend DoubleMatrix& operator--(DoubleMatrix&, int);
    int n;
    int m;
    double** matrix;
public:
    DoubleMatrix(int _n = 0, int _m = 0);
    DoubleMatrix(const DoubleMatrix&);
    operator double();
    operator int();
    operator MatrixSize();
    DoubleMatrix& operator=(const DoubleMatrix&);
    DoubleMatrix& operator++();
    DoubleMatrix& operator++(int);
    DoubleMatrix operator+(const DoubleMatrix&);
    DoubleMatrix operator-(const DoubleMatrix&);
    DoubleMatrix operator+=(const DoubleMatrix&);
    DoubleMatrix operator-=(const DoubleMatrix&);
    double* operator[](int);
    double operator()(int, int);
    bool operator==(DoubleMatrix&);
    bool operator!=(DoubleMatrix&);
    ~DoubleMatrix();
};
