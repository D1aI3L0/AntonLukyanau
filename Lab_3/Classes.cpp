#include "Classes.h"

Animal::Animal(){}

Animal::Animal(string type) : type(type){}

void Animal::SetType(string _type){ this->type = _type; }

string Animal::GetType(){ return this->type; }

void Animal::Show()
{
    cout << "Animal type: " << type << endl;
}

Animal::~Animal(){}


AnimalGender::AnimalGender() : Animal(){}

AnimalGender::AnimalGender(string type, string gender) : Animal(type), gender(gender){}

void AnimalGender::SetGender(string _gender){ this->gender = _gender; }

string AnimalGender::GetGender(){ return this->gender; }

void AnimalGender::Show()
{
    cout << "Animal type: " << type << endl
    << "Animal gender: " << gender;
}

AnimalGender::~AnimalGender(){}


AnimalName::AnimalName() : AnimalGender(){}

AnimalName::AnimalName(string type, string gender, string name) : AnimalGender(type, gender), name(name), Animal(type){}

void AnimalName::SetName(string _name) { this->name = _name; }

string AnimalName::GetName() { return this->name; }

void AnimalName::Show()
{
    cout << "Animal type: " << type << endl
    << "Animal gender: " << gender << endl
    << "Animal name: " << name << endl;
}

AnimalName::~AnimalName(){}


AnimalAge::AnimalAge() : Animal(){}

AnimalAge::AnimalAge(string type, int age) : Animal(type), age(age){}

void AnimalAge::SetAge(int _age) { this->age = _age; }

int AnimalAge::GetAge() { return  this->age; }

void AnimalAge::Show()
{
    cout << "Animal type: " << type << endl
    << "Animal age: " << age << endl;
}

AnimalAge::~AnimalAge(){}


AnimalColor::AnimalColor() : AnimalAge(){}

AnimalColor::AnimalColor(string type, int age, string color) :
AnimalAge(type, age), color(color), Animal(type){}

void AnimalColor::SetColor(string _color) { this->color = _color; }

string AnimalColor::GetColor() { return this->color; }

void AnimalColor::Show()
{
    cout << "Animal type: " << type << endl
    << "Animal age: " << age << endl
    << "Animal color: " << color << endl;
}

AnimalColor::~AnimalColor(){}


AnimalInfo::AnimalInfo() : AnimalColor(), AnimalName(), Animal()
{
    animalID = ++ID;
}

AnimalInfo::AnimalInfo(string type, string gender, string name, int age, string Color) :
AnimalColor(type, age, Color), AnimalName(type, gender, name), Animal(type)
{
    if(!animalID)
        animalID = ++ID;
}

void AnimalInfo::Show()
{
    cout << endl
            << "Animal ID: " << animalID << endl
            << "Animal type: " << type << endl
            << "Animal gender: " << gender << endl
            << "Animal name: " << name << endl
            << "Animal age: " << age << endl
            << "Animal color: " << color << endl;
}

AnimalInfo::~AnimalInfo(){}