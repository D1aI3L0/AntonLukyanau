#include "Input.h"


void Input::Int(int &data, string msg, char mode, int leftBorder, int rightBorder   )
{
    while(true)
    {
        try
        {
            cout << msg;
            cin >> data;

            if(data == INT_MAX || data == INT_MIN)
                throw OverflowException();

            if(mode == 'b')
                if (data < leftBorder || data > rightBorder)
                    throw OverflowException("Out of this range");

            if (mode == 'l')
                if (data < leftBorder)
                    throw OverflowException("Out of this range");

            if(mode == 'r')
                if(data > rightBorder)
                    throw OverflowException("Out of this range");

            break;
        }
        catch (MyException &ex)
        {
            ex.Info();
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
}