#include "AllocException.h"


AllocException::AllocException(string _msg) : MyException(_msg) {}

AllocException::~AllocException() {}


void AllocException::Info()
{
    cout << "Exception: " << msg << endl;
}