#ifndef right_triangle_h
#define right_triangle_h

#include "Triangle.h"

class RightTriangle : public Triangle
{
private:
    friend ostream& operator <<(ostream&, const RightTriangle&);
    friend istream& operator >>(istream&, RightTriangle&);
    double a, b;
public:
    RightTriangle();
    RightTriangle(double, double);
    RightTriangle(RightTriangle&);
    RightTriangle& operator=(RightTriangle&);

    void Show() override;

    double Square() override;

    ~RightTriangle();
};

#endif //right_triangle_h