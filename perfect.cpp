#include <iostream>
using namespace std;

int main()
{
    int n, sum=0;
    cout << "Enter your number: ";
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }

    if(2*n==sum)
    {
        cout << "perfect number." << endl;
    }

    else
    {
        cout << "Not perfect number." << endl;
    }

    return 0;
    
}