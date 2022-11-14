#ifndef figure_h
#define figure_h

#include <string>
#include <iostream>

using namespace std;


class Figure
{
protected:
    friend ostream& operator <<(ostream&, const Figure&);
    friend istream& operator >>(istream&, Figure&);
    static int ID;
    int figureID = 0;
public:
    Figure();
    Figure(Figure&);
    Figure& operator=(Figure&);

    void ShowID();
    virtual void Show();
    virtual double Square() = 0;

    virtual ~Figure() = 0;
};

#endif //figure_h

