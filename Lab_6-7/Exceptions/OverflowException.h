#ifndef LAB6_OVERFLOWEXCEPTION_H
#define LAB6_OVERFLOWEXCEPTION_H

#include "MyException.h"

class OverflowException : public MyException{

public:
    OverflowException(string = "Out of range");

    void Info() override;

    ~OverflowException();
};


#endif //LAB6_OVERFLOWEXCEPTION_H
