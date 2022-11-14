#ifndef LAB6_LENGTHEXCEPTION_H
#define LAB6_LENGTHEXCEPTION_H

#include "MyException.h"


class LengthException : public MyException{

public:
    LengthException(string = "Out of memory");

    void Info() override;

    ~LengthException();
};


#endif //LAB6_LENGTHEXCEPTION_H
