#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,r,sum=0,m;
    cout << "Enter number: ";
    cin >> n;
    m=n;

    while(n>0)
    {
        r=n%10;
        n=n/10;
        sum += pow(r,3);
    }

    if(m==sum)
    {
        cout << "It is a Amstrong number." << endl;
    }

    else
    {
        cout << "Not a Amstrong number," << endl;
    }

    return 0;
}