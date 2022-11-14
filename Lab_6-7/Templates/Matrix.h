#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include "../Input.h"
#include <fstream>
#include <iomanip>

using namespace std;

template<typename T>
class Matrix
{
private:
    template<typename T1> friend ostream& operator <<(ostream&, const Matrix<T1>&);
    template<typename T1> friend istream& operator >>(istream&, Matrix<T1>&);

    template<typename T1> friend ofstream& operator <<(ofstream&, const Matrix<T1>&);
    template<typename T1> friend ifstream& operator >>(ifstream&, Matrix<T1>&);
    template<typename T1> friend fstream& operator <<(fstream&, const Matrix<T1>&);
    template<typename T1> friend fstream& operator >>(fstream&, Matrix<T1>&);
    int n = 0, m = 0;
    T** matrix = NULL;
public:
    Matrix();
    Matrix(Matrix&);

    void FRead(fstream&);
    void FWrite(fstream&);



    void SortColumn(const int);
    void SortLine(const int);

    T LineSum(int);
    T ColumnSum(int);
    T Sum();

    T* operator[](int);
    T operator()(int, int);

    void SetElement(int, int, T);
    T GetElement(int, int);

    void Menu();

    ~Matrix();
};


template<typename T>
ostream& operator <<(ostream& out, const Matrix<T>& matrix)
{
    if(matrix.matrix)
    {
        for (int i = 0; i < matrix.n; i++)
        {
            for (int j = 0; j < matrix.m; j++)
                out << (matrix.matrix[i][j]) << '\t';
            out << endl;
        }
    }
    return out;
}

template<typename T>
istream& operator >>(istream& in, Matrix<T>& matrix)
{
    if(matrix.matrix)
    {
        for(int i = 0; i < matrix.n; i++)
            delete[] matrix.matrix[i];
        delete[] matrix.matrix;
    }

    cout << "Enter matrix sizes:\n";
    Input::Int(matrix.n, "Enter 'n': ", 'b', 1, 30000);
    Input::Int(matrix.m, "Enter 'm': ", 'b', 1, 30000);


    while(true)
    {
        try
        {
            matrix.matrix = new T*[matrix.n];

            if(!matrix.matrix)
                throw AllocException("Memory allocation error");

            break;
        }
        catch (MyException &ex)
        {
            ex.Info();
        }
    }

    for(int i = 0; i < matrix.n; i++)
        while(true)
        {
            try
            {
                matrix.matrix[i] = new T[matrix.n];

                if(!matrix.matrix[i])
                    throw AllocException("Memory allocation error");

                break;
            }
            catch (MyException &ex)
            {
                ex.Info();
            }
        }

    cout << "Enter matrix: " << endl;
    for(int i = 0; i < matrix.n; i++)
    {
        for(int j = 0; j < matrix.m; j++)
            in >> matrix.matrix[i][j];
    }
    return in;
}


template<typename T>
ofstream& operator <<(ofstream& fOut, const Matrix<T>& matrix)
{
    if(matrix.matrix)
    {
        fOut << matrix.n << endl << matrix.m << endl;
        for(int i = 0 ; i < matrix.n; i++)
        {
            for(int j = 0; j < matrix.m; j++)
            {
                fOut << setw(7) << matrix.matrix[i][j];
            }
            fOut << endl;
        }
        fOut << endl;
    }
    return fOut;
}


template<typename T>
ifstream& operator >>(ifstream& fIn, Matrix<T>& matrix)
{
    if(matrix.matrix)
    {
        for(int i = 0; i < matrix.n; i++)
            delete[] matrix.matrix[i];
        delete[] matrix.matrix;
    }

    fIn >> matrix.n;
    fIn >> matrix.m;


    while(true)
    {
        try
        {
            matrix.matrix = new T*[matrix.n];

            if(!matrix.matrix)
                throw AllocException("Memory allocation error");

            break;
        }
        catch (MyException &ex)
        {
            ex.Info();
        }
    }

    for(int i = 0; i < matrix.n; i++)
        while(true)
        {
            try
            {
                matrix.matrix[i] = new T[matrix.n];

                if(!matrix.matrix[i])
                    throw AllocException("Memory allocation error");

                break;
            }
            catch (MyException &ex)
            {
                ex.Info();
            }
        }


    for (int i = 0; i < matrix.n; i++)
    {
        for(int j = 0; j < matrix.m; j++)
        {
            fIn >> matrix.matrix[i][j];
        }
    }
    return fIn;
}


