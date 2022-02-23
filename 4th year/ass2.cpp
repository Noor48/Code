/*
A box is divided into two side with a barrier.There is N number of particles are held in the left side of the barrier of the box at beginning. 
Let a small hole is created in the the barrier and one particle can pass though the hole per unit time.

1:-  Write down a code and draw a graph to determint the time for the particles to be in equilibrium position, 
hince both left and right side have N/2 number of particle.

2:-  Solve dnl/dt= 1-(2*nl/N); and plot the gruph. Compair your result with problem 1
*/
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream fout("ass2.dat");
    double N=1000, n=N, nr=0, nl=N, x, y;
    srand(time(NULL));
    
    for(int i=0; i<=10000; i+=1)
    {
        x = (double)rand()/(double)RAND_MAX;
        y = n/N;
        if(x<=y)
        {
            n-=1;
        }
        else
        {
            n+=1;
        }

        fout << i << "  " << n  << "  "  << nl << endl; 

        nl +=1-(2*nl)/N;
    }

    return 0;
}