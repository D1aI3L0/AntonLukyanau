#include "DoubleMatrix.h"


DoubleMatrix::DoubleMatrix(int n, int m)
{
    this->n = n;
    this->m = m;
    if(n == 0 && m == 0)
        this->matrix = nullptr;
    else
    {
        this->matrix = new double *[n];
        for (int i = 0; i < n; i++) {
            this->matrix[i] = new double[m];
            for (int j = 0; j < m; j++)
                this->matrix[i][j] = rand() % 100 - 50 + rand() % 100 / 100.0;
        }
    }
}


DoubleMatrix::DoubleMatrix(const DoubleMatrix& other)
{
    this->n = other.n;
    this->m = other.m;
    this->matrix = new double*[this->n];
    for(int i = 0; i < this->n; i++)
    {
        this->matrix[i] = new double[this->m];
        for (int j = 0; j < this->m; j++)
            this->matrix[i][j] = other.matrix[i][j];
    }
}


DoubleMatrix::operator double()
{
    double tmp = 0;
    if(matrix)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp += matrix[i][j];
    }
    return tmp;
}


DoubleMatrix::operator int()
{
    int tmp = 0;
    if(matrix)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp += matrix[i][j];
    }
    return tmp;
}


DoubleMatrix::operator MatrixSize()
{
    MatrixSize tmp;
    tmp.n = this->n;
    tmp.m = this->m;
    return tmp;
}


DoubleMatrix& DoubleMatrix::operator=(const DoubleMatrix& other)
{
    if(this->matrix)
    {
        for(int i = 0; i < this->n; i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
    }

    this->n = other.n;
    this->m = other.m;

    this->matrix = new double*[this->n];
    for(int i = 0; i < this->n; i++)
    {
        this->matrix[i] = new double[m];
        for(int j = 0; j < this->m; j++)
            this->matrix[i][j] = other.matrix[i][j];
    }
    return *this;
}


DoubleMatrix& DoubleMatrix::operator++ ()
{
    if(this->matrix)
    {
        for (int i = 0; i < this->n; i++)
            for (int j = 0; j < this->m; j++)
                ++this->matrix[i][j];
    }
    return *this;
}


DoubleMatrix& DoubleMatrix::operator++(int)
{
    DoubleMatrix& tmp = *this;
    ++*this;
    return tmp;
}


DoubleMatrix DoubleMatrix::operator+ (const DoubleMatrix& other)
{
    DoubleMatrix tmp;
    if(this->n == other.n && this->m == other.m && this->matrix)
    {
        tmp.n = this->n;
        tmp.m = this->m;
        tmp.matrix = new double*[tmp.n];
        for(int i = 0; i < tmp.n; i++)
        {
            tmp.matrix[i] = new double[tmp.m];
            for(int j = 0; j < tmp.m; j++)
                tmp.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    return tmp;
}


DoubleMatrix DoubleMatrix::operator- (const DoubleMatrix& other)
{
    DoubleMatrix tmp;
    if(this->n == other.n && this->m == other.m && this->matrix)
    {
        tmp.n = this->n;
        tmp.m = this->m;
        tmp.matrix = new double*[tmp.n];
        for(int i = 0; i < tmp.n; i++)
        {
            tmp.matrix[i] = new double[tmp.m];
            for(int j = 0; j < tmp.m; j++)
                tmp.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
        }
    }
    return tmp;
}


DoubleMatrix DoubleMatrix::operator+= (const DoubleMatrix& other)
{
    *this = *this + other;
    return *this;
}


DoubleMatrix DoubleMatrix::operator-= (const DoubleMatrix& other)
{
    *this = *this - other;
    return *this;
}


double* DoubleMatrix::operator[](int _n)
{
    double* tmp = new double[m];
    for(int i = 0; i < m; i++)
        tmp[i] = matrix[_n][i];
    return tmp;
}


double DoubleMatrix::operator()(int _n, int _m)
{
    if(matrix)
        return matrix[_n-1][_m-1];
    else
        return 0;
}


bool DoubleMatrix::operator == (DoubleMatrix& other)
{
    if(this->n == other.n && this->m == other.m)
    {
        for(int i = 0; i < this->n; i++)
            for(int j = 0; j < this->m; j++)
                if(this->matrix[i][j] != other.matrix[i][j])
                    return false;
        return true;
    }
    else
        return false;
}


bool DoubleMatrix::operator != (DoubleMatrix& other)
{
    if(this->n == other.n && this->m == other.m)
    {
        for(int i = 0; i < this->n; i++)
            for(int j = 0; j < this->m; j++)
                if(this->matrix[i][j] != other.matrix[i][j])
                    return true;
        return false;
    }
    else
        return true;
}


DoubleMatrix::~DoubleMatrix()
{
    if(matrix)
    {
        for (int i = 0; i < n; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
}