template<typename T>
fstream& operator <<(fstream& fOut, const Matrix<T>& matrix)
{
    if(matrix.matrix)
    {
        fOut << setw(5) << matrix.n  << setw(5) << matrix.m << endl;
        for(int i = 0 ; i < matrix.n; i++)
        {
            for(int j = 0; j < matrix.m; j++)
            {
                fOut << setw(7) << matrix.matrix[i][j];
            }
            fOut << endl;
        }
        fOut << endl;
    }
    return fOut;
}


template<typename T>
fstream& operator >>(fstream& fIn, Matrix<T>& matrix)
{
    if(matrix.matrix)
    {
        for(int i = 0; i < matrix.n; i++)
            delete[] matrix.matrix[i];
        delete[] matrix.matrix;
    }

    fIn >> matrix.n;
    fIn >> matrix.m;


    while(true)
    {
        try
        {
            matrix.matrix = new T*[matrix.n];

            if(!matrix.matrix)
                throw AllocException("Memory allocation error");

            break;
        }
        catch (MyException &ex)
        {
            ex.Info();
        }
    }

    for(int i = 0; i < matrix.n; i++)
        while(true)
        {
            try
            {
                matrix.matrix[i] = new T[matrix.n];

                if(!matrix.matrix[i])
                    throw AllocException("Memory allocation error");

                break;
            }
            catch (MyException &ex)
            {
                ex.Info();
            }
        }


    for (int i = 0; i < matrix.n; i++)
    {
        for(int j = 0; j < matrix.m; j++)
        {
            fIn >> matrix.matrix[i][j];
        }
    }
    return fIn;
}


template<typename T>
void Matrix<T>::FWrite(fstream& fOut)
{
    if(this->matrix)
    {
        fOut.write((char*)&(this->n), sizeof(int));
        fOut.write((char*)&(this->m), sizeof(int));
        for (int i = 0; i < !this->n; i++)
        {
            for (int j = 0; j < this->m; j++)
            {
                fOut.write((char*)&(this->matrix[i][j]), sizeof(T));
            }
        }
    }
}


template<typename T>
void Matrix<T>::FRead(fstream &fIn)
{
    if(this->matrix)
    {
        for(int i = 0; i < this->n; i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
    }

    fIn.read((char*)&(this->n), sizeof(int));
    fIn.read((char*)&(this->m), sizeof(int));
    while(true)
    {
        try
        {
            this->matrix = new T*[this->n];

            if(!this->matrix)
                throw AllocException("Memory allocation error");

            break;
        }
        catch (MyException &ex)
        {
            ex.Info();
        }
    }

    for(int i = 0; i < this->n; i++)
        while(true)
        {
            try
            {
                this->matrix[i] = new T[this->m];

                if(!this->matrix[i])
                    throw AllocException("Memory allocation error");

                break;
            }
            catch (MyException &ex)
            {
                ex.Info();
            }
        }


    for (int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->m; j++)
        {
            fIn.read((char*)&(this->matrix[i][j]), sizeof(T));
        }
    }
}


template<typename T>
Matrix<T>::Matrix() {}

