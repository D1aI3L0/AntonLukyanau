#include "DoubleMatrix.h"


ostream& operator << (ostream& out, const DoubleMatrix& doubleMatrix)
{
    out << endl;
    if(doubleMatrix.matrix)
    {
        for (int i = 0; i < doubleMatrix.n; i++)
        {
            for (int j = 0; j < doubleMatrix.m; j++)
                out << doubleMatrix.matrix[i][j] << '\t';
            out << endl;
        }
    }
    return out;
}


istream& operator >> (istream& input, DoubleMatrix& doubleMatrix)
{
    if(doubleMatrix.matrix)
    {
        for(int i = 0; i < doubleMatrix.n; i++)
            delete[] doubleMatrix.matrix[i];
        delete[] doubleMatrix.matrix;
    }

    input >> doubleMatrix.n >> doubleMatrix.m;

    doubleMatrix.matrix = new double*[doubleMatrix.n];
    for(int i = 0; i < doubleMatrix.n; i++)
        doubleMatrix.matrix[i] = new double[doubleMatrix.m];

    for(int i = 0; i < doubleMatrix.n; i++)
    {
        for(int j = 0; j < doubleMatrix.m; j++)
            input >>  doubleMatrix.matrix[i][j];
    }
    return input;
}


DoubleMatrix& operator--(DoubleMatrix& doubleMatrix)
{
    for(int i = 0; i < doubleMatrix.n; i++)
        for(int j = 0; j < doubleMatrix.m; j++)
            --doubleMatrix.matrix[i][j];
    return doubleMatrix;
}


DoubleMatrix& operator--(DoubleMatrix& doubleMatrix, int)
{
    DoubleMatrix& tmp = doubleMatrix;
    --doubleMatrix;
    return tmp;
}