#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void f(double t, double omega, double theta, double dt)
{
    double g=9.8, l=1;
    ofstream fout ("euler2.dat");
    for(double i=0; i<=100; i+=dt)
    {
        fout << t << " " << theta << " " << omega << endl;
        omega -= (g/l)*theta*dt;
        theta += omega*dt;
        t += dt;
    }
}

int main()
{
    double t=0, dt=0.1, omega=1, theta=0;
    f(t, omega, theta, dt);

    return 0;
}