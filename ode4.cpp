#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void euler(double t, double theta, double omega, double dt)
{
    ofstream fout ("eulerc.dat");
    ofstream file ("eulerc.dat");

    for(int i=0; i<=100; i++)
    {
        double omegaOld = omega;
        omega -= (9.8/1)*theta*dt;
        theta += omegaOld*dt;
        t += dt;

        fout << t << "  " << theta << "  " << omega << endl;
    }

    for(int i=0; i<=100; i++)
    {
        omega -= (9.8/1)*theta*dt;
        theta += omega*dt;
        t += dt;

        file << t << "  " << theta << "  " << omega << endl;
    }
}

int main()
{
    double t=0, theta=0, omega=1, dt=0.1;

    euler(t,theta,omega,dt);

    return 0;
}