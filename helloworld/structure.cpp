#include <iostream>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
    double height;
    double weight;

};

int main()
{
    Person peter = {"Peter Jone", 18, 180.5, 70.5};
    cout << "Name: " << peter.name << endl;
    cout << "Age: " << peter.age << endl;
    cout << "Height: " << peter.height << endl;
    cout << "Weight: " << peter.weight << endl;

    return 0;
}
