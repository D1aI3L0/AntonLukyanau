#include "Figure.h"

Figure::Figure() {}

Figure::Figure(Figure &other)
{
    this->figureID = other.figureID;
}

Figure& Figure::operator=(Figure &other)
{
    this->figureID = other.figureID;
    return *this;
}

void Figure::Show()
{
    cout << "Figure ID: " << figureID << endl;
}

void Figure::ShowID()
{
    cout << "Figure ID: " << figureID << endl;
}

Figure::~Figure() {}



ostream& operator <<(ostream& out, const Figure& figure)
{
    out << "Figure ID: " << figure.figureID << endl;
    return out;
}


istream& operator >>(istream& in, Figure& figure)
{
    figure.figureID = ++figure.ID;
    return in;
}