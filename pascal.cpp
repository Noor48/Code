#include <iostream>
#include <cmath>
using namespace std;

double fact(int n)
{
    if(n<=1)
    {
        return 1; 
    }

    else
    {
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    cout << "Enter row number: ";
    cin >> n;

    for(int i=0; i<=n; i++)
    {
        for (int k=0; k<n-i; k++)
        {
            cout << " ";
        }

        for(int j=0; j<=i; j++)
        {   
            cout << (fact(i)/(fact(j)*fact(i-j))) << " "; // i represnts n which is power number. Calculating combination do rest of the job.
        }

        cout << endl;
    }


    return 0;
}