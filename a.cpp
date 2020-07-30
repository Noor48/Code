#include <iostream>
#include <cmath>
using namespace std;

double sd( double data[])
{
    double sum = 0, mean, s = 0;

    for(int i=0; i<10; i++)
    {
        sum+=data[i];
    }

    mean = sum/10;

    for(int i=0; i<10; i++)
    {
        s += pow(data[i] - mean, 2);
    }

    return sqrt(s/10);
}

int main()
{
    int n;
    double data[10];

    cout << "Enter data number: ";
    cin >> n;
    cout << "Enter data elements: ";

    for(int i=0; i<10; i++)
    {
        cin >> data[i];
    }

    cout << "standard deviation = " << sd(data);

    return 0;
}