template<typename T>
Matrix<T>::Matrix(Matrix<T>& other)
{
    if(this->matrix)
    {
        for(int i = 0 ; i < this->n; i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
    }

    this->n = other.n;
    this->m = other.m;
    this->matrix = new T*[this->n];
    for(int i = 0; i < this->n; i++)
    {
        this->matrix[i] = new T[this->m];
        for(int j = 0; j < this->m; j++)
            this->matrix[i][j] = other.matrix[i][j];
    }
}


template<typename T>
void Matrix<T>::SortColumn(const int columnNumber)
{
    if(columnNumber <= this->m && matrix)
    {
        int pos;
        for(int i = 0; i < this->n; i++)
        {
            pos = i;
            for(int j = i+1; j < this->n; j++)
            {
                if(matrix[pos][columnNumber-1] > matrix[j][columnNumber-1])
                    pos = j;
            }
            if(pos != i)
            {
                T tmp = matrix[i][columnNumber-1];
                matrix[i][columnNumber-1] = matrix[pos][columnNumber-1];
                matrix[pos][columnNumber-1] = tmp;
            }
        }
    }
}

template<typename T>
void Matrix<T>::SortLine(const int lineNumber)
{
    if(lineNumber <= this->n && matrix)
    {
        int pos;
        for(int i = 0; i < this->m; i++)
        {
            pos = i;
            for(int j = i+1; j < this->m; j++)
            {
                if(matrix[lineNumber-1][pos] > matrix[lineNumber-1][j])
                    pos = j;
            }
            if(pos != i)
            {
                T tmp;
                tmp = matrix[lineNumber-1][i];
                matrix[lineNumber-1][i] = matrix[lineNumber-1][pos];
                matrix[lineNumber-1][pos] = tmp;
            }
        }
    }
}


template<typename T>
T Matrix<T>::LineSum(int lineNumber)
{
    T sum = 0;

    if(lineNumber <= this->n)
    {
        for(int j = 0; j < m; j++)
            sum += matrix[lineNumber][j];
    }

    return sum;
}

template<typename T>
T Matrix<T>::ColumnSum(int columnNumber)
{
    T sum = 0;

    if(columnNumber <= this->m)
    {
        for(int i = 0; i < n; i++)
        sum += matrix[i][columnNumber];
    }

    return sum;
}

template<typename T>
T Matrix<T>::Sum()
{
    T sum = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            sum += matrix[i][j];
    return sum;
}


template<typename T>
T* Matrix<T>::operator[](int lineNumber)
{
    if(!matrix)
    {
        cout << "This matrix is empty!" << endl;
        return NULL;
    }

    T* res = new T[n];
    for(int i = 0; i < m; i++)
        res[i] = matrix[lineNumber][i];
    return res;
}

template<typename T>
T Matrix<T>::operator()(int lineNumber, int columnNumber)
{
    if(!matrix)
    {
        cout << "This matrix is empty!" << endl;
        return 0;
    }

    return matrix[lineNumber][columnNumber];
}


template<typename T>
void Matrix<T>::SetElement(int lineNumber, int columnNumber, T element)
{
    if(!matrix)
    {
        cout << "This matrix is empty!" << endl;
        return;
    }

    if(lineNumber <= n && columnNumber <= m)
        matrix[lineNumber-1][columnNumber-1] = element;
}

template<typename T>
T Matrix<T>::GetElement(int lineNumber, int columnNumber)
{
    if(!matrix)
    {
        cout << "This matrix is empty!" << endl;
        return 0;
    }

    return matrix[lineNumber-1][columnNumber-1];
}


template<typename T>
void Matrix<T>::Menu()
{
    if(!this->m)
        cin >> *this;
    int rep;
    do
    {
        int num;

        cout << "\nMatrix:\n" << *this;

        Input::Int(num, "\nWhat do you what do to?\n1. Sort column\n2. Sort line\n3. Get element\n4. Change element\n5. Show matrix\n6. Nothing\n", 'b', 1, 6);

        switch (num)
        {
            case 1:
            {
                int columnNumber;
                Input::Int(columnNumber, "\nEnter number of column you want to sort: ", 'b', 1, this->m);

                SortColumn(columnNumber);
                cout << "\nMatrix:\n" << *this;
                break;
            }

            case 2:
            {
                int lineNumber;
                Input::Int(lineNumber, "\nEnter number of line you want to sort: ", 'b', 1, this->n);

                SortLine(lineNumber);
                cout << "\nMatrix:\n" << *this;
                break;
            }

            case 3:
            {
                int _n, _m;
                cout << "\nEnter coordinates of the element you want to get: ";
                Input::Int(_n, "\nEnter line number: ", 'b', 1, this->n);
                Input::Int(_m, "\nEnter column number: ", 'b', 1, this->m);

                cout << "\nElement you search for: " << GetElement(_n, _m);
                break;
            }

            case 4:
            {

                int _n, _m;
                T newElement;
                cout << "\nEnter coordinates of the element you want to change: ";
                Input::Int(_n, "\nEnter line number: ", 'b', 1, this->n);
                Input::Int(_m, "\nEnter column number: ", 'b', 1, this->m);

                Input::Int(newElement, "\nEnter new element: ");
                SetElement(_n, _m, newElement);
                cout << "\nMatrix:\n" << *this;
                break;
            }

            case 5:
            {
                cout << "\nMatrix:\n" << *this;
                break;
            }

            case 6:
            {
                return;
            }

            default:
                break;
        }

        Input::Int(rep, "\nDo you want to do something else?\n1. Yes\n2. No\n", 'b', 1, 2);
    } while (rep == 1);
}


template<typename T>
Matrix<T>::~Matrix() {}


#endif //LAB5_MATRIX_H
