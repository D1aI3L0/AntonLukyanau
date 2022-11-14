#include "RightTriangle.h"
#include "Circle.h"
#include "Queue.h"

int Figure::ID = 0;

int main()
{
    Queue<Circle> c;
    Circle c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    c.pushPos(c1, 4);
    c.pushPos(c2,1);
    c.pushPos(c3, 2);
    c.pushPos(c4, 1);
    return 0;
}