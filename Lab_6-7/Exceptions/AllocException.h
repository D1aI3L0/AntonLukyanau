#ifndef LAB6_ALLOCEXCEPTION_H
#define LAB6_ALLOCEXCEPTION_H

#include "MyException.h"

class AllocException : public MyException {

public:
    AllocException(string = "Memory error");

    void Info() override;

    ~AllocException();
};


#endif //LAB6_ALLOCEXCEPTION_H
