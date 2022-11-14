#include "Figures/Figures.h"

int Figure::ID = 0;

int main()
{
    Figure* figure;

    Circle* circle = new Circle;
    cin >> *circle;
    figure = circle;
    figure->Show();
    cout << endl;

    Triangle* triangle = new Triangle;
    cin >> *triangle;
    figure = triangle;
    figure->Show();
    cout << endl;

    RightTriangle* rightTriangle = new RightTriangle;
    cin >> *rightTriangle;
    figure = rightTriangle;
    figure->Show();
}
