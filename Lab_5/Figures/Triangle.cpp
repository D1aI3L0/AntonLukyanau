#include "Triangle.h"

Triangle::Triangle() : Figure() {}
Triangle::Triangle(double _a, double _Ha) : a(_a), Ha(_Ha), Figure() {}

Triangle::Triangle(Triangle &other) : Figure(other)
{
    this->a = other.a;
    this->Ha = other.Ha;
}

Triangle &Triangle::operator=(Triangle &other)
{
    dynamic_cast<Figure&>(*this) = other;
    this->a = other.a;
    this->Ha = other.Ha;
    return *this;
}

void Triangle::Show()
{
    ShowID();
    cout << "Figure type: triangle" << endl
         << "a: " << a << endl
         << "Ha: " << Ha << endl;
}

double Triangle::Square()
{
    return (a*Ha/2);
}

Triangle::~Triangle(){}


ostream& operator <<(ostream& out, const Triangle& triangle)
{
    out << dynamic_cast<const Figure&>(triangle)
        << "Figure type: triangle" << endl
        << "a: " << triangle.a << endl
        << "Ha: " << triangle.Ha << endl;
    return out;
}


istream& operator >>(istream& in, Triangle& triangle)
{
    in >> dynamic_cast<Figure&>(triangle);
    cout << "Enter 'a' and 'Ha': ";
    in >> triangle.a >> triangle.Ha;
    return in;
}