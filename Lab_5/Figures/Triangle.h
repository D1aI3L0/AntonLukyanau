#ifndef triangle_h
#define triangle_h

#include "Figure.h"

class Triangle : public Figure
{
    friend ostream& operator <<(ostream&, const Triangle&);
    friend istream& operator >>(istream&, Triangle&);
private:
    double a = 0, Ha = 0;
public:
    Triangle();
    Triangle(double, double);
    Triangle(Triangle&);
    Triangle& operator=(Triangle&);

    void Show() override;

    double Square() override;

    ~Triangle();
};

#endif //triangle_h