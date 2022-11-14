#include "Classes.h"

istream& operator >>(istream& input, Animal& animal)
{
    cout << "Enter animal type" << endl;
    input >> animal.type;
    return input;
}


ostream& operator <<(ostream& out, const Animal& animal)
{
    out << "Animal type: " << animal.type << endl;
    return out;
}


istream& operator >>(istream& input, AnimalGender& animalGender)
{
    cout << "Enter animal type" << endl;
    input >> animalGender.type;
    cout << "Enter animal gender" << endl;
    input >> animalGender.gender;
    return input;
}


ostream& operator <<(ostream& out, const AnimalGender& animalGender)
{
    out << "Animal type: " << animalGender.type << endl
    << "Animal gender: " << animalGender.gender;
    return out;
}


istream& operator >>(istream& input, AnimalName& animalName)
{
    cout << "Enter animal type" << endl;
    input >> animalName.type;
    cout << "Enter animal gender" << endl;
    input >> animalName.gender;
    cout << "Enter animal name" << endl;
    input >> animalName.name;
    return input;
}


ostream& operator <<(ostream& out, const AnimalName& animalName)
{
    out << "Animal type: " << animalName.type << endl
    << "Animal gender: " << animalName.gender << endl
    << "Animal name: " << animalName.name << endl;
    return out;
}


istream& operator >>(istream& input, AnimalAge& animalAge)
{
    cout << "Enter animal type" << endl;
    input >> animalAge.type;
    cout << "Enter animal age" << endl;
    input >> animalAge.age;
    return input;
}


ostream& operator <<(ostream& out, const AnimalAge& animalAge)
{
    out << "Animal type: " << animalAge.type << endl
    << "Animal age: " << animalAge.age << endl;
    return out;
}


istream& operator >>(istream& input, AnimalColor& animalColor)
{
    cout << "Enter animal type" << endl;
    input >> animalColor.type;
    cout << "Enter animal age" << endl;
    input >> animalColor.age;
    cout << "Enter animal  color" << endl;
    input >> animalColor.color;
    return input;
}


ostream& operator <<(ostream& out, const AnimalColor& animalColor)
{
    out << "Animal type: " << animalColor.type << endl
    << "Animal age: " << animalColor.age << endl
    << "Animal color: " << animalColor.color << endl;
    return out;
}


istream& operator >>(istream& input, AnimalInfo& animalInfo)
{
    cout << "Enter animal type" << endl;
    input >> animalInfo.type;
    cout << "Enter animal gender" << endl;
    input >> animalInfo.gender;
    cout << "Enter animal name" << endl;
    input >> animalInfo.name;
    cout << "Enter animal age" << endl;
    input >> animalInfo.age;
    cout << "Enter animal color" << endl;
    input >> animalInfo.color;
    return input;
}


ostream& operator <<(ostream& out, const AnimalInfo& animalInfo)
{
    out << "Animal ID: " << animalInfo.animalID << endl
        << "Animal type: " << animalInfo.type << endl
        << "Animal gender: " << animalInfo.gender << endl
        << "Animal name: " << animalInfo.name << endl
        << "Animal age: " << animalInfo.age << endl
        << "Animal color: " << animalInfo.color << endl;
    return out;
}