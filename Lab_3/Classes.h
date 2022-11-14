#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    friend istream& operator >>(istream&, Animal&);
    friend ostream& operator <<(ostream&, const Animal&);
    string type;
public:
    Animal();
    Animal(string);
    void SetType(string);
    string GetType();
    virtual void Show();
    ~Animal();
};

class AnimalGender : public virtual Animal
{
protected:
    friend istream& operator >>(istream&, AnimalGender&);
    friend ostream& operator <<(ostream&, const AnimalGender&);
    string gender;
public:
    AnimalGender();
    AnimalGender(string, string);
    void SetGender(string);
    string GetGender();
    virtual void Show() override;
    ~AnimalGender();
};

class AnimalName : public AnimalGender
{
protected:
    friend istream& operator >>(istream&, AnimalName&);
    friend ostream& operator <<(ostream&, const AnimalName&);
    string name;
public:
    AnimalName();
    AnimalName(string, string, string);
    void SetName(string);
    string GetName();
    virtual void Show() override;
    ~AnimalName();
};

class AnimalAge : public virtual Animal
{
protected:
    friend istream& operator >>(istream&, AnimalAge&);
    friend ostream& operator <<(ostream&, const AnimalAge&);
    int age;
public:
    AnimalAge();
    AnimalAge(string, int);
    void SetAge(int);
    int GetAge();
    virtual void Show() override;
    ~AnimalAge();
};

class AnimalColor : public AnimalAge
{
protected:
    friend istream& operator >>(istream&, AnimalColor&);
    friend ostream& operator <<(ostream&, const AnimalColor&);
    string color;
public:
    AnimalColor();
    AnimalColor(string, int, string);
    void SetColor(string);
    string GetColor();
    virtual void Show() override;
    ~AnimalColor();
};

class AnimalInfo : public AnimalColor, public AnimalName
{
private:
    friend istream& operator >>(istream&, AnimalInfo&);
    friend ostream& operator <<(ostream&, const AnimalInfo&);
    static int ID;
    int animalID = 0;
public:
    AnimalInfo();
    AnimalInfo(string, string, string, int, string);
    void Show() override;
    ~AnimalInfo();
};