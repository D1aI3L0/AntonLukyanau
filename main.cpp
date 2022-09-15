#include <iostream>
#include <string>

using namespace std;

class Dean;

class Student
{
private:
    friend void Print(Student);
    friend class Dean;
    static int ID;
    int studentID;
    string name;
    double rate;
public:
    Student(){}


    Student(const string _name)
    {
        studentID = ++ID;
        name = _name;
        rate = 0;
    }


    ~Student(){}
};
int Student::ID = 0;


class Dean
{
public:
    void SetRating(Student& _student)
    {
        do
        {
            cin >> _student.rate;
        }while(_student.rate < 0 || _student.rate > 10);
    }
};


void Print(const Student _student)
{
    cout << _student.studentID << '\t' << _student.name << "\t\t" << _student.rate << endl;
}


int main()
{
    Student firstStudent, secondStudent;
    Dean dean;
    string name;

    cout << "Enter name of student number 1\n";
    cin >> name;
    firstStudent = Student(name);
    cout << "Enter name of student number 2\n";
    cin >> name;
    secondStudent = Student(name);

    cout << "Befored ranking" << endl;
    Print(firstStudent);
    Print(secondStudent);
    cout << endl;

    cout << "Enter rating of student number 1 (from 0.0 to 10.0)" << endl;
    dean.SetRating(firstStudent);
    cout << "Enter rating of student number 2 (from 0.0 to 10.0)" << endl;
    dean.SetRating(secondStudent);

    cout << "After ranking" << endl;
    Print(firstStudent);
    Print(secondStudent);
    cout << endl;

    int count;
    cout << "Enter count of students" << endl;
    cin >> count;

    Student *students = new Student[count];

    cout << endl;
    for(int i = 0; i < count; i++)
    {
        cout << "Enter name of student number " << i+1 << endl;
        cin >> name;
        *(students+i) = Student(name);
    }

    cout << endl << "Before ranking" << endl;
    for(int i = 0; i < count; i++)
        Print(*(students+i));

    cout << endl;
    for(int i = 0; i < count; i++)
    {
        cout << "Enter rating of student number " << i+1 << "(from 0.0 to 10.0)" << endl;
        dean.SetRating(*(students+i));
    }

    cout << endl << "After ranking" << endl;
    for(int i = 0; i < count; i++)
        Print(*(students+i));

    delete[] students;
}
