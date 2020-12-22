#include <iostream>
#include <string>
using namespace std;

class Innova 
{
public:
    static int price;
    static int getPrice()
    {
        return price;
    }
};

int Innova::price=20;

class Student
{
public:
    int roll;
    string name;
    static int addNo;
    Student(string n)
    {
        addNo++;
        roll=addNo;
        name = n;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
    }
};

int Student::addNo=0;
int main()
{
    Innova i1,i2, i3;
    cout << i1.price << endl;
    cout << i3.price << endl;
    cout << Innova::price << endl;

    Student s1("John");
    Student s2("Ravi");
    Student s3("Khan");

    s1.display();
    s2.display();
    s3.display();
    cout << "Number Admission: " << Student::addNo <<  endl;

    return 0;   
}