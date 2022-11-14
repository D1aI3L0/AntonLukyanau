#include "OverflowException.h"


OverflowException::OverflowException(string _msg) : MyException(_msg) {}

OverflowException::~OverflowException() {}


void OverflowException::Info()
{
    cout << "Exception: " << msg << endl;
}