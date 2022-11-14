#include "RightTriangle.h"

RightTriangle::RightTriangle() : Triangle() {}
RightTriangle::RightTriangle(double _a, double _b) : Triangle(), a(_a), b(_b) {}

RightTriangle::RightTriangle(RightTriangle &other) : Triangle(other)
{
    this->a = other.a;
    this->b = other.b;
}

RightTriangle &RightTriangle::operator=(RightTriangle &other)
{
    dynamic_cast<Figure&>(*this) = other;
    this->a = other.a;
    this->b = other.b;
    return *this;
}

void RightTriangle::Show()
{
    ShowID();
    cout << "Figure type: right triangle" << endl
        << "a: " << a << endl << "b: " << b << endl
        << "Square: " << this->Square() << endl;
}

double RightTriangle::Square()
{
    return (a*b/2);
}

RightTriangle::~RightTriangle() {}


ostream& operator <<(ostream& out, const RightTriangle& rightTriangle)
{
    out << dynamic_cast<const Figure&>(rightTriangle)
        << "Figure type: right triangle" << endl
        << "a: " << rightTriangle.a << endl
        << "b: " << rightTriangle.b << endl;
    return out;
}


istream& operator >>(istream& in, RightTriangle& rightTriangle)
{
    in >> dynamic_cast<Figure&>(rightTriangle);
    cout << "Enter 'a' and 'b': ";
    in >> rightTriangle.a >> rightTriangle.b;
    return in;
}