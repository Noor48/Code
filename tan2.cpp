#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout ("tan2.dat");

    for(double x=-M_PI; x<=M_PI; x+=0.0001)
    {
        fout << x << "  " << tan(x) << endl;
    }

    return 0;
}