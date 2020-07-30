#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j=0; j<t; j++)
    {
    int n,a = 1;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        a += a*i;
    }

    cout << a;

    }
}
