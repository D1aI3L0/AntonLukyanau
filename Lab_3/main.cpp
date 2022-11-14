#include "Classes.h"

int AnimalInfo::ID = 0;

int main()
{
    AnimalInfo a;
    cin >> a;
    cout << "Animal a:" << endl << a;
    AnimalInfo b("Dog", "Female", "Bulka", 3, "Black");
    cout << "Animal b: " << endl;
    b.Show();
    cout << endl
        << "B type: " << b.GetType() << endl
        << "B color: " << b.GetColor() << endl;
}