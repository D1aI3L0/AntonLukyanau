#ifndef LAB6_MYEXCEPTION_H
#define LAB6_MYEXCEPTION_H

#include <iostream>

using namespace std;

class MyException{

protected:
    string msg = "Unknown exception";

public:
    MyException(string);

    virtual void Info() = 0;

    ~MyException();
};


#endif //LAB6_MYEXCEPTION_H
