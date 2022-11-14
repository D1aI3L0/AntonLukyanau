#ifndef circle_h
#define circle_h

#include "Figure.h"

class Circle : public Figure
{
private:
    friend ostream& operator <<(ostream&, const Circle&);
    friend istream& operator >>(istream&, Circle&);
    double radius;
public:
    Circle();
    Circle(double);
    Circle(Circle&);
    Circle& operator=(Circle&);

    void Show() override;

    double Square() override;

    ~Circle();
};

#endif //circle_h
