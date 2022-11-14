#include "LengthException.h"


LengthException::LengthException(string _msg) : MyException(_msg) {}

LengthException::~LengthException() {}


void LengthException::Info()
{
    cout << "Exception: " << msg << endl;
}
