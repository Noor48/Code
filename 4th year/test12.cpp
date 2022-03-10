#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

ofstream fout1("q1.dat");
ofstream fout2("q2.dat");
double h=0.25;      // time increment

double f(double N, double lamda)        // function for slope
{
    int m=0;
        
    for(int i=1; i<=N; i++)
    {
        double x=(double)rand()/(double)RAND_MAX;
        if (x<0.25*lamda)
        {
            m++;
        }
    }

    return m;
}

int main()
{
    double t, N1=1000, N2=10000;

    srand(time(NULL));
    
    for (double t=0; t<=100 ; t=t+h)       // for comparison
    {
        fout1<< t<<"  "<< N1<<"  "<< N2<<"  "<< log(N1)<<"  "<< log(N2)<<"  "<< log(f(N2,0.05))<< endl;
        N1=N1-f(N1,0.05);
        N2=N2-f(N2,0.05);
    }

    double N3=10000, N4=10000;

    for (double t=0; t<=100 ; t=t+h)       // for different lamda
    {
        fout2<< t<<"  "<< log(N3)<<"  "<< log(N4)<< endl;
        N3=N3-f(N3,0.025);
        N4=N4-f(N4,0.05);
    }
    
    return 0;
}