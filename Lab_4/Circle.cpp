#include "Circle.h"

Circle::Circle() : Figure() {}
Circle::Circle(double _radius) : Figure(), radius(_radius) {}

Circle::Circle(Circle &other) : Figure(other)
{
    this->radius = other.radius;
}

Circle& Circle::operator=(Circle &other)
{
    dynamic_cast<Figure&>(*this) = other;
    this->radius = other.radius;
    return *this;
}

void Circle::Show()
{
    ShowID();
    cout << "Figure type: circle" << endl
        << "Radius: " << radius << endl;
}

double Circle::Square()
{
    return (3.14*radius*radius);
}

Circle::~Circle(){}



ostream& operator <<(ostream& out, const Circle& circle)
{
    out << dynamic_cast<const Figure&>(circle)
        << "Figure type: circle" << endl
        << "Radius: " << circle.radius << endl;
    return out;
}


istream& operator >>(istream& in, Circle& circle)
{
    in >> dynamic_cast<Figure&>(circle);
    cout << "Enter circle radius: ";
    in >> circle.radius;
    return in;
}

