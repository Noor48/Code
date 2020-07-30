#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void f(double t, double omega, double theta, double dt)
{
    double g=9.8, l=1;
    ofstream fout ("euler2.dat");
    for(int i=0; i<=100; i++)
    {
        omega -= (g/l)*theta*dt;
        theta += omega*dt;
        t += dt;
        fout << t  << " " << theta << " " << omega << endl;
    }
}

int main()
{
    double t=0, theta =0, omega =1, dt = 0.1;
    f(t, omega, theta, dt);
    return 0;
